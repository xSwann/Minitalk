# Minitalk (42)

> A small communication program using **UNIX signals** to exchange messages between a client and a server.

---

## 🚀 Description

Minitalk is a simple message exchange system: a **server** receives messages sent by a **client**. The communication uses only **SIGUSR1** and **SIGUSR2** signals, as required by the 42 subject.

This project introduces:

* UNIX process communication (IPC)
* Signal handling
* Bit manipulation

---

## ✨ Features

* Client → Server messaging via **UNIX signals** only (`SIGUSR1` / `SIGUSR2`)
* **Bitwise transmission** (send message bit by bit)
* Handles **spaces and punctuation** in messages
* **Acknowledgment**: server sends a signal back when the message is fully received
* **Bonus implemented** and **built by default** (no separate `make bonus` required)

---

## 🔧 Build

Compile both programs with the included `Makefile` (bonus included by default):

```bash
make        # build server and client (includes bonus)
make clean  # remove object files
make fclean # remove objects and binaries
make re     # rebuild everything
```

---

## ▶️ Usage

Start the server first:

```bash
./server
# Example output: PID: 42421
```

Send a message (spaces and punctuation supported):

```bash
./client <SERVER_PID> "Hello, world!"
```

The client will finish after the server **acknowledges** the message reception.

---

## 📁 Project structure

```
Minitalk/
├─ Makefile
├─ client.c
├─ server.c
└─ minitalk.h
```

---

## 🧠 Implementation notes

* Communication relies on **signals** only
* Each bit of the message is sent using **SIGUSR1** or **SIGUSR2**
* The server reconstructs characters **bit by bit**
* The PID displayed at server startup is required by the client

---

## 👤 Author

* Swann — @xSwann
