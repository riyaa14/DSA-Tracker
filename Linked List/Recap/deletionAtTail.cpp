#include<iostream>
using namespace std;

class node{
public:
     
     int data;
     node* nextnode;

     // parameterized constructor
     node(int data){
     	this-> data = data;
     	this-> nextnode = NULL; // We don't know what next of the node will point to.
     	                    // So let it be null, we'll change/set it as per the situation.
     }
};

void insertAtHead(node* &head, int data){
	 // 1. create a new node
	 node* n = new node(data);
	 // 2. next of this node must point to the prev head
	 n->nextnode = head;
	 // 3. make this node the head node.
	 head = n;
}

void deleteAtHead(node* &head){
	// 1. store address of the node to be deleted in a pointer to node.
	node* toBeDeleted = head;
	// 2. the next node becomes head.
	head = head->nextnode;
	// 3. delete the node to be deleted.
	delete toBeDeleted;
}

void deleteAtTail(node* head){
     // corner cases
     if(head==NULL){
     	return;
     }
     if(head->nextnode==NULL){
     	deleteAtHead(head);
     	return;
     }

	// 1. store address of tail node and the prev one in a ptr to node.
	node* tail = head;
	node* prev = NULL;
	while(tail->next != NULL){
		prev = tail;
		tail = tail->nextnode;
	}
	// 2. make nextnode of prev NULL.
	prev->nextnode = NULL;
	// 3. delete tail node.
	delete tail;
}

void printList(node* head){

	 while(head){
	 	  cout << head->data;
	 	  head = head->nextnode;
	 	  if(head!= NULL) cout << "->"; 
	 }
}

int main(){
         node* head = NULL;
         insertAtHead(head, 30);
         insertAtHead(head, 20);
         insertAtHead(head, 10);
         deleteAtTail(head);
         printList(head);

	return 0;
}
