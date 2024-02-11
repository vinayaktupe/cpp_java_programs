#include<iostream>
#include<stdlib.h>
using namespace std;
class Node{
	public:
		string data;
		Node *l,*r;
};
class Tree:protected Node{
	public:
		Node *root;
		Tree(){
			root=NULL;
		}
		Node *create(string s){
			Node *temp;
			temp=new Node;
			temp->data=s;
			temp->l=temp->r=NULL;
			return(temp);
		} 
		void add(string s){
			Node *curr;
			curr=create(s);
			if(root==NULL){
				root=curr;
			}
			else{
				insert(root,curr);
			}
		}
		void insert(Node *rt,Node *curr){
			char ch;
			cout<<"\nAdd on Left or Right of: "<<rt->data;
			cin>>ch;
			if(ch=='l' || ch=='L'){
				if(rt->l==NULL){
					rt->l=curr;
				}
				else{
					insert(rt->l,curr);
				}
			}
			else if(ch=='r' || ch=='R'){
				if(rt->r==NULL){
					rt->r=curr;
				}
				else{
					insert(rt->r,curr);
				}
			}
		}
		void preorder(Node *temp){
			if(temp!=NULL){
				cout<<" "<<temp->data;
				preorder(temp->l);
				preorder(temp->r);
			}
		}
};
int main(){
	int ch,flag=0;
	Tree t;
	string s;
	while(flag!=1){
		cout<<"\nEnter Choice\n1]Add\n2]Display\n3]Exit\n";
		cin>>ch;
		switch(ch){
			case 1:
				cout<<"\nEnter Data: ";
				cin>>s;
				t.add(s);
				break;
			case 2:
				t.preorder(t.root);
				break;
			case 3:
				flag=1;
				break;
			default:
				cout<<"\nInvalid Choice!!!!";
				break;
		}
	}
	cout<<"\nThank You!!!!";
	return 0;
}









