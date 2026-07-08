import java.util.ArrayList;
import java.util.LinkedHashMap;
import java.util.List;
import java.util.Map;

public class User {
    private String username;
    private String password;
    private double balance;
    private List<Transaction> transactions;

    public User(String username, String password, double balance) {
        this.username = username;
        this.password = password;
        this.balance = balance;
        this.transactions = new ArrayList<>();
    }

    public String getUsername() { return username; }
    public String getPassword() { return password; }
    public double getBalance() { return balance; }
    public void setBalance(double balance) { this.balance = balance; }
    public List<Transaction> getTransactions() { return transactions; }

    public void addTransaction(Transaction t) {
        transactions.add(t);
    }

    public Map<String, Object> toMap() {
        Map<String, Object> map = new LinkedHashMap<>();
        map.put("username", username);
        map.put("password", password);
        map.put("balance", balance);
        List<Object> txList = new ArrayList<>();
        for (Transaction t : transactions) {
            txList.add(t.toMap());
        }
        map.put("transactions", txList);
        return map;
    }

    @SuppressWarnings("unchecked")
    public static User fromMap(Map<String, Object> map) {
        String username = (String) map.get("username");
        String password = (String) map.get("password");
        double balance = ((Number) map.get("balance")).doubleValue();
        User user = new User(username, password, balance);
        Object txObj = map.get("transactions");
        if (txObj instanceof List) {
            for (Object o : (List<Object>) txObj) {
                user.addTransaction(Transaction.fromMap((Map<String, Object>) o));
            }
        }
        return user;
    }
}
