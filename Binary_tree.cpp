//Insertion,Deletion,Searching and Traversal in Binary Search Tree (BST)

#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
using namespace std;

typedef struct node
{
	int info;
	struct node *left;
	struct node *right;
}NODE;

NODE *root=NULL,*temp=NULL,*cur=NULL,*par=NULL,*parsuc=NULL,*suc=NULL;
int value;

NODE* make_node()
{
	cur=(NODE*)malloc(sizeof(NODE));
	printf("Enter the element to be insert: ");
	scanf("%d",&value);
	cur->info=value;
	cur->left=NULL;
	cur->right=NULL;
	return cur;
}

NODE* Insert_BST(NODE*);
void Search_BST(NODE*);
void Preorder(NODE*);
void Inorder(NODE*);
void Postorder(NODE*);
NODE* Delete_BST(NODE*);

int main()
{
	int ch;
	printf("*****Binary Search Tree Operations*****\n");
	printf("1. Insert a node\n");
	printf("2. Searching a node\n");
	printf("3. Preorder Traversal\n");
	printf("4. Inorder Traversal\n");
	printf("5. Postorder Traversal\n");
	printf("6. Delete a node\n");
	printf("7. Exit\n");
	do{
	printf("\nEnter Your Choice: ");
	scanf("%d",&ch);
	
	switch(ch)
	{
		case 1: root = Insert_BST(root);
		        break;
		case 2: Search_BST(root);
		        break;
		case 3: Preorder(root);
		        printf("\n");
		        break;
		case 4: Inorder(root);
		        printf("\n");
		        break;
		case 5: Postorder(root);
		        printf("\n");
		        break;
		case 6: root = Delete_BST(root);
    	        break;
		case 7: printf("Thanks For Using This Amazing Program!!\n");
		        exit(0);
		        break;
		default: break;												               				       
	}
    }while(1);
    getch();
}

NODE* Insert_BST(NODE *root)
{
	cur=make_node();
	if(root == NULL)
	    root=cur;
	else
	{
	    temp=root;
	    while(temp!=NULL)
	    {
	   	  par=temp;
	   	  if(cur->info < temp->info)
	   	     temp=temp->left;
	   	  else
			 temp=temp->right;   
	    }
	    if(cur->info < par->info)
	      par->left=cur;
		else
		  par->right=cur;
	}
	return root;	       
}

void Search_BST(NODE *root)
{
	int skey;
	printf("Enter the node you want to search: ");
	scanf("%d",&skey);
	temp=root;
	if(temp == NULL)
	   printf("Node is not Found\n");
	else
	{
	   while(temp->info!=skey)
	   {
	   	  par=temp;
	      if(skey < temp->info)
		     temp=temp->left;
		  else
		     temp=temp->right;	 	
	   }
	   if(temp->info == skey)
	       {
		   printf("Node is Found\n");
		   printf("%d is parent of that Node\n",par->info);
	       }
	   else
	       printf("Node is not Found\n");
	}
}

void Preorder(NODE *root)
{
	if(root==NULL)
	   return;
	else
	{
	   printf("%d ",root->info);
	   Preorder(root->left);
	   Preorder(root->right);
    }
}

void Inorder(NODE *root)
{
	if(root==NULL)
	   return;
	else
	{
	   Inorder(root->left);
	   printf("%d ",root->info);
	   Inorder(root->right);
    }
}

void Postorder(NODE *root)
{
	if(root==NULL)
	   return;
	else
	{
	   Postorder(root->left);
	   Postorder(root->right);
	   printf("%d ",root->info);
    }
}

NODE* Delete_BST(NODE *root)
{
	int skey;
	printf("Enter the node you want to delete: ");
	scanf("%d",&skey);
	temp=root;
	if(temp == NULL)
	  {
	   printf("Node is not exist\n");	
      }
	else
	{
	   while(temp->info!=skey)
	   {
	   	  par=temp;
	      if(skey < temp->info)
		     temp=temp->left;
		  else
		     temp=temp->right;	 	
	   }
	   if(temp->info == skey)
	       {
	       	  //case 1: no child
		      if(temp->left==NULL && temp->right==NULL)
		      {
		      	if (par->left->info == skey)
		      	    par->left=NULL;
		      	else
				    par->right=NULL;  
			  }
			  
			  //case 2: one right child
			  if(temp->left==NULL && temp->right!=NULL)
			  {
			  	if (par->left->info == skey)
			  	    par->left=temp->right;
			  	else
				    par->right=temp->right;    
			  }
			  
			  //case 3: one left child
			  if(temp->left!=NULL && temp->right==NULL)
			  {
			  	if (par->left->info == skey)
			  	    par->left=temp->left;
			  	else
				    par->right=temp->left;
			  }
			  
			  //case 4: two both left or right child
			  if(temp->left!=NULL && temp->right!=NULL)
			  {
			  	parsuc=temp;
			  	suc=temp->right;
			  	while(suc->left!=NULL)
			  	{
			  	  parsuc=suc;
			  	  suc=suc->left;						
				}
				suc->left=temp->left;
				temp->left=temp->right=NULL;
				par->right=suc;
			  }
	       }
	   else
	       printf("Node is not exist\n");
	}
	return root;
}











