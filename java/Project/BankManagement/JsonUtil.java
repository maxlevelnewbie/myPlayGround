import java.util.*;

/**
 * A small, dependency-free JSON parser + writer.
 * Supports: objects (LinkedHashMap<String,Object>), arrays (ArrayList<Object>),
 * strings, numbers (Double), booleans, and null.
 * This is intentionally minimal -- just enough to persist our bank data
 * without needing to download an external JSON library.
 */
public class JsonUtil {

    // ---------- PARSING ----------

    public static Object parse(String text) {
        Parser p = new Parser(text);
        p.skipWhitespace();
        Object result = p.parseValue();
        p.skipWhitespace();
        return result;
    }

    private static class Parser {
        private final String s;
        private int pos = 0;

        Parser(String s) { this.s = s; }

        void skipWhitespace() {
            while (pos < s.length() && Character.isWhitespace(s.charAt(pos))) pos++;
        }

        char peek() { return s.charAt(pos); }

        Object parseValue() {
            skipWhitespace();
            char c = peek();
            switch (c) {
                case '{': return parseObject();
                case '[': return parseArray();
                case '"': return parseString();
                case 't': pos += 4; return Boolean.TRUE;
                case 'f': pos += 5; return Boolean.FALSE;
                case 'n': pos += 4; return null;
                default: return parseNumber();
            }
        }

        Map<String, Object> parseObject() {
            Map<String, Object> map = new LinkedHashMap<>();
            pos++; // consume '{'
            skipWhitespace();
            if (peek() == '}') { pos++; return map; }
            while (true) {
                skipWhitespace();
                String key = parseString();
                skipWhitespace();
                pos++; // consume ':'
                Object value = parseValue();
                map.put(key, value);
                skipWhitespace();
                char c = peek();
                if (c == ',') { pos++; continue; }
                if (c == '}') { pos++; break; }
            }
            return map;
        }

        List<Object> parseArray() {
            List<Object> list = new ArrayList<>();
            pos++; // consume '['
            skipWhitespace();
            if (peek() == ']') { pos++; return list; }
            while (true) {
                Object value = parseValue();
                list.add(value);
                skipWhitespace();
                char c = peek();
                if (c == ',') { pos++; continue; }
                if (c == ']') { pos++; break; }
            }
            return list;
        }

        String parseString() {
            StringBuilder sb = new StringBuilder();
            pos++; // consume opening quote
            while (true) {
                char c = s.charAt(pos++);
                if (c == '"') break;
                if (c == '\\') {
                    char next = s.charAt(pos++);
                    switch (next) {
                        case '"': sb.append('"'); break;
                        case '\\': sb.append('\\'); break;
                        case '/': sb.append('/'); break;
                        case 'b': sb.append('\b'); break;
                        case 'f': sb.append('\f'); break;
                        case 'n': sb.append('\n'); break;
                        case 'r': sb.append('\r'); break;
                        case 't': sb.append('\t'); break;
                        case 'u':
                            String hex = s.substring(pos, pos + 4);
                            sb.append((char) Integer.parseInt(hex, 16));
                            pos += 4;
                            break;
                        default: sb.append(next);
                    }
                } else {
                    sb.append(c);
                }
            }
            return sb.toString();
        }

        Double parseNumber() {
            int start = pos;
            while (pos < s.length() && "-+.eE0123456789".indexOf(s.charAt(pos)) >= 0) pos++;
            return Double.parseDouble(s.substring(start, pos));
        }
    }

    // ---------- WRITING ----------

    public static String write(Object obj) {
        StringBuilder sb = new StringBuilder();
        writeValue(obj, sb, 0);
        return sb.toString();
    }

    @SuppressWarnings("unchecked")
    private static void writeValue(Object obj, StringBuilder sb, int indent) {
        if (obj == null) {
            sb.append("null");
        } else if (obj instanceof String) {
            writeString((String) obj, sb);
        } else if (obj instanceof Map) {
            writeObject((Map<String, Object>) obj, sb, indent);
        } else if (obj instanceof List) {
            writeArray((List<Object>) obj, sb, indent);
        } else if (obj instanceof Double || obj instanceof Integer || obj instanceof Long) {
            double d = ((Number) obj).doubleValue();
            if (d == Math.floor(d) && !Double.isInfinite(d)) {
                sb.append((long) d);
            } else {
                sb.append(d);
            }
        } else if (obj instanceof Boolean) {
            sb.append(obj.toString());
        } else {
            writeString(obj.toString(), sb);
        }
    }

    private static void writeObject(Map<String, Object> map, StringBuilder sb, int indent) {
        sb.append("{\n");
        int i = 0;
        int size = map.size();
        for (Map.Entry<String, Object> entry : map.entrySet()) {
            indent(sb, indent + 1);
            writeString(entry.getKey(), sb);
            sb.append(": ");
            writeValue(entry.getValue(), sb, indent + 1);
            if (++i < size) sb.append(",");
            sb.append("\n");
        }
        indent(sb, indent);
        sb.append("}");
    }

    private static void writeArray(List<Object> list, StringBuilder sb, int indent) {
        if (list.isEmpty()) { sb.append("[]"); return; }
        sb.append("[\n");
        for (int i = 0; i < list.size(); i++) {
            indent(sb, indent + 1);
            writeValue(list.get(i), sb, indent + 1);
            if (i < list.size() - 1) sb.append(",");
            sb.append("\n");
        }
        indent(sb, indent);
        sb.append("]");
    }

    private static void writeString(String s, StringBuilder sb) {
        sb.append('"');
        for (int i = 0; i < s.length(); i++) {
            char c = s.charAt(i);
            switch (c) {
                case '"': sb.append("\\\""); break;
                case '\\': sb.append("\\\\"); break;
                case '\n': sb.append("\\n"); break;
                case '\r': sb.append("\\r"); break;
                case '\t': sb.append("\\t"); break;
                default:
                    if (c < 0x20) {
                        sb.append(String.format("\\u%04x", (int) c));
                    } else {
                        sb.append(c);
                    }
            }
        }
        sb.append('"');
    }

    private static void indent(StringBuilder sb, int level) {
        for (int i = 0; i < level; i++) sb.append("  ");
    }
}
