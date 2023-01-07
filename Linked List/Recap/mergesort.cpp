// MERGE SORT
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
	// 1. create a new node
	node* n = new node(data);
	// 2. nextnode of the new node stores the address of prev head
	n->nextnode = head;
	// 3. make node n the new head
	head = n;
}

node* getmidpoint(node* head){
	if(head==NULL){
		return head;
	}

	 node* slow = head;
	 node* fast = head->nextnode;

	 while(fast != NULL and fast->nextnode != NULL){
	 	slow = slow->nextnode;
	 	fast = fast->nextnode->nextnode;
	 }

	 return slow;
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

node* mergesort(node* head){
	// base case
	if(head==NULL or head->nextnode==NULL){
		return head;
	}

	// 1. get midpoint and split into 2
	node* midpoint = getmidpoint(head);
	node* head2 = midpoint->nextnode;
	midpoint->nextnode = NULL;

	// 2. sort the 2 newly created lists
	head = mergesort(head);
	head2 = mergesort(head2);

	// 3. merge these 2
	return merge(head, head2);
}

int main(){
	node* head = NULL;
	insertAtHead(70, head);
	insertAtHead(20, head);
	insertAtHead(30, head);
	insertAtHead(50, head);
	insertAtHead(40, head);
	insertAtHead(10, head);
	insertAtHead(60, head);
	printLinkedList(head);
	cout << endl;

	head = mergesort(head);
	printLinkedList(head);
	return 0;
}