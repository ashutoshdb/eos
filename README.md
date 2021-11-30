# Embedded Operating Systems


## Tools

- Typerora
- Shutter
- VS code

## Day 4 Library

- Static Library(.a) => archieve file
- Dyanamic Library(.so) => shared object

# command for creating library

- ar -cr libname.a add.o sub.o
- gcc -o libname.so -shared -fPIC add.o sub.o  (for dynamic)

# commad for compling with library
-  gcc -o main main.c -lairth -L. (for static)
-  gcc -o main main.c -lairth -L. (for dynamic)

export LD_LIBRARY_PATH=.

# system call

- man 2 open,read,write to see all the details 
- fd = open("desd.txt", O_WRONLY | O_CREAT, S_IRUSR | S_IWUSR); 
