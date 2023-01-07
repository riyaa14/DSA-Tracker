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
	 	  if(head != NULL) cout << "->"; 
	 }
}

node* getNode(node* head, int i){
	for(int j=0; j<i and head != NULL; j++){
		head = head->nextnode;
	}
	return head;
}

void insertAtIndex(node* head, int i, int data){
	// 1. get the i-1th node
	node* prev = getNode(head, i-1);

     if(prev == NULL){
        // idx i exceeds the length of linked list.
        cout << "index exceeds length of linked list.";
        return;	
     }

	// 2. create a new node which is to be inserted
	node* n = new node(data);
	// 3. the address stored in nextnode of prev (which has address to the ith node) has to be stored in nextnode of the new node.
	n->nextnode = prev->nextnode;
	// 4. the nextnode of prev would now contain the address of new node.
	prev->nextnode = n;
}

int main(){
         node* head = NULL;
         insertAtHead(head, 40);
         insertAtHead(head, 30);
         insertAtHead(head, 10);
         insertAtIndex(head, 1, 20);
         printList(head);

	return 0;
}
