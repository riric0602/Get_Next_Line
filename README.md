# GET NEXT LINE : *Reading a line from a fd is way too tedious*

> This project is coded in C, it has to implement a **get_next_line()** function that can read a text file, one line at a time, through repeated calls

The most important thing in this assignment was to discover static variables and how to read / write on files using the C language. The option *-D BUFFER_SIZE=42* for example can be added to the compilation flags in order to determine how many characters will the system call **read()** will read every time it is called. It was very crucial in this project to prevent leaks or segmentation faults from happening in scenarios such as from overflow errors or reading from a line that doesn't example.

The *Bonus* part demands that the code only uses **one static variable**, and can also manage **multiple file descriptors at the same time**, the *_bonus.c files should be compiled on their own.
