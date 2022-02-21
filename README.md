# Tic Tac Toe OS aka TIC TOS

If I remember correctly, this my second ever program in C after hello world.

This is dual player tic tac toe from scratch compiled for 1386 systems and compatible for x86_64 systems.

I followed the futorial from https://github.com/cfenollosa/os-tutorial to build the base of this os.

Build instructions:

Follow the instructions from https://github.com/cfenollosa/os-tutorial/tree/master/11-kernel-crosscompiler to setup a cross compilor or just use the compiled binary provided.

To compile and run:
```
git clone https://github.com/lonely-code-cube/tic-tac-toe-os
cd tic-tac-toe-os
make
make run
```
If you just want to boot the provided binary (you must have qemu installed)
```
qemu-system-i386 -fda os-image.bin
```
or
```
qemu-system-x86_64 -fda os-image.bin
```
