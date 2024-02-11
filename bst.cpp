/*
Beginning with an empty binary search tree, Construct binary search tree by inserting the values in the order given. 
After constructing a binary tree -
i. Insert new node
ii. Find number of nodes in longest path
iii. Minimum data value found in the tree
iv. Change a tree so that the roles of the left and right pointers are swapped at every node
v. Search a value
*/

#include<iostream>
#include<stdlib.h>
using namespace std;
class Node{
	public: 
	int data;
	Node *lptr,*rptr;
};
class Tree: protected Node{
	public:
		Node *root;
		Tree(){
			root=NULL;
		}
		Node* create(int);
		void add(int);
		void insert(Node*,Node*);
		void disp();
		void pre(Node*);
		void in(Node*);
		void post(Node*);
};
int main(){
	int a,ch,flag=0;
	Tree t;
	system("cls");
	while(flag!=1){
		cout<<"\nEnter Choice\n1]Add\n2]Delete\n3]Display\n4]Number of nodes in longest path\n5]Search a Value\n6]Exit ";
		cin>>ch;
		switch(ch){
			case 1:
				system("cls");
				cout<<"\nEnter Value of a node: ";
				cin>>a;
				t.add(a);
				break;
			case 2:
				system("cls");
				cout<<"\nWorking"<<endl;
				break;
			case 3:
				system("cls");
				t.disp();
				break;
			case 4:
				system("cls");
				cout<<"\nWorking"<<endl;
				break;
			case 5:
				system("cls");
				cout<<"\nWorking"<<endl;
				break;
			case 6:
				system("cls");
				flag=1;
				break;
			default:
				system("cls");
				cout<<"\nInvalid Choice!!";
				break;
		}
	}
	cout<<"\nThank You!!"<<endl;
	return 0;
}
Node* Tree :: create(int x){
	Node *temp;
	temp=new Node;
	temp->data=x;
	temp->lptr=temp->rptr=NULL;
	return(temp);
}
void Tree :: add(int x){
	Node *curr;
	curr=create(x);
	if(root==NULL){
		root=curr;
	} 
	else{
		insert(root,curr);
	}
}
void Tree :: insert(Node *rt,Node *curr){
	if(curr->data>rt->data){
		if(rt->rptr==NULL){
			rt->rptr=curr;
		}
		else{
			insert(rt->rptr,curr);
		}
	}
	if(curr->data<rt->data){
		if(rt->lptr==NULL){
			rt->lptr=curr;
		}
		else{
			insert(rt->lptr,curr);
		}
	}
}
void Tree :: disp(){
	int ch,flag=0;
	while(flag!=1){
		cout<<"\n1]Pre Order\n2]In Order\n3]Post Order\n4]Exit ";
		cin>>ch;
		switch(ch){
			case 1:
				pre(root);
				break;
			case 2:
				in(root);
				break;
			case 3:
				post(root);
				break;
			case 4:
				flag=1;
				break;
			default:
				cout<<"\nInvalid Choice";
				system("cls");
				break;
		}
	}
	system("cls");
	cout<<"\nThank You!!!";
}
void Tree :: pre(Node *rt){
	if(rt==NULL)
		return;
		cout<<" "<<rt->data;
		pre(rt->lptr);
		pre(rt->rptr);
}
void Tree :: in(Node *rt){
	if(rt==NULL)
		return;
		pre(rt->lptr);
		cout<<" "<<rt->data;
		pre(rt->rptr);
}
void Tree :: post(Node *rt){
	if(rt==NULL)
		return;
		
		pre(rt->lptr);
		pre(rt->rptr);
		cout<<" "<<rt->data;
}
