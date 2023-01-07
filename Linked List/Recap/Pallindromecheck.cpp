#include<iostream>
using namespace std;

class node{
public:
    int data;
    node* nextnode;

    node(int data){
        this->data = data;
        this->nextnode = NULL;
    }
};

void insertAtHead(int data, node* &head){
     node* n = new node(data);
     n->nextnode = head;
     head = n;
}

node* getmidpoint(node* head){
    if(head==NULL){
        return head;
    }

     node* slow = head;
     node* fast = head->nextnode;

     while(fast != NULL && fast->nextnode != NULL){
        slow = slow->nextnode;
        fast = fast->nextnode->nextnode;
     }

     return slow;
}

node* reverse(node* head){

     node* curr = head;
     node* prev = NULL;

     while(curr != NULL){
        // store the nextnode of current in 'NEXT' node.
        node* next = curr->nextnode;
        // nextnode of curr is rn pointing to next. to reverse we gotta change it to prev.
        curr->nextnode = prev;
        // prev becomes curr.
        prev = curr;
        // curr becomes next.
        curr = next;
     }

     return prev;
}

bool isPalindrome(node* head){
	node* head1 = head;
    node* midpoint = getmidpoint(head);
    node* head2 = midpoint->nextnode;

    node* newhead2 = reverse(head2);

    while(newhead2!=NULL){
        if(head1->data != newhead2->data){
            return false;
        }

        head1 = head1->nextnode;
        newhead2 = newhead2->nextnode;
    }
        return true;
}

// bool isPalindrome(node* head) {
//     node* head1 = head;
//     if(!head1 || !head1->nextnode) {
//         return true;
//     }

//     node* midPoint = getmidpoint(head1);
//     node* head2 = reverse(midPoint->nextnode);
//     midPoint->nextnode = NULL;

//     while(head2 != NULL) {
//         if(head1->data != head2->data) {
//             return false;
//         }
//         head1 = head1->nextnode;
//         head2 = head2->nextnode;
//     }

//     return true;

// }

int main(){

    node* head = NULL;
    insertAtHead(20,head);
    insertAtHead(20,head);
    insertAtHead(10,head);
    insertAtHead(20,head);
    insertAtHead(30,head);

    isPalindrome(head) ? cout << "TRUE" : cout << "FALSE";

    return 0;
}