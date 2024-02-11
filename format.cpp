#include<iostream>
#include<stdlib.h>
#define max 100
using namespace std;
int main(){
	int ch,flag=0;
	system("cls");
	while(flag!=1){
		cout<<"\nEnter Choice\n1]\n2]\n3]\n4]\n5]Display\n6]Exit ";
		cin>>ch;
		switch(ch){
			case 1:
				system("cls");
				break;
			case 2:
				system("cls");
				break;
			case 3:
				system("cls");
				break;
			case 4:
				system("cls");
				break;
			case 5:
				system("cls");
				break;
			case 6:
				system("cls");
				break;
			case 7:
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
