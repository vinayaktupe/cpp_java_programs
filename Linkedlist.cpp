#include<iostream>
#include<stdlib.h>
using namespace std;
class node;
node *head1,*tail1,*head2,*tail2,*head3,*tail3;
class node{
	int data;
	node *nxt;
	public:
		friend void create(node*,node*);
		friend void display(node*);
		friend void un();
		friend void compare(int,node*);
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
void un(){
	
}
void compare(int x,node *h){
}
int main(){
	head1=tail1=head2=tail2=head3=tail3=NULL;
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
