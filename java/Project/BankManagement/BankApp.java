import java.io.*;
import java.nio.charset.StandardCharsets;
import java.nio.file.*;
import java.time.LocalDateTime;
import java.time.format.DateTimeFormatter;
import java.util.*;

public class BankApp {

    private static final String DATA_FILE = "bank_data.json";
    private static final DateTimeFormatter TIME_FORMAT =
            DateTimeFormatter.ofPattern("yyyy-MM-dd HH:mm:ss");

    private final Map<String, User> users = new LinkedHashMap<>();
    private final Scanner scanner = new Scanner(System.in);

    public static void main(String[] args) {
        BankApp app = new BankApp();
        app.loadUsers();
        app.run();
    }

    // ---------- MAIN MENU ----------

    private void run() {
        System.out.println("=========================================");
        System.out.println("      WELCOME TO THE JAVA BANK SYSTEM");
        System.out.println("=========================================");

        boolean running = true;
        while (running) {
            System.out.println("\n--- MAIN MENU ---");
            System.out.println("1. Create New User");
            System.out.println("2. Login");
            System.out.println("3. Exit");
            System.out.print("Choose an option: ");

            String choice = scanner.nextLine().trim();
            switch (choice) {
                case "1":
                    createUser();
                    break;
                case "2":
                    login();
                    break;
                case "3":
                    running = false;
                    System.out.println("Thank you for using the Java Bank System. Goodbye!");
                    break;
                default:
                    System.out.println("Invalid option. Please choose 1, 2, or 3.");
            }
        }
        scanner.close();
    }

    // ---------- CREATE USER ----------

    private void createUser() {
        System.out.println("\n--- CREATE NEW USER ---");
        System.out.print("Enter a username: ");
        String username = scanner.nextLine().trim();

        if (username.isEmpty()) {
            System.out.println("Username cannot be empty.");
            return;
        }
        if (users.containsKey(username)) {
            System.out.println("That username already exists. Please choose another.");
            return;
        }

        System.out.print("Enter a password: ");
        String password = scanner.nextLine().trim();
        if (password.isEmpty()) {
            System.out.println("Password cannot be empty.");
            return;
        }

        double initialDeposit = 0;
        System.out.print("Enter initial deposit amount (or 0 to skip): ");
        try {
            initialDeposit = Double.parseDouble(scanner.nextLine().trim());
            if (initialDeposit < 0) initialDeposit = 0;
        } catch (NumberFormatException e) {
            System.out.println("Invalid amount entered, defaulting to 0.");
        }

        User user = new User(username, password, initialDeposit);
        if (initialDeposit > 0) {
            user.addTransaction(new Transaction("DEPOSIT", initialDeposit, initialDeposit, now()));
        }
        users.put(username, user);
        saveUsers();

        System.out.println("New User Created");
    }

    // ---------- LOGIN ----------

    private void login() {
        System.out.println("\n--- LOGIN ---");
        System.out.print("Username: ");
        String username = scanner.nextLine().trim();
        System.out.print("Password: ");
        String password = scanner.nextLine().trim();

        User user = users.get(username);
        if (user == null || !user.getPassword().equals(password)) {
            System.out.println("Invalid username or password.");
            return;
        }

        System.out.println("\nLogin successful. Welcome, " + username + "!");
        boolean loggedIn = true;
        while (loggedIn) {
            System.out.println("\n--- ACCOUNT MENU (" + username + ") ---");
            System.out.println("1. Deposit");
            System.out.println("2. Withdraw");
            System.out.println("3. View Withdrawal & Deposit Records");
            System.out.println("4. Check Balance");
            System.out.println("5. Logout");
            System.out.print("Choose an option: ");

            String choice = scanner.nextLine().trim();
            switch (choice) {
                case "1":
                    deposit(user);
                    break;
                case "2":
                    withdraw(user);
                    break;
                case "3":
                    viewHistory(user);
                    break;
                case "4":
                    System.out.printf("Current balance: Rs. %.2f%n", user.getBalance());
                    break;
                case "5":
                    loggedIn = false;
                    System.out.println("Logged out successfully.");
                    break;
                default:
                    System.out.println("Invalid option. Please choose 1-5.");
            }
        }
    }

    // ---------- DEPOSIT ----------

    private void deposit(User user) {
        System.out.print("Enter deposit amount: ");
        double amount;
        try {
            amount = Double.parseDouble(scanner.nextLine().trim());
        } catch (NumberFormatException e) {
            System.out.println("Invalid amount.");
            return;
        }
        if (amount <= 0) {
            System.out.println("Deposit amount must be greater than 0.");
            return;
        }

        user.setBalance(user.getBalance() + amount);
        user.addTransaction(new Transaction("DEPOSIT", amount, user.getBalance(), now()));
        saveUsers();

        System.out.printf("Deposit successful. New balance: Rs. %.2f%n", user.getBalance());
    }

    // ---------- WITHDRAW ----------

    private void withdraw(User user) {
        System.out.print("Enter withdrawal amount: ");
        double amount;
        try {
            amount = Double.parseDouble(scanner.nextLine().trim());
        } catch (NumberFormatException e) {
            System.out.println("Invalid amount.");
            return;
        }
        if (amount <= 0) {
            System.out.println("Withdrawal amount must be greater than 0.");
            return;
        }
        if (amount > user.getBalance()) {
            System.out.println("Insufficient balance.");
            return;
        }

        user.setBalance(user.getBalance() - amount);
        user.addTransaction(new Transaction("WITHDRAWAL", amount, user.getBalance(), now()));
        saveUsers();

        System.out.printf("Withdrawal successful. New balance: Rs. %.2f%n", user.getBalance());
    }

    // ---------- VIEW HISTORY ----------

    private void viewHistory(User user) {
        System.out.println("\n--- TRANSACTION HISTORY (" + user.getUsername() + ") ---");
        List<Transaction> transactions = user.getTransactions();
        if (transactions.isEmpty()) {
            System.out.println("No transactions yet.");
            return;
        }
        for (Transaction t : transactions) {
            System.out.println(t);
        }
    }

    // ---------- PERSISTENCE ----------

    @SuppressWarnings("unchecked")
    private void loadUsers() {
        Path path = Paths.get(DATA_FILE);
        if (!Files.exists(path)) {
            return; // No file yet, start fresh
        }
        try {
            String content = new String(Files.readAllBytes(path), StandardCharsets.UTF_8);
            if (content.trim().isEmpty()) return;

            Object parsed = JsonUtil.parse(content);
            if (parsed instanceof List) {
                for (Object o : (List<Object>) parsed) {
                    User user = User.fromMap((Map<String, Object>) o);
                    users.put(user.getUsername(), user);
                }
            }
        } catch (IOException e) {
            System.out.println("Warning: could not read " + DATA_FILE + " (" + e.getMessage() + "). Starting fresh.");
        } catch (Exception e) {
            System.out.println("Warning: " + DATA_FILE + " appears corrupted. Starting fresh.");
        }
    }

    private void saveUsers() {
        List<Object> list = new ArrayList<>();
        for (User user : users.values()) {
            list.add(user.toMap());
        }
        String json = JsonUtil.write(list);
        try {
            Files.write(Paths.get(DATA_FILE), json.getBytes(StandardCharsets.UTF_8));
        } catch (IOException e) {
            System.out.println("Error saving data: " + e.getMessage());
        }
    }

    private String now() {
        return LocalDateTime.now().format(TIME_FORMAT);
    }
}
