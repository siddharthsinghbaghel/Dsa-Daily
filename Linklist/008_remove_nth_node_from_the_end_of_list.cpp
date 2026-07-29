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

void printList(ListNode* head)
{
    while(head != NULL)
    {
        cout << head->val << " ";
        head = head->next;
    }

    cout << endl;
}


//------------------------------------------------------
// Remove Nth Node From End
//------------------------------------------------------
ListNode* removeNthFromEnd(ListNode* head, int n)
{
    // Empty List
    if(head == NULL)
        return NULL;

    ListNode* fast = head;
    ListNode* slow = head;

    //--------------------------------------------------
    // Move fast pointer n steps ahead
    //--------------------------------------------------
    for(int i = 0; i < n; i++)
    {
        fast = fast->next;
    }

    //--------------------------------------------------
    // If fast becomes NULL,
    // delete the first node
    //--------------------------------------------------
    if(fast == NULL)
    {
        ListNode* temp = head;
        head = head->next;
        delete temp;

        return head;
    }

    //--------------------------------------------------
    // Move both pointers
    //--------------------------------------------------
    while(fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next;
    }

    //--------------------------------------------------
    // Delete nth node from end
    //--------------------------------------------------
    ListNode* nodeToDelete = slow->next;

    slow->next = slow->next->next;

    delete nodeToDelete;

    return head;
}

int main()
{
    ListNode* head = NULL;

    insertAtEnd(head,1);
    insertAtEnd(head,2);
    insertAtEnd(head,3);
    insertAtEnd(head,4);
    insertAtEnd(head,5);

    cout<<"Original List : ";
    printList(head);

    head = removeNthFromEnd(head,2);

    cout<<"After Deletion : ";
    printList(head);

    return 0;
}