#include<iostream>
#include<stdlib.h>
using namespace std;
int n,front,rear,a[5];
void initialize();
int full();
int empty();
void enqueue();
void dequeue();
void display();
int main(){
	int ch,x,flag=0;
	system("cls");
	initialize();
	while(flag!=1){
		cout<<"\nEnter Choice\n1]Enqueue\n2]Dequeue\n3]Display\n4]Exit ";
		cin>>ch;
		switch(ch){
			case 1:
				//Enqueue
				system("cls");
				enqueue();
				break;
			case 2:
				//Dequeue
				system("cls");
				dequeue();
				break;
			case 3:
				//Display
				system("cls");
				cout<<"\nQueue: "<<endl;
				display();
				break;
			case 4:
				//Exit
				system("cls");
				cout<<"\nThank You!!!!!!"<<endl;
				flag=1;
				break;
			default:
				system("cls");
				cout<<"\nInvalid Choice!!!!!!"<<endl;
				break;
		}
	}
	return 0;
}
void initialize(){
	front=rear=-1;
	n=5;
}
int full(){
	if(rear==(n-1)){
		return 1;
	}
	else{
		return 0;
	}
}
int empty(){
	if(rear==-1 || front==(n-1)){
		return 1;
	}
	else{
		return 0;
	}
}
void enqueue(){
	int x;
	if(full()==0){
		cout<<"\nEnter Element to enqueue: ";
		cin>>x;
		rear++;
		a[rear]=x;
		cout<<"\nElement "<<a[rear]<<" enqueued."<<endl;
	}
	else{
		cout<<"\nQueue is Full"<<endl;
	}
}
void dequeue(){
	int x;
	if(empty()==0){
		front++;
		x=a[front];
		cout<<"\n"<<x<<" is deleted."<<endl;
	}
	else{
		cout<<"\nQueue is Empty"<<endl;
	}
}
void display(){
	int i;
	if(empty()==0){
		for(i=front+1;i<=rear;++i){
			cout<<"\n"<<a[i];
		}
	}
}
