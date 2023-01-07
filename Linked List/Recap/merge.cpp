// merge 2 SORTED linked lists.

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


node* merge(node* &head1, node* &head2){
    node* head = NULL;
    // base case
     if(head1==NULL){
        return head2;
     }

     if(head2==NULL){
        return head1;
     }

     // recursive case
     if(head1->data > head2->data){
        head = head2;
        head->nextnode = merge(head1, head2->nextnode); 
     }else{

     head = head1;
     head->nextnode = merge(head1->nextnode, head2);
     }

     return head;
}

void printLinkedList(node* head){
    if(head==NULL){
        return;
    }

    while(head){
        cout << head->data;
        if(head->nextnode){
            cout << "->";
        }
        head = head->nextnode;
    }
}


int main(){

    node* head1 = NULL;
    insertAtHead(70,head1);
    insertAtHead(50,head1);
    insertAtHead(30,head1);
    insertAtHead(10,head1);
    printLinkedList(head1);
    cout << endl;

     node* head2 = NULL;
    insertAtHead(60,head2);
    insertAtHead(40,head2);
    insertAtHead(20,head2);
    printLinkedList(head2);
    cout << endl;

    node* head = NULL;
    head = merge(head1, head2);
    printLinkedList(head);
    cout << endl;

    return 0;
}