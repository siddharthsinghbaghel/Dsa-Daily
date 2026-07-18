#include<iostream>
using namespace std;

// Definition of listnode
class Listnode{
    public:
    int val;
    Listnode *next;

    Listnode(int data){
        val = data;
        next = NULL;
    }
};


// Main logic or function to reverse list 

Listnode * reverselist(Listnode * head ){
    Listnode*prev = NULL;
    Listnode * curr = head;
    Listnode * next = NULL;

    while(curr != NULL){
        Listnode * nextnode = curr->next;
        curr->next = prev;
        prev =curr;
        curr = nextnode;
    }
    return prev;
}


// function to insert at the end 

void insertatend(Listnode *&head, int value){

    // create new node 
    Listnode * newnode = new Listnode(value);

    // what if the list is empty
    if(head == NULL){
        head = newnode;
        return;
    }

    // now traverse till last
    Listnode * temp = head;

    while(temp->next != NULL){
        temp = temp->next;
    }
    //connect new node to the last node
    temp->next = newnode; 
}

// function to print list 

void printlist(Listnode * head){
    Listnode * temp = head ;

    while(temp != NULL){
        cout<<temp->val <<" ";
        temp = temp->next;
    }
    cout<<endl;
}

// Driver code 

int main(){
 // create a linked list

    Listnode * head = NULL;
  
    // insert some values

    insertatend(head, 1);
    insertatend(head, 2);   
    insertatend(head, 3);
    insertatend(head, 4);
    insertatend(head, 5);

    cout<<"Original list: ";
    printlist(head);

    // reverse the list
    head = reverselist(head);

    cout<<"Reversed list: ";
    printlist(head);
    return 0;

}