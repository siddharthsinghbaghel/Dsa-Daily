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

ListNode* findMiddle(ListNode* head)
{
    // slow moves 1 step
    ListNode* slow = head;

    // fast moves 2 steps
    ListNode* fast = head->next;

    while(fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }

    // slow points to node before middle split
    return slow;
}

ListNode* merge(ListNode* left, ListNode* right)
{
    // Dummy node simplifies merging
    ListNode* dummy = new ListNode(-1);

    // Current pointer
    ListNode* temp = dummy;

    while(left != NULL && right != NULL)
    {
        // Smaller value comes first
        if(left->val < right->val)
        {
            temp->next = left;
            left = left->next;
        }
        else
        {
            temp->next = right;
            right = right->next;
        }

        temp = temp->next;
    }

    // Attach remaining nodes
    if(left != NULL)
        temp->next = left;

    if(right != NULL)
        temp->next = right;

    return dummy->next;
}

//---------------------------------------------------------
// Merge Sort
//---------------------------------------------------------
ListNode* sortList(ListNode* head)
{
    //-----------------------------------------------------
    // Base Case
    //-----------------------------------------------------
    // Empty list or one node is already sorted
    if(head == NULL || head->next == NULL)
        return head;

    //-----------------------------------------------------
    // Find Middle
    //-----------------------------------------------------
    ListNode* mid = findMiddle(head);

    //-----------------------------------------------------
    // Split List into two halves
    //-----------------------------------------------------
    ListNode* rightHead = mid->next;

    mid->next = NULL;

    //-----------------------------------------------------
    // Sort Left Half
    //-----------------------------------------------------
    ListNode* left = sortList(head);

    //-----------------------------------------------------
    // Sort Right Half
    //-----------------------------------------------------
    ListNode* right = sortList(rightHead);

    //-----------------------------------------------------
    // Merge both sorted halves
    //-----------------------------------------------------
    return merge(left,right);
}


int main()
{
    ListNode* head = NULL;

    insertAtEnd(head,4);
    insertAtEnd(head,2);
    insertAtEnd(head,1);
    insertAtEnd(head,3);
    insertAtEnd(head,5);

    cout<<"Original List : ";
    printList(head);

    head = sortList(head);

    cout<<"Sorted List : ";
    printList(head);

    return 0;
}




Explanation 


Dry Run

Suppose

4 → 2 → 1 → 3
Step 1

Find middle

4 → 2 | 1 → 3

Split

Left

4 → 2

Right

1 → 3
Step 2

Sort Left

4 → 2

Split again

4

2

Merge

2 → 4
Step 3

Sort Right

1 → 3

Split

1

3

Merge

1 → 3
Step 4

Merge both

Left

2 → 4

Right

1 → 3

Compare

2 vs 1

Take 1
1

Compare

2 vs 3

Take 2
1 → 2

Compare

4 vs 3

Take 3
1 → 2 → 3

Remaining

4

Final

1 → 2 → 3 → 4
Recursion Tree
                4 2 1 3

             /          \

          4 2          1 3

         /   \        /   \

        4     2      1     3

         \   /        \   /

         2 4          1 3

              \      /

             1 2 3 4
Why fast = head->next?

Many students ask this.

Suppose

1 → 2

If you write

fast = head;

then slow ends at node 2, leaving:

1 → 2

Left : 1 → 2
Right : NULL

The list is never properly split, causing infinite recursion.

Instead, using

fast = head->next;

makes slow stop at the first node:

1 | 2

Now the list splits correctly into two halves.

