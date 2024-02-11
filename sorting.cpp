#include<iostream>
#include<stdlib.h>
#define n 5
using namespace std;
void disp();
void bubble();
void selection();
float f[n];
int main(){
	int i,ch,flag=0;
	system("cls");
	for(i=0;i<n;++i){
		cout<<"Enter Percentage of Roll no."<<i+1<<": ";
		cin>>f[i];
	}
	while(flag!=2){
		cout<<"\nEnter Choice\n1]Sort using Selection Sort\n2]Sort using Bubble Sort\n3]Display\n4]Exit";
		cin>>ch;
		switch(ch){
			case 1:
				selection();
				break;
			case 2:
				system("cls");
				bubble();
				break;
			case 3:
				system("cls");
				disp();
				break;
			case 4:
				system("cls");
				flag=2;
				cout<<"\nThank You!!!";
				break;
			default:
				cout<<"\nInvalid Choice";
				break;
		}
	}
	return 0;
}
void disp(){
	int i;
	for(i=0;i<n;++i){
		cout<<"\n"<<f[i];
	}
}
void bubble(){
int i,j;
float temp;
for(i=0;i<n;++i){
	for(j=i;j<n;++j){
		if(f[i]>f[j]){
			temp=f[i];
			f[i]=f[j];
			f[j]=temp;
		}
	}
}
cout<<"\nSorted";
}
void selection(){
	cout<<"\nWorking.....!!!"<<endl;
}
