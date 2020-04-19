#include <iostream>
#include <fstream>
#include "BinaryTree.h"
#include "ItemType.h"

using namespace std;

// author: David Doan and Austin Schultz
int main(int argc, char * argv[]) {
    // // TESTING CODE
    // BinaryTree tree;

    // ItemType item1;
    // item1.initialize(50);
    // tree.insert(item1);

    // ItemType item2;
    // item2.initialize(35);
    // tree.insert(item2);

    // ItemType item3;
    // item3.initialize(45);
    // tree.insert(item3);

    // ItemType item4;
    // item4.initialize(73);
    // tree.insert(item4);

    // ItemType item5;
    // item5.initialize(85);
    // tree.insert(item5);

    // ItemType item6;
    // item6.initialize(10);
    // tree.insert(item6);

    // ItemType item7;
    // item7.initialize(65);
    // tree.insert(item7);

    // ItemType item8;
    // item8.initialize(5);
    // tree.insert(item8);

    // TRAVERSAL FUNCTION TEST
    //tree.inOrder();
    //tree.postOrder();

    // RETRIEVE/SEARCH FUNCTION TEST
    // ItemType testItem;
    // testItem.initialize(45);
    
    // bool found = false;
    // tree.retrieve(testItem, found);

    // cout << found << endl;

    // DELETE ITEM FUNCTION TEST
    // tree.inOrder();
    
    // tree.deleteItem(item1);

    // tree.inOrder();
    
    // MAIN CODE
    
    // BinaryTree list;
    // ItemType item;
    // int input;
    // fstream fs;
    // fs.open(argv[1], fstream::in); // reads input file

    // if (fs.is_open()) {
    // 	fs >> input;

    // 	while (!fs.eof()) {
    // 	    item.initialize(input);
    // 	    list.insert(item);
    // 	    fs >> input;
    // 	}

    // 	cout << "Commands: insert (i), delete (d), retrieve (r), length (l), in-order (n), pre-order (p), post-order (o), getSameLevelNonsiblings (c), quit (q)" << endl;
    // }

    // else {
    // 	cout << "Failed to open the input file" << endl;
    // 	return 0;
    // }

    // bool loop = true;
    // char character; // character input when entering a command

    // while (loop) {
    // 	cout << "\nEnter a command: ";
    // 	cin >> character;
    // 	cout << "\n";

    // 	switch (character) {
	    
    // 	case 'i': { // insert command
    // 	    break;
    // 	}

    // 	case 'd': { // delete command
    // 	    break;
    // 	}
    // 	case 'r': {
    // 	    break;
    // 	}

    // 	case 'l': { // length command
    // 	    break;
    // 	}
	    
    // 	case 'n': {
    // 	    break;
    // 	}  
		
    // 	case 'p': {
    // 	    break;
    // 	}
	    
    // 	case 'o': {
    // 	    break;
    // 	}
	    
    // 	case 'c': {
    // 	    break;
    // 	}
	    
    // 	case 'q': { // quit command that stops the while loop and exits the program
    // 	    cout << "Quitting program...\n" << endl;
    // 	    loop = false;
    // 	    break;
    // 	}
	    
    // 	default: { // this will print when the command is invalid
    // 	    cout << "Invalid command, try again!" << endl;
    // 	    break;
    // 	}
    // 	}
    // }
}
