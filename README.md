## Build
```Bash
gcc -Wall -std=c99 -m32 -IInclude -c src\asymmetric.c -o obj\Release\asymmetric.o
gcc -Wall -std=c99 -m32 -IInclude -c src\gui.c -o obj\Release\gui.o
gcc -Wall -std=c99 -m32 -IInclude -c src\helper_functions.c -o obj\Release\helper_functions.o
gcc -Wall -std=c99 -m32 -IInclude -c main.c -o obj\Release\main.o
g++ -o bin\Release\CrypTest.exe obj\Release\asymmetric.o obj\Release\gui.o obj\Release\helper_functions.o obj\Release\main.o  -lncurses
```
