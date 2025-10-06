// COMSC-210 | Lab 18 | Andrei Buchatskiy
// IDE used : Visual Studio Code

#include <iostream>
#include <string>
using namespace std;

// create the node struct with the data needed, in this case the rating and the comment
struct Node{
    int rating;
    string comment;
    Node *next;
};

// Needed functions are going to be the pushback pushfront and output function

// output(): outputs the linked list to user
// arguments: pointer to node struct
// returns: nothing
void output(Node *);

// pushback(): pushes value to the back of the linked list
// arguments: pointer to node, value, comment
// returns: nothing
void pushback(Node *, int, string);

// pushback(): pushes value to the front of the linked list
// arguments: pointer to node, value, comment
// returns: nothing
void pushback(Node *, int, string);

int main(){
    //variables
    Node *head = nullptr;
    int method;
    int rating;
    string comment; 

    // ask for if to push to front or back
    cout << "Which linked list method should we use?" << endl;
    cout << "[1] New nodes are added at the head of the linked list" << endl;
    cout << "[2] New nodes are added at the tail of the linked list" << endl;
    cout << "Choice: ";
    cin >> method;

    // Check for chosen method (and if neither is chosen)
    if(method == 1){
        // ask for review rating and comment
        cout << "";

    }
    else if(method == 2) {

    }
    else {
        cout << "Error: Neither method chosen" << endl;
    }

    return 0;
}