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

void printList(ListNode* head)
{
    while(head != NULL)
    {
        cout << head->val << " ";
        head = head->next;
    }

    cout << endl;
}

ListNode * getIntersectionNode(ListNode *headA, ListNode *headB) {
    if(headA == NULL || headB == NULL)
        return NULL;

    ListNode* a = headA;
    ListNode* b = headB;

    while(a != b)
    {
        a = (a == NULL) ? headB : a->next;
        b = (b == NULL) ? headA : b->next;
    }

    return a; // or return b; both are same
}

// driver code
int main()
{
    ListNode* headA = new ListNode(4);
    headA->next = new ListNode(1);
    headA->next->next = new ListNode(8);
    headA->next->next->next = new ListNode(4);
    headA->next->next->next->next = new ListNode(5);

    ListNode* headB = new ListNode(5);
    headB->next = new ListNode(0);
    headB->next->next = new ListNode(1);
    headB->next->next->next = headA->next->next; // Intersection at node with value 8

    cout << "List A: ";
    printList(headA);

    cout << "List B: ";
    printList(headB);

    ListNode* intersection = getIntersectionNode(headA, headB);

    if(intersection != NULL)
        cout << "Intersection at node with value: " << intersection->val << endl;
    else
        cout << "No intersection." << endl;

    return 0;
}