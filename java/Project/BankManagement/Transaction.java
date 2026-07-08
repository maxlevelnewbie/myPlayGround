import java.util.LinkedHashMap;
import java.util.Map;

public class Transaction {
    private String type;        // "DEPOSIT" or "WITHDRAWAL"
    private double amount;
    private double balanceAfter;
    private String timestamp;

    public Transaction(String type, double amount, double balanceAfter, String timestamp) {
        this.type = type;
        this.amount = amount;
        this.balanceAfter = balanceAfter;
        this.timestamp = timestamp;
    }

    public String getType() { return type; }
    public double getAmount() { return amount; }
    public double getBalanceAfter() { return balanceAfter; }
    public String getTimestamp() { return timestamp; }

    public Map<String, Object> toMap() {
        Map<String, Object> map = new LinkedHashMap<>();
        map.put("type", type);
        map.put("amount", amount);
        map.put("balanceAfter", balanceAfter);
        map.put("timestamp", timestamp);
        return map;
    }

    @SuppressWarnings("unchecked")
    public static Transaction fromMap(Map<String, Object> map) {
        String type = (String) map.get("type");
        double amount = ((Number) map.get("amount")).doubleValue();
        double balanceAfter = ((Number) map.get("balanceAfter")).doubleValue();
        String timestamp = (String) map.get("timestamp");
        return new Transaction(type, amount, balanceAfter, timestamp);
    }

    @Override
    public String toString() {
        return String.format("[%s] %-10s Rs. %-10.2f  Balance after: Rs. %.2f", timestamp, type, amount, balanceAfter);
    }
}
