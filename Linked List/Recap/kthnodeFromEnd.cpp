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

node* KthFromEnd(node* head, int k){
	if(head==NULL){
		return head;
	}

	 node* slow = head;
	 node* fast = head;
	 int i=0;
	 while(i<k and fast){
          fast = fast->nextnode;
          i++;
	 }

	 while(fast){
	 	slow = slow->nextnode;
	 	fast = fast->nextnode;
	 }

	 return slow;
}

int main(){
    node* head = NULL;
	insertAtHead(50, head);
	insertAtHead(40, head);
	insertAtHead(30, head);
	insertAtHead(20, head);
    node* n = KthFromEnd(head, 2);
    n ? cout << n->data : cout << "NULL";


	return 0;
}