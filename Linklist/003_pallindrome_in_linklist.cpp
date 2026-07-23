#include<iostream>
using namespace std;

class listnode{
    int val;
    listnode* next;

    listnode(int data){
        val = data;
        next = NULL;
    }
};

void insertatend(listnode*&head , int value){

    listnode * newnode = new listnode(value);

    if(head == NULL){
        head = newnode;
        return;
    }

    listnode*temp = head;

    while(temp->next != NULL){
        temp = temp->next;
    }
    temp->next = newnode;
}

void printlist(listnode * head){

    while(head !=NULL){
        cout<<head->val<<" ";
        head = head->next;
    }
    cout<<endl;
}

listnode*reversell(listnode* start){
    listnode*prev = NULL:
    listnode*curr = start;
    listnode*next = NULL;

    while(curr != NULL){
        listnode* frwd= curr->next;
        curr->next = prev;
        prev = curr;
        curr = frwd;
    }
    return prev;
}

bool ispallindrome(listnode*head){

    listnode*slow = head;
    listnode*fast = head;

    while(fast != NULL && fast->next != NULL){
        slow = slow->next;
        fast = fast->next->next;
    }

    listnode*reversehalf = reversell(slow);

    while(reversehalf){
        if(head->val != reversehalf->val)
            return false;
        head = head->next;
        reversehalf = reversehalf->next;
        
    }
    return true;
}

int main(){
    listnode*head = NULL;

    insertatend(head, 1);
    insertatend(head, 2);
    insertatend(head, 3);
    insertatend(head, 2);
    insertatend(head, 1);

    cout<<"The linked list is: ";
    printlist(head);

    if(ispallindrome(head)){
        cout<<"The linked list is a palindrome."<<endl;
    }
    else{
        cout<<"The linked list is not a palindrome."<<endl;
    }
    return 0;
}