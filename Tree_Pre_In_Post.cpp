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
	if(root=NULL){
		root=curr;
	} 
	else{
		insert(root,curr);
	}
}
void Tree :: insert(Node *rt,Node *curr){
	char ch;
	cout<<"\nAdd to Left or Right of "<<rt->data<<" ?";
	cin>>ch;
	if(ch=='r' || ch=='R'){
		if(rt->rptr==NULL){
			rt->rptr=curr;
		}
		else{
			insert(rt->rptr,curr);
		}
	}
	if(ch=='r' || ch=='R'){
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
		system("cls");
		cout<<"\nThank You!!!";
	}
}
void Tree :: pre(Node *rt){
	if(rt!=NULL){
		cout<<" "<<rt->data;
		pre(rt->lptr);
		pre(rt->rptr);
	}
}
void Tree :: in(Node *rt){
	if(rt!=NULL){
		pre(rt->lptr);
		cout<<" "<<rt->data;
		pre(rt->rptr);
	}
}
void Tree :: post(Node *rt){
	if(rt!=NULL){
		pre(rt->lptr);
		pre(rt->rptr);
		cout<<" "<<rt->data;
	}
}
