// COMSC-210 | Lab 18 | Andrei Buchatskiy
// IDE used : Visual Studio Code

#include <iostream>
#include <string>
using namespace std;

// create the node struct with the data needed, in this case the rating and the comment
struct Node{
    double rating;
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
void pushback(Node *, double, string);

// pushfront(): pushes value to the front of the linked list
// arguments: pointer to node, value, comment
// returns: nothing
void pushfront(Node *, double, string);

int main(){
    //variables
    Node *head = nullptr;
    int method;
    double rating;
    string comment; 
    char yn;

    // ask for if to push to front or back
    cout << "Which linked list method should we use?" << endl;
    cout << "[1] New nodes are added at the head of the linked list" << endl;
    cout << "[2] New nodes are added at the tail of the linked list" << endl;
    cout << "Choice: ";
    cin >> method;

    // Check for chosen method (and if neither is chosen)
    if(method == 1){
        // ask for review rating and comment
        cout << "Enter review rating 0-5: ";
        cin >> rating;
        cout << "Enter review comments: ";
        cin.ignore();
        getline(cin, comment);
        pushfront(head, rating, comment);

        // check if they want to keep going
        cout << "Enter another review? Y/N: ";
        cin >> yn;

        // if they want to keep going add a while loop for however long they want to keep going
        while(yn == 'y' || yn == 'Y'){
            cout << "Enter review rating 0-5: ";
            cin >> rating;
            cout << "Enter review comments: ";
            cin.ignore();
            getline(cin, comment);
            pushfront(head, rating, comment);
            
            // recheck if they want to keep going to make sure its not inifinite
            cout << "Enter another review? Y/N: ";
            cin >> yn;
        }
    }
    else if(method == 2) {
        // ask for review rating and comment
        cout << "Enter review rating 0-5: ";
        cin >> rating;
        cout << "Enter review comments: ";
        cin.ignore();
        getline(cin, comment);
        pushback(head, rating, comment);

        // check if they want to keep going
        cout << "Enter another review? Y/N: ";
        cin >> yn;

        // if they want to keep going add a while loop for however long they want to keep going
        while(yn == 'y' || yn == 'Y'){
            cout << "Enter review rating 0-5: ";
            cin >> rating;
            cout << "Enter review comments: ";
            cin.ignore();
            getline(cin, comment);
            pushback(head, rating, comment);
            
            // recheck if they want to keep going to make sure its not inifinite
            cout << "Enter another review? Y/N: ";
            cin >> yn;
        }
    }
    else {
        cout << "Error: Neither method chosen" << endl;
    }

    // output the lists:
    output(head);

    return 0;
}

void output(Node * hd){
    if (!hd){
        cout << "Empty list\n";
        return;
    }
    int count = 1;
    Node * current = hd;
}

void pushback(Node * hd, double r, string c){

}

void pushfront(Node * hd, double r, string c){

}

