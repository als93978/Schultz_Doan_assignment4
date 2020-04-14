#include <iostream>
#include <fstream>
#include "BinaryTree.h"
#include "ItemType.h"

using namespace std;

// author: David Doan
int main(int argc, char * argv[]) {
    BinaryTree list;
    ItemType item;
    int input;
    fstream fs;
    fs.open(argv[1], fstream::in); // reads input file

    if (fs.is_open()) {
	fs >> input;

	while (!fs.eof()) {
	    item.initialize(input);
	    list.insert(item);
	    fs >> input;
	}

	cout << "Commands: insert (i), delete (d), retrieve (r), length (l), in-order (n), pre-order (p), post-order (o), getSameLevelNonsiblings (c), quit (q)" << endl;
    }

    else {
	cout << "Failed to open the input file" << endl;
	return 0;
    }

    bool loop = true;
    char character; // character input when entering a command

    while (loop) {
	cout << "\nEnter a command: ";
    	cin >> character;
    	cout << "\n";

	switch (character) {
	    
	case 'i': { // insert command
	    break;
	}

	case 'd': { // delete command
	    break;
	}
	case 'r': {
	    break;
	}

	case 'l': { // length command
	    break;
	}
	    
	case 'n': {
	    break;
	}  
		
	case 'p': {
	    break;
	}
	    
	case 'o': {
	    break;
	}
	    
	case 'c': {
	    break;
	}
	    
	case 'q': { // quit command that stops the hile loop and exits the program
	    cout << "Quitting program...\n" << endl;
	    loop = false;
	    break;
	}
	    
	default: { // this will print when the command is invalid
	    cout << "Invalid command, try again!" << endl;
    	    break;
	}
	}
    }
}
