// find the starting point of cycle 

#include<iostream>
using namespace std;

class listnode{
    public:

    int val;
    listnode * next;

    listnode(int data){
        val = data;
        next = NULL;
    }
};


void insertatend(listnode*&head, int value){

    listnode * newnode = new listnode(value);   
    
     // Empty List
    if(head == NULL)
    {
        head = newnode;
        return;
    }

    listnode* temp = head;

    while(temp->next != NULL)
    {
        temp = temp->next;
    }

    temp->next = newnode;
}

void printList(listnode* head)
{
    while(head != NULL)
    {
        cout<<head->val<<" ";
        head=head->next;
    }

    cout<<endl;
}

//-------------------------------------------------------
// Create Cycle
//
// Example:
//
// 1 -> 2 -> 3 -> 4 -> 5
//           ^         |
//           |_________|
//
// position = 3
//-------------------------------------------------------

void createCycle(listnode* head,int position)
{
    if(position==0)
        return;

    listnode * cycleNode=NULL;
    listnode* temp=head;

    int count=1;

    while(temp->next!=NULL)
    {
        if(count==position)
            cycleNode=temp;

        temp=temp->next;
        count++;
    }

    // Connect last node to cycle node
    temp->next=cycleNode;
}

listnode* detectCycle(listnode* head)
{
    // Empty List
    if(head==NULL)
        return NULL;

    //---------------------------------------------------
    // Step 1 : Detect Cycle
    //---------------------------------------------------
    listnode* slow=head;
    listnode* fast=head;

    while(fast!=NULL && fast->next!=NULL)
    {
        slow=slow->next;
        fast=fast->next->next;

        // Cycle Detected
        if(slow==fast)
        {
            //------------------------------------------------
            // Step 2 : Find Starting Node
            //------------------------------------------------

            // Move slow back to head
            slow=head;

            // Move both one step
            while(slow!=fast)
            {
                slow=slow->next;
                fast=fast->next;
            }

            // Starting node
            return slow;
        }
    }

    // No Cycle
    return NULL;
}


int main()
{
    listnode* head=NULL;

    insertatend(head,1);
    insertatend(head,2);
    insertatend(head,3);
    insertatend(head,4);
    insertatend(head,5);

    // Create cycle at node 3
    createCycle(head,3);

    listnode* ans=detectCycle(head);

    if(ans!=NULL)
        cout<<"Cycle starts at node : "<<ans->val<<endl;
    else
        cout<<"No Cycle"<<endl;

    return 0;
}       