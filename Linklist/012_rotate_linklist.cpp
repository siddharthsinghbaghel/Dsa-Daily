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
    // Create a new node
    ListNode* newNode = new ListNode(value);

    // If list is empty
    if(head == NULL)
    {
        head = newNode;
        return;
    }

    // Traverse to the last node
    ListNode* temp = head;

    while(temp->next != NULL)
    {
        temp = temp->next;
    }

    // Attach new node
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

//---------------------------------------------------------
// Rotate Linked List to the Right
//---------------------------------------------------------
ListNode* rotateRight(ListNode* head, int k)
{
    //-----------------------------------------------------
    // Edge cases
    //-----------------------------------------------------
    // If list is empty
    // OR list has only one node
    // OR k is 0
    if(head == NULL || head->next == NULL || k == 0)
        return head;

    //-----------------------------------------------------
    // Step 1: Find the length of the linked list
    //-----------------------------------------------------
    int length = 1;

    ListNode* tail = head;

    while(tail->next != NULL)
    {
        tail = tail->next;
        length++;
    }

    //-----------------------------------------------------
    // Step 2: Reduce k
    //
    // Example:
    //
    // List length = 5
    // k = 12
    //
    // Rotating 12 times is same as rotating
    // 12 % 5 = 2 times.
    //-----------------------------------------------------
    k = k % length;

    // If k becomes 0, no rotation is required
    if(k == 0)
        return head;

    //-----------------------------------------------------
    // Step 3: Make the linked list circular
    //
    // Before:
    //
    // 1 → 2 → 3 → 4 → 5 → NULL
    //
    // After:
    //
    // 1 → 2 → 3 → 4 → 5
    // ↑               ↓
    // └───────────────┘
    //-----------------------------------------------------
    tail->next = head;

    //-----------------------------------------------------
    // Step 4: Find the new tail
    //
    // New tail will be at:
    //
    // length - k - 1
    //
    // from the head.
    //-----------------------------------------------------
    int stepsToNewTail = length - k - 1;

    ListNode* newTail = head;

    for(int i = 0; i < stepsToNewTail; i++)
    {
        newTail = newTail->next;
    }

    //-----------------------------------------------------
    // Step 5: New head is the node after new tail
    //-----------------------------------------------------
    ListNode* newHead = newTail->next;

    //-----------------------------------------------------
    // Step 6: Break the circular list
    //-----------------------------------------------------
    newTail->next = NULL;

    //-----------------------------------------------------
    // Return new head
    //-----------------------------------------------------
    return newHead;
}


int main()
{
    ListNode* head = NULL;

    insertAtEnd(head,1);
    insertAtEnd(head,2);
    insertAtEnd(head,3);
    insertAtEnd(head,4);
    insertAtEnd(head,5);

    cout << "Original List : ";
    printList(head);

    int k = 2;

    head = rotateRight(head, k);

    cout << "After Rotation : ";
    printList(head);

    return 0;
}