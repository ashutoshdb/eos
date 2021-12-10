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

- gcc -o main main.c -lairth -L. (for static)
- gcc -o main main.c -lairth -L. (for dynamic)

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

# day 9 and day 10

- Race around condition is the problem in which shared space is access by both the threads at the same time
- Mutal exclusion is the solution
- crital region is a region in which comman varilable are used between mutiple threads and IT SHOULD BE AS SMALL AS POSSIBLE
- In mutex(provide mutal exclusion) when lock is used in critical region and other thread go in wait state until unlock
- mutex implimanted in user space
- 1-> futex = fast mutex
- 2-> recursive mutex
- 3->  adaptive mutex
- 4->  error checking mutex

- mutex can only be used in between threads not in processes

## if there is shared resource we should have mutal exclusion (mutex or semipolise)

## try to have small critical reagion

- if we lock 2 time a thread(we call a function in which lock is happend inside a lock ) then it will put that thread into wait condition and we will face deadlock situation

- to create different time of mutex using attributes or initialise

- semaphore  
  - binary 1-> signalling 2-> mutual exclusion
  - counting

- semaphore can be used in between threads not in processes
- sem wait check the value by one and dec by 1 if value is 0 it waits if value is 1 its execute
- sem post increse the value by 1

# Day 11

## Ipc -> Shared Memory and massege queue

- shared memory is created(with name and size ) in user space and is much faster and are of fixed size 
- face race condion and semahpore is used to solve race conditon because they are used in between threads
- counting semaphore uses in resource management 



?? counting semaphore ?? named semaphore