CSCI 2720

Assignnment 4: Binary Search Tree

README
==============================================

Group members
-------------
Austin Schultz - als93978@uga.edu
       * Contributions: Functions mentioned in BinaryTree.h, some debugging of main, valgrind testing and debugging,
       README.txt, some testing, some comments
       
David Doan - dd67391@uga.edu
       * Contributions: Functions mentioned in BinaryTree.h, ItemType.cpp, ItemType.h, some debugging of main, Makefile,
       Bonus, some testing, some comments


Compiling
---------
Ensure you are in the correct assignment directory (Schultz-Doan-assignment4).

Then simply run:
make compile

gcc version 6.2.0 was used to compile for testing.

To compile manually, run the following:
g++ -g -Wall -O0 -pedantic-errors -o main ItemType.cpp BinaryTree.cpp Main.cpp

To run
------
Simply run:
make run    **(note this runs ./main input.txt)

To run manually, run the following:
./main input.txt
or ./main [other input file]

After running
-------------
If you want, you can run the following:
make clean

Or, run: rm main.

This deletes the 'main' executable file.
