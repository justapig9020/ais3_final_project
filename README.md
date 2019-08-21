# This is the final project of ais3 2019

## Overview
Use dlfan.h to overwrite malloc and free, base on these two function, count how many memories are allocated and freed, to make sure every memories are freed when the process terminated

## Structure 

### initialize and terminate
Use __attribute__ to initialize the memCounter and check it when terminated

### memCounter
Base on linked list, the saved informations include
- memory address
- allocated size

### malloc and free 
Use dlfan.h to overwrite the original functions, save the alloct size and address as a node then push it into the memCounter when malloc. Check the address was allocate and remove it from the memCounter when free

## How to use 
Chage the file name ```test``` at the ```run1``` in the ```makefile``` to the file name whitch you want to test, then use ```$ make``` to start the test  
