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

node* midpoint(node* head){
	if(head==NULL){
		return head;
	}

	 node* slow = head;
	 node* fast = head->nextnode;

	 while(fast->nextnode){
	 	slow = slow->nextnode;
	 	fast = fast->nextnode->nextnode;
	 }

	 return slow;
}

int main(){
    node* head = NULL;
	insertAtHead(50, head);
	insertAtHead(40, head);
	insertAtHead(30, head);
	insertAtHead(20, head);
    node* n = midpoint(head);
    n ? cout << n->data : cout << "NULL";


	return 0;
}