/*
Name:Shardul Pathak
Roll no:222021
Gr No:17u666
Batch:B1
*/

#include<iostream>
using namespace std;

class TBTree
{
  public:
	int data;
	int lthread,rthread;
	TBTree *left,*right;
	void assign();
  void maketree(TBTree *,TBTree *);
  void inorder(TBTree *); 
  void menu(); 	
}*root,*head;

void TBTree::assign()
{
  TBTree *newnode; 
  newnode=new TBTree;
  newnode->lthread=newnode->rthread=1;
  newnode->left=newnode->right=head;
  cout<<"Enter data"<<endl;
  cin>>newnode->data;
  
  if(root==NULL)
  {
    root=newnode;
    head=new TBTree;
    head->data=999;
    head->lthread=head->rthread=1;
    head->left=root;
    head->right=head;
    root->left=head;
	root->right=head;
  }
  
  else
  maketree(root,newnode); 
}

void TBTree::maketree(TBTree *temp,TBTree *newtemp)
{
  if(newtemp->data<temp->data)
  {
	  while((temp->left!=head)&&(newtemp->data<temp->data))
				temp=temp->left;
				if(newtemp->data<temp->data)
				{
				  newtemp->left=temp->left;
 				  newtemp->lthread=temp->lthread;
				  temp->left=newtemp;
				  newtemp->right=temp;
				  newtemp->rthread=1;
				  temp->lthread=0;
				}  
				else
				{
				  newtemp->right=temp->right;
				  newtemp->rthread=temp->rthread;
				  temp->right=newtemp;
				  newtemp->left=temp;
				  newtemp->lthread=1;
				  temp->rthread=0;
				}
  }
  
  else if(newtemp->data>temp->data)
  {
     while((temp->right!=head)&&(newtemp->data>temp->data))
				temp=temp->right;
    if(newtemp->data>temp->data)
    {
       newtemp->right=temp->right;
	newtemp->rthread=temp->rthread;
				  temp->right=newtemp;
				  newtemp->left=temp;
				  newtemp->lthread=1;
				  temp->rthread=0;
    } 
    else
    {
      newtemp->left=temp->left;
	newtemp->lthread=temp->lthread;
				  temp->left=newtemp;
				  newtemp->right=temp;
				  newtemp->rthread=1;
				  temp->lthread=0;
    }
  }
}

void TBTree::inorder(TBTree *temp)
{
  if(temp->rthread==1)
 {
    temp=temp->right;
    cout<<temp->data<<"\t";
 }
  else if(temp->rthread==0)
 {
  temp=temp->right;
  cout<<temp->data<<"\t";
 }
 if(temp->right!=head)
 inorder(temp);
}

void TBTree::menu()
{
	TBTree *temp=root;
	while(temp->lthread==0)
  temp=temp->left;
  cout<<temp->data<<"\t";
  inorder(temp);	
}

int main()
{
  int n,i;
  TBTree t;
  cout<<"Enter the number of data elements in this tree"<<endl;
  cin>>n;
  for(i=0;i<n;i++)
  t.assign();
	cout<<"The inorder is"<<endl;
        t.menu();
	cout<<endl;
  return 0;
}
