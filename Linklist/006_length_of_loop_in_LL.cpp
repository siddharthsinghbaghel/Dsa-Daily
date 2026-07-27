#include<iostream>
using namespace std;

class ListNode
{
public:
    int val;
    ListNode* next;

    // Constructor
    ListNode(int data)
    {
        val = data;
        next = NULL;
    }
};

void insertAtEnd(ListNode* &head, int value)
{
    ListNode* newNode = new ListNode(value);

    if(head == NULL)
    {
        head = newNode;
        return;
    }

    ListNode* temp = head;

    while(temp->next != NULL)
    {
        temp = temp->next;
    }

    temp->next = newNode;
}

void createCycle(ListNode* head, int position)
{
    if(position == 0)
        return;

    ListNode* cycleNode = NULL;
    ListNode* temp = head;

    int count = 1;

    while(temp->next != NULL)
    {
        if(count == position)
            cycleNode = temp;

        temp = temp->next;
        count++;
    }

    // Connect last node to desired node
    temp->next = cycleNode;
}

int findlength(ListNode* slow, ListNode* fast)
{
    int count = 1;
    fast = fast->next;
    while(slow != fast)
    {
        fast = fast->next;
        count++;
    }
    return count;
}
int lengthOfLoop(ListNode* head)
{
    if(head == NULL)
        return 0;

    ListNode* slow = head;
    ListNode* fast = head;

    while(fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;

        if(slow == fast)
        {
            return findlength(slow, fast);
        }
    }

    return 0; // No loop found
}

int main()
{
    ListNode* head = NULL;

    insertAtEnd(head,1);
    insertAtEnd(head,2);
    insertAtEnd(head,3);
    insertAtEnd(head,4);
    insertAtEnd(head,5);
    insertAtEnd(head,6);

    // Create cycle at node 3
    createCycle(head,3);

    int length = lengthOfLoop(head);

    if(length == 0)
        cout<<"No Cycle"<<endl;
    else
        cout<<"Length of Loop = "<<length<<endl;

    return 0;
}
