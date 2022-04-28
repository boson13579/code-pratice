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
Node *deletenode(Node *first , int data);

int main () {

	Node *first;
	int arr[] = {12,43,56,34,98,76,43,24};
	first = createList(arr,8);
	printList(first);
	first = deletenode(first , 12);
	first = deletenode(first , 34);
	first = deletenode(first , 24);
	//first = deletenode(first , 1231231);
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
Node *deletenode(Node *first , int data){
	bool finddata = false;
	Node *previous  = first, *current = first -> next;
	Node *temp = first;
	if(previous -> data == data)
		return previous -> next;
	while(current != NULL){
		if(current -> data == data){
			finddata = true;
			break;
		}
		previous = current;
		current = previous -> next;
	}
	if(finddata)
		previous -> next = current -> next;
	else
		cout<<"can't find " << data << " in linked list\n";
	return temp;
};
