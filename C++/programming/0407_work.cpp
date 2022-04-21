#include <bits/stdc++.h>
using namespace std;

struct node{
	int data;
	struct node *next;	
};
typedef struct node Node;
Node *add(Node *,Node *);

int main () {

	Node a,b,c;
	Node *ptr = &a;

	a.data = 12;
	a.next = &b;
	b.data = 30;
	b.next = &c;
	c.data = 64;
	c.next = NULL;

	while(ptr != NULL){
		cout<<"address = "<<ptr<<" ";
		cout<<"data = "<<ptr -> data<<" ";
		cout<<"next = "<<ptr -> next<<endl;
		ptr = ptr -> next; 
	} 

	cout<<endl;

	Node d;
	d.data = 24;
	d.next = NULL;
	ptr = add(&a , &d);

	while(ptr != NULL){
		cout<<"address = "<<ptr<<" ";
		cout<<"data = "<<ptr -> data<<" ";
		cout<<"next = "<<ptr -> next<<endl;
		ptr = ptr -> next; 
	} 

	return 0;
}
Node* add(Node *ptr ,Node *d){

	Node *temp = ptr;

	while(ptr -> next != NULL)
		ptr = ptr -> next;
	ptr -> next = d;

	return temp;
}
