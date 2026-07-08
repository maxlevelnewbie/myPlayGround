# Java Bank System

A simple console-based banking application in Java that stores user
data (username, password, balance, and transaction history) in a
JSON file (`bank_data.json`), created automatically next to the
program the first time you create a user.

No external libraries are required — a small built-in JSON
reader/writer (`JsonUtil.java`) handles all the file persistence.

## Files
- `BankApp.java` – main program: menu, login, deposit/withdraw, file I/O
- `User.java` – user account model
- `Transaction.java` – single deposit/withdrawal record
- `JsonUtil.java` – minimal JSON parser & writer (no dependencies needed)

## How to Compile
Open a terminal in this folder and run:

```
javac *.java
```

## How to Run

```
java BankApp
```

## Features

**Main Menu**
1. Create New User – enter a username, password, and optional initial
   deposit. Prints `New User Created` on success.
2. Login – enter your username/password to access your account.
3. Exit – closes the program.

**Account Menu (after logging in)**
1. Deposit – add money to your balance.
2. Withdraw – take money out (blocked if it exceeds your balance).
3. View Withdrawal & Deposit Records – see your full transaction history.
4. Check Balance
5. Logout – return to the main menu.

## Data Storage

All accounts are saved to `bank_data.json` in the same folder,
in a human-readable format like this:

```json
[
  {
    "username": "john",
    "password": "mypass",
    "balance": 600,
    "transactions": [
      { "type": "DEPOSIT", "amount": 500, "balanceAfter": 500, "timestamp": "2026-07-08 14:49:42" },
      { "type": "DEPOSIT", "amount": 200, "balanceAfter": 700, "timestamp": "2026-07-08 14:49:42" },
      { "type": "WITHDRAWAL", "amount": 100, "balanceAfter": 600, "timestamp": "2026-07-08 14:49:42" }
    ]
  }
]
```

The file is re-read on startup and re-written after every change, so
your data persists between runs.

## Note on Security

Passwords are stored in plain text for simplicity, which is fine for
learning/demo purposes but **not** suitable for a real banking
application. In production you'd hash passwords (e.g. with BCrypt)
before storing them.
