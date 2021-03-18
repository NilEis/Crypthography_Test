## Build
```Bash
gcc -Wall -std=c99 -m32 -IInclude -c asymmetric.c -o obj\Release\asymmetric.o
gcc -Wall -std=c99 -m32 -IInclude -c gui.c -o obj\Release\gui.o
gcc -Wall -std=c99 -m32 -IInclude -c helper_functions.c -o obj\Release\helper_functions.o
gcc -Wall -std=c99 -m32 -IInclude -c main.c -o obj\Release\main.o
g++ -o bin\Release\RSA.exe obj\Release\asymmetric.o obj\Release\gui.o obj\Release\helper_functions.o obj\Release\main.o  -lncurses
```
