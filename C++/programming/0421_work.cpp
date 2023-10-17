#include <bits/stdc++.h>
using namespace std;

struct node{
	int data;
	struct node *next;	
};
typedef struct node Node;

Node *createList(int *,int);
void printList(Node *);
void freeList(Node *);
Node *insert(Node *first , int data);

int main () {

	Node *first;
	int arr[] = {14,27,32,46};
	first = createList(arr,4);
	int data = 36;
	printList(first);
	first = insert(first,data);
	printList(first);
	freeList(first);
	system("pause");

	return 0;
}

Node *createList(int *arr,int len){
	int i;
	Node *first,*current,*previous;
	for(i=0 ; i<len ; i++){
		current=(Node *)malloc(sizeof(Node));
		current -> data = arr[i];
		if(i==0)
			first=current;
		else
			previous -> next = current;
		current -> next = NULL;
		previous = current;
	}
	return first;
}

void printList(Node *first){
	Node *node=first;
	if(first==NULL){
		printf("List is empty\n");
	}
	else{
		while(node!=NULL){
			cout << node -> data << " ";
			node = node -> next;
		}
		cout<<endl;
	}
}

void freeList(Node *first){
	Node *ptr,*temp;
	ptr=first;
	while(ptr!=NULL){
		temp=ptr;
		ptr=ptr->next;
		free(temp);
	}
}

Node *insert(Node *first , int data){
	Node *previous , *current;
	Node *newnode = (Node *)malloc(sizeof(Node));
	newnode -> data= data;
	Node *temp = first;
	previous = first;
	if(previous -> data > data){
		newnode -> next = previous;
		return newnode;
	}
	current = previous -> next;
	while(current != NULL and current -> data < data){
		previous = current;
		current = previous -> next;
		}
	previous -> next = newnode;
	newnode -> next = current;
	return temp;
	}

