#include<iostream
using namespace std;

// definition of linklist node
class Listnode{
    public:
    int val ;
    Listnode*next;

    Listnode(int data){
        val = data;
        next  = NULL;
    }
};

// Insert node at the end of linklist 

void Insertatend(Listnode *&head , int value){

    // create a node

    Listnode * newnode = new Listnode(value);
    

    //what if the list is empty

    if(head == NULL){
        head = newnode;
        return;
    }

    // traverse till last node

    Listnode * temp = head ;

    while(temp->next != NULL){
        temp = temp->next;
    }
    temp->next = newnode;
}

//Print list

void printlist(Listnode * head){
Listnode *temp = head;

while(temp != NULL){
    cout<<temp->val<<" ";
    temp = temp->next;
}
cout<<endl;

}

// Function to find middle node
// ---------------------------------------------------------
Listnode* middlenode(Listnode* head)
{
    // If linked list is empty
    if(head == NULL)
        return NULL;

    // Slow pointer moves one step
    Listnode* slow = head;

    // Fast pointer moves two steps
    Listnode* fast = head;

    // Keep moving until fast reaches end
    while(fast != NULL && fast->next != NULL)
    {
        // Move slow by one node
        slow = slow->next;

        // Move fast by two nodes
        fast = fast->next->next;
    }

    // When loop ends,
    // slow will point to the middle node.
    return slow;
}


// Driver Code
// ---------------------------------------------------------
int main()
{
    Listnode* head = NULL;

    // Creating linked list
    Insertatend(head,1);
    Insertatend(head,2);
    Insertatend(head,3);
    Insertatend(head,4);
    Insertatend(head,5);
    Insertatend(head,6);

    cout<<"Linked List : ";
    printlist(head);

    // Find middle node
    Listnode* middle = middlenode(head);

    cout<<"Middle Node : "<<middle->val<<endl;

    return 0;
}