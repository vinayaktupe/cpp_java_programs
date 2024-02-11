#include<iostream>
#include<stdlib.h>
using namespace std;
class node;
node *head1,*tail1;
class node{
	int data;
	node *nxt;
	public:
		friend void create(node*,node*);
		friend void display(node*);
};
void create(node *head,node *tail){
	node *curr=new node();
	cout<<"\nEnter Data: ";
	cin>>curr->data;
	curr->nxt= NULL;
	if(head==NULL){
		head=tail=curr;
	}
	else{
		tail->nxt=curr;
		tail=curr;
	}
}
void display(node *disp){
	cout<<"\n";
	while(disp!=NULL){
		cout<<disp->data<<endl;
		disp=disp->nxt;
		}
}
int main(){
	head1=tail1=NULL;
	int x,i=0;
	cout<<"\nEnter Size of Set A & B: ";
	cin>>x;
	while(i<x){
		create(head1,tail1);
		++i;
	}
	cout<<"\nSet A:";
	display(head1);
	return 0;
}
