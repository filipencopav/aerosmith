# aerosmith
Little man computer implemented in C.  
Idea from a random /g/ programming challenges roll.

---
Default program in `instr.txt` is a fibonacci calculator

---
Dependencies:
 - git (optional)
 - make (optional)
 - any c compiler

---
To run:

```
git clone https://github.com/theamazingwaffle/aerosmith
cd aerosmith
make run
```

Without make:

```
git clone https://github.com/theamazingwaffle/aerosmith
cd aerosmith
gcc -std=c90 main.c -o aerosmith
./aerosmith
```

---

Little man computer programming language [documentation][1]. The source code is
a mix of mnemonic codes and actual addresses (ex: STA 123). It goes into
`instr.txt`. Unlike in the wikipedia version, `DAT` receives an argument, which
is the value stored in the given mailbox. Each line that has code is a mailbox
itself. When finished writing your program, execute `make run` and see the
output. Make sure to be in aerosmith's directory.

[1]: https://en.wikipedia.org/wiki/Little_man_computer
