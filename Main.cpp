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
    // tree.preOrder();
    // tree.inOrder();
    // tree.postOrder();

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

    // GET LENGTH FUNCTION TEST

    // cout << "Tree length: " << tree.getLength() << endl;
    
    // MAIN CODE
    
    BinaryTree tree;
    ItemType item;
    int input;
    fstream fs;
    fs.open(argv[1], fstream::in); // reads input file

    if (fs.is_open()) {
    	fs >> input;

    	while (!fs.eof()) {
    	    item.initialize(input);
    	    tree.insert(item);
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
    	    cout << "Item to insert: ";
    	    int value;
    	    cin >> value;
    	    cin.ignore(1, '\n');
    	    ItemType item(value);
    	    tree.insert(item);
    	    cout << endl;
    	    cout << "In-Order: " << endl;
    	    tree.inOrder();
    	    cout << endl;
    	    break;
    	}

    	case 'd': { // delete command
    	    cout << "Item to delete: ";
    	    int value;
    	    cin >> value;
    	    cin.ignore(1, '\n');
    	    ItemType item(value);
    	    tree.deleteItem(item);
    	    cout << endl;
    	    cout << "In-Order: " << endl;
    	    tree.inOrder();
    	    cout << endl;
    	    break;
    	}
    	case 'r': { // retrieve command
    	    cout << "Item to retrieved: ";
    	    int value;
    	    cin >> value;
    	    cin.ignore(1, '\n');
    	    ItemType item(value);
    	    bool found = false;
    	    tree.retrieve(item, found);
    	    cout << endl;
    	    break;
    	}

    	case 'l': { // length command
    	    cout << "List Length: " << tree.getLength()  << endl;
    	    cout << endl;
    	    break;
    	}
	    
    	case 'n': { // in-order command that prints the binary tree in in-order-traverse
    	    cout << "In-Order: " << endl;
    	    tree.inOrder();
    	    cout << endl;
    	    break;
    	}  
		
    	case 'p': { // pre-order command that prints the binary tree in pre-order traverse
    	    cout << "Pre-Order: " << endl;
    	    tree.preOrder();
    	    cout << endl;
    	    break;
    	}
	    
    	case 'o': { // post-order command that prints the binary tree in post-order traverse
    	    cout << "Post-Order: " << endl;
    	    tree.postOrder();
    	    cout << endl;
    	    break;
    	}
	    
    	case 'c': { // this command finds the value of nodes that are in the same level and not siblings
	    cout << "Item to find same level nonsiblings: ";
	    int value;
	    cin >> value;
	    cin.ignore(1, '\n');
	    ItemType item(value);
	    tree.getSameLevelNonsiblings(item);
	    cout << endl;
    	    break;
    	}
	    
    	case 'q': { // quit command that stops the while loop and exits the program
    	    cout << "Quitting program...\n" << endl;
    	    loop = false;
    	    break;
    	}
	    
    	default: { // this will print when the command is invalid
    	    cout << "Command not recognized, Try again" << endl;
    	    break;
    	}
    	}
    }
}
