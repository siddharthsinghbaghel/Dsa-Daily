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


ListNode* oddEvenList(ListNode* head)
{
    // Empty list or only one node
    if(head == NULL || head->next == NULL)
        return head;

    //------------------------------------------------------
    // odd points to first node
    //------------------------------------------------------
    ListNode* odd = head;

    //------------------------------------------------------
    // even points to second node
    //------------------------------------------------------
    ListNode* even = head->next;

    //------------------------------------------------------
    // Save head of even list
    //------------------------------------------------------
    ListNode* evenHead = even;

    //------------------------------------------------------
    // Rearrange pointers
    //------------------------------------------------------
    while(even != NULL && even->next != NULL)
    {
        // Connect odd node to next odd node
        odd->next = even->next;

        // Move odd pointer
        odd = odd->next;

        // Connect even node to next even node
        even->next = odd->next;

        // Move even pointer
        even = even->next;
    }

    //------------------------------------------------------
    // Attach even list after odd list
    //------------------------------------------------------
    odd->next = evenHead;

    return head;
}

int main()
{
    ListNode* head = NULL;z

    insertAtEnd(head,1);
    insertAtEnd(head,2);
    insertAtEnd(head,3);
    insertAtEnd(head,4);
    insertAtEnd(head,5);

    cout << "Original List : ";
    printList(head);

    head = oddEvenList(head);

    cout << "After Rearranging : ";
    printList(head);

    return 0;
}