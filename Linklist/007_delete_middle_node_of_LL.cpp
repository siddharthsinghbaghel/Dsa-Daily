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

ListNode* deleteMiddle(ListNode* head)
{
    // If list is empty
    if(head == NULL)
        return NULL;

    // If only one node exists
    if(head->next == NULL)
    {
        delete head;
        return NULL;
    }

    // Previous pointer
    ListNode* prev = NULL;

    // Slow pointer
    ListNode* slow = head;

    // Fast pointer
    ListNode* fast = head;

    // Find middle node
    while(fast != NULL && fast->next != NULL)
    {
        prev = slow;
        slow = slow->next;
        fast = fast->next->next;
    }

    // Remove middle node
    prev->next = slow->next;

    // Free memory
    delete slow;

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

    head = deleteMiddle(head);

    cout<<"After Deleting Middle : ";
    printList(head);

    return 0;
}