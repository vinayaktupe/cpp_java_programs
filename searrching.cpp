#include<iostream>
#include<stdlib.h>
#define size 10
using namespace std;
void getdata();
void linear();
void sentinial();
void binary();
void sort();
void fibonacci();
void disp();
int a[size];
int main(){
	int ch,flag=0;
	system("cls");
	cout<<"***********************************Welcome to Searching Algorithm System***********************************"<<endl;
	getdata();
	system("cls");
	while(flag!=1){
		cout<<"\nEnter Choice\n1]Search Using Linear Search\n2]Search Using Sentinial Search\n3]Search Using Binary Search\n4]Search Using Fibonacci Search\n5]Display Elements\n6]Re-Enter Elements\n7]Exit"<<endl;
		cin>>ch;
		switch(ch){
			case 1:
				//Search Using Linear Search
				system("cls");
				linear();
				break;
			case 2:
				//Search Using Sentinial Search
				system("cls");
				sentinial();
				break;
			case 3:
				//Search Using Binary Search
				system("cls");
				binary();
				break;
			case 4:
				//Search Using Fibonacci Search
				system("cls");
				fibonacci();
				break;
			case 5:
				//Display Elements
				system("cls");
				disp();
				break;
			case 6:
				//Re-Enter Elements
				system("cls");
				getdata();
				break;
			case 7:
				//Exit
				flag=1;
				break;
			default:
				system("cls");
				cout<<"\nInvalid Choice!!!!"<<endl;
				break;
		}
	}
	system("cls");
	cout<<"\nThank You!!!"<<endl;
	return 0;
}
void getdata(){
	int i;
	for(i=0;i<size;++i){
		cout<<"\nEnter "<<i+1<<" element: ";
		cin>>a[i];
	}
}
void linear(){
	int key,i,flag=0;
	cout<<"\nEnter Element to Search: ";
	cin>>key;
	for(i=0;i<size;++i){
		if(key==a[i]){
			flag=1;
			cout<<"\nElement "<<key<<" found at "<<i<<" position!!"<<endl;
			break;
		}
	}
	if(flag!=1){
		cout<<"\nElement "<<key<<" not found!!!"<<endl;
	}
}
void sentinial(){
	int key,last,i=0;
	cout<<"\nEnter Element to Search: ";
	cin>>key;
	last=a[size-1];
	a[size-1]=key;
	while(a[i]!=key){
		++i;
	}
	if(i<size-1 || a[i]==key){
		cout<<"\nElement "<<key<<" found at "<<i<<" position!!"<<endl;
	}
	else{
		cout<<"\nElement "<<key<<" not found!!!"<<endl;
	}
}
void binary(){
}
void sort(){
	int i,j,temp;
	for(i=0;i<size;++i){
		for(j=i;j<size;++j){
			if(a[i]>a[j]){
				temp=a[i];
				a[i]=a[j];
				a[j]=temp;
			}
		}
	}
}
void fibonacci(){
}
void disp(){
	int i;
	cout<<"\nElements:"<<endl;
	for(i=0;i<size;++i){
		cout<<a[i]<<endl;
	}
}
