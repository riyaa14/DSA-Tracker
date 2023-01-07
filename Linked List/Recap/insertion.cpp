#include<iostream>
using namespace std;

class node{
public:
     
     int data;
     node* nextnode;

     // parameterized constructor
     node(int data){
     	this-> data = data;
     	this-> nextnode = NULL; // We dont know what next of the node will point to.
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
         printList(head);

	return 0;
}
