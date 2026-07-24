#include<iostream>
using namespace std;

class listnode{
    int val;
    listnode * next;

    listnode(int data){
        val = data;
        next = NULL;
    }
};

void insertatend(listnode*&head, int value){
    listnode * newnode = new listnode(value);

    if(head == NULL){
        head = newnode;
        return;
    }

    listnode*temp = head;
    while(temp->next !=NULL){
        temp = temp->next;
    }
    temp->next = newnode;

}
void printlist(listnode*head){
    listnode*temp = head;
    while(temp != NULL){
        cout<<temp->val<<" ";
        temp = temp->next;
    }
    cout<<endl;
}

//----------------------------------------------------
// Create a cycle for testing
//
// Example:
// 1 -> 2 -> 3 -> 4 -> 5
//           ^         |
//           |_________|
//
// position = 3 means last node points to node 3.
//----------------------------------------------------

void createcycle(listnode*head, int position){
    if(position == 0)
        return;

        listnode*cycleNode = NULL;
        listnode*temp = head;

        int count = 1;

        while(temp->next != NULL){
            if(count == position){
                cycleNode = temp;
            }
            temp = temp->next;
            count++;
        }
        if(cycleNode != NULL){
            // connect last node to the cycleNode
            temp->next = cycleNode;
        }
}

bool hascycle(listnode*head){
    if(!head || !head->next)
        return false;

    listnode*slow = head;
    listnode*fast = head;

    while(fast && fast->next){
        slow = slow->next;
        fast = fast->next->next;

        if(slow == fast)
            return true;
    }

    return false;
}

int main()
{
    ListNode* head = NULL;

    insertAtEnd(head,1);
    insertAtEnd(head,2);
    insertAtEnd(head,3);
    insertAtEnd(head,4);
    insertAtEnd(head,5);

    // Create cycle
    createCycle(head,3);

    if(hasCycle(head))
        cout<<"Cycle Detected"<<endl;
    else
        cout<<"No Cycle"<<endl;

    return 0;
}