# aerosmith – Little Man Computer in C

A minimal implementation of the [Little Man Computer](https://en.wikipedia.org/wiki/Little_man_computer) (LMC), written in ANSI C90.

The LMC is a simplified model of a von Neumann architecture computer, used for teaching assembly and machine-level programming concepts.

---

## 📦 Features

- Supports standard LMC instruction set (ADD, SUB, STA, LDA, BRA, BRZ, BRP, INP, OUT, COB)
- Custom extension: `DAT` accepts a value directly (e.g., `DAT 42`)
- Programs are read from `instr.txt`
- Default program calculates Fibonacci numbers

---

## 💻 Requirements

- Any C compiler (GCC, Clang, etc.)
- Optional: `git` and `make` for convenience

---

## ▶️ How to Run

Using `make`:
```bash
git clone https://github.com/theamazingwaffle/aerosmith 
cd aerosmith
make run
```

Without `make`:
```bash
git clone https://github.com/theamazingwaffle/aerosmith 
cd aerosmith
gcc -std=c90 main.c -o aerosmith
./aerosmith
```

---

## 📄 Writing Programs

Each line in `instr.txt` represents one "mailbox" in the LMC.

Example:
```
INP
STA 6
LDA 6
OUT
COB
```

This simple program reads input, stores it in mailbox number 6, loads and outputs it, then halts.

For more information about LMC programming, see the [Wikipedia page](https://en.wikipedia.org/wiki/Little_man_computer).

---

## 🛠️ Implementation Notes

- Memory: 100 mailboxes (0–99)
- Accumulator: holds current arithmetic result
- Program Counter: tracks next instruction address
- Input/Output: via stdin/stdout

Self-modifying code is supported — treat data as instructions at your own risk!

---

## 📝 Roadmap

- Add support for labels and symbolic addressing
- Implement debugging output (register/memory dump)
- Add unit tests
- Create a GUI interface or web-based emulator

---

## 🤝 Contributing

PRs welcome! Please ensure changes are well-documented and tested.

---

## 📜 License

BSD 3 Clause License
