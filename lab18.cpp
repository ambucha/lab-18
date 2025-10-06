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
// arguments: pointer to node, value, comment (i need to pass by reference for the poitner)
// returns: nothing
void pushback(Node *&, double, string);

// pushfront(): pushes value to the front of the linked list
// arguments: pointer to node, value, comment
// returns: nothing
void pushfront(Node *&, double, string);

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
    // Check to see if list is empty
    if (!hd){
        cout << "Empty list" << endl;
        return;
    }

    int count = 1;
    Node * current = hd;

    // Loop through the reviews
    cout << "Outputting all reviews:" << endl;
    while (current){
        cout << "\t> Review #" << count << ": " << current->rating << ": " << current->comment << endl;
        current = current->next;
    }
    cout << endl;
}

void pushfront(Node *&hd, double r, string c){
    Node *newNode = new Node;

    //adds a node at head
    if(!hd){
        hd = newNode;
        newNode->next = nullptr;
        newNode->rating = r;
        newNode->comment = c;
    }
    else {
        newNode->next = hd;
        newNode->rating = r;
        newNode->comment = c;
        hd = newNode;
    }
}

void pushback(Node *&hd, double r, string c){\
    Node *newNode = new Node;

    // set the new nodes data
    newNode->rating = r;
    newNode->comment = c;
    newNode->next = nullptr;

    // check if the list is empty
    if(!hd){
        hd = newNode;
        return;
    }

    //if not empty then walk to the tail
    Node *current = hd;
    while(current->next){
        current = current->next;
    }

    // Now add the new node to the tail
    current->next = newNode;
}

