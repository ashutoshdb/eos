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

# Day 6

- Fork api
- IPC
- pipe -> used for when process has relations

- named pipe -> fifo ->  used for when process has  no relations
    - mkfifo -m600 (name of fifo)

- process state diagram 
    - Create -> gets address space during create time (ready queque)
    - Ready -> mention on a table 
    - Running -> cpu is availabile
    - Exit-> destroyed state, resources will be free
    - Waiting state -> when process is waiting for some data from externl world and not using cpu or waiting for io

    - waiting goes into ready state then running
    - we can kill the process in the waiting state by kill -9 command
    - we cant no go into run state to wait state without runnig it  

# day 7 

- context saving ->  the value of registers in cpu,sp,ip,gpr,flags is saved logical ds in pcb or stack of process   
- context restore -> restore the value in physical copy from pcb or stack of process 
- pthread_create()
- cow copy on write -> os optimization 
- blocking (not come with data) and non blocking api (come with data or error) 

# day 8

- valgrind for memory leak 

- stack pointer
- stack
- stack frame is created when u call a fun it hold argument, local variable return address of the next inst. after the funtion
- racearound condition for global variable

- try on raspberrypie stack with gdb gef


            