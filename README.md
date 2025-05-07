
# 🔐 TEXTCRYPT - C++ Text Encryption Tool

Welcome to **TEXTCRYPT**, a C++ command-line utility for **text encryption and decryption** using:

🔹 Caesar Cipher  
🔹 Keyword Cipher  
🔹 RSA Encryption  

Built as a **fun and educational project** for learning classical and asymmetric encryption methods in C++. 🎓

---

## 📦 Features

- 🔁 **Caesar Cipher** Encryption & Decryption  
- 🧠 **Keyword Cipher** with dynamic keyword substitution  
- 🔑 **RSA Encryption** using basic prime number generation  
- 🧮 ASCII to Cipher conversions  
- 🖥️ Clean terminal interface with user prompts  
- 🔄 Encryption/Decryption loop with options to retry or quit

---

## 🧰 Technologies Used

- C++ (Standard Library)  
- Random number generation (for prime selection in RSA)  
- Basic use of arrays, strings, and custom classes

---

## ⚙️ How It Works

1. You’ll be asked to choose a cipher method (Caesar, Keyword, RSA).
2. Enter a message and optionally a keyword or key depending on the cipher.
3. The tool will encrypt it and ask if you want to decrypt it.
4. Continue or exit the program!

---

## 🚀 Getting Started

### 🔧 Prerequisites

- C++ compiler (e.g., `g++`, Visual Studio, Code::Blocks)
- Windows (developed/tested) or Linux (with minor adjustments)

### 🛠️ Compile & Run

```bash
g++ -o textcrypt textcrypt.cpp
./textcrypt
