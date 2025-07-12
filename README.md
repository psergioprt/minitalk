# 📡 minitalk

**minitalk** is a 42 project focused on inter-process communication using UNIX signals.  
It consists of a client and a server program that exchange messages by sending and receiving signals.

---

## 🧩 Project Overview

- Implements communication between processes using `SIGUSR1` and `SIGUSR2`.
- The server listens for incoming signals and reconstructs the transmitted message bit by bit.
- The client encodes a string message into signals and sends them to the server’s process ID (PID).
- Ensures reliable transmission with acknowledgement signals.
- Demonstrates low-level IPC (Inter-Process Communication) without using sockets or files.

---

## ⚙️ Compilation

Compile with the provided Makefile:

bash
make

## ▶️ Usage

Start the server first:

./server

It will display its PID for the client to use.

Then, run the client, passing the server PID and a message string:

./client <server_pid> "Your message here"

The client sends the message to the server via signals, which then prints the received text.
## 📌 Learning Outcomes

    Understanding UNIX signal handling in C.

    Implementing communication protocols without standard IPC mechanisms.

    Managing synchronization and data integrity between processes.

    Practicing bitwise operations and low-level programming concepts.
