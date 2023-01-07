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

void print(node* head) {
	while(head != NULL) {
		cout << head->data;
		head = head->nextnode;
		if(head != NULL) cout << "->";
	}
	cout << endl;
}

node* reverseIterative(node* head) {

	node* cur = head;
	node* prev= NULL;

	while(cur != NULL) {
		node* temp = cur->nextnode;
		cur->nextnode = prev;
		prev = cur;
		cur = temp;
	}

	return prev;
}


// node* reverseIterative(node* head){

// 	 node* curr = head;
// 	 node* prev = NULL;

// 	 while(curr != NULL){
// 	 	// store the nextnode of current in 'NEXT' node.
// 	 	node* next = curr->nextnode;
// 	 	// nextnode of curr is rn pointing to next. to reverse we gotta change it to prev.
// 	 	curr->nextnode = prev;
// 	 	// prev becomes curr.
// 	 	prev = curr;
// 	 	// curr becomes next.
// 	 	curr = next;
// 	 }

// 	 return prev;
// }

// void reverseRecursive(node* head){
// 	 // base case


// 	 // recursive case
//      node* newhead = reverseRecursive(head->nextnode);
//      head->nextnode->nextnode = head;
     
// }

int main(){
	node* head = NULL;
	insertAtHead(50, head);
	insertAtHead(40, head);
	insertAtHead(30, head);
	insertAtHead(20, head);
	node* newhead = reverseIterative(head);
	print(newhead);
	return 0;
}