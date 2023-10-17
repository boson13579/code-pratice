#include<stdio.h>
#include<stdlib.h>
#include<iostream>

/* 二元搜尋樹 */
using namespace std;
struct tree
{
    int data;
    struct tree *left;
    struct tree *right;
};
typedef struct tree treenode;
typedef treenode *btree;

btree create_btree(int*, int);
btree insert_node(btree, int);
void print_btree(btree);
void postOrder(btree);

int main()
{
    btree root = NULL;
    int data[10] = {5,6,4,8,2,3,7,1,9,12};
    root = create_btree(data,10);
    cout<<"樹的節點內容\n"<<endl;
    print_btree(root);

    cout<<endl;
    cout<< "PostOrder Traversal:"<<endl;
    postOrder(root);
    cout<<endl;
    system("PAUSE");
    return 0;
}

btree create_btree(int *data,int len)
{
    btree root=NULL;
    int i;

    for(i=0;i<len;i++)
        root=insert_node(root,data[i]);
    return root;
}

btree insert_node(btree root,int value)
{
    btree newnode;
    btree current;
    btree back;
    //建立新節點記憶體
    newnode=(btree) malloc(sizeof(treenode));
    newnode->data=value;
    newnode->left=NULL;
    newnode->right=NULL;
    if(root==NULL)
    {
        return newnode;
    }
    else
    {
        current=root;
        while(current!=NULL)
        {
            back=current;
            if(current->data<value)
                current=current->right;
            else
                current=current->left;
        }
        if(back->data<value)
            back->right=newnode;
        else
            back->left=newnode;
    }
    return root;
}

void print_btree(btree root)
{
    btree ptr;
    ptr=root->left;
    printf("列印左子樹:\n");
    while(ptr!=NULL)
    {
        printf("[%2d]\n",ptr->data);
        ptr=ptr->left;
    }
    ptr=root->right;
    printf("列印右子樹:\n");
    while(ptr!=NULL)
    {
        printf("[%2d]\n",ptr->data);
        ptr=ptr->right;
    }
}

void postOrder(btree root)
{
    //recursive
	if(root != NULL){
		postOrder(root -> left);
		postOrder(root -> right);
		cout<<root -> data<<" ";
	}
}