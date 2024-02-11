#include<iostream>
#include<stdlib.h>
#include<string.h>
#define n 50
using namespace std;
char s[n];
int top=-1;
void push(char);
void pop();
int main(){
	int l,i,flag=0;
	char temp[n];
	system("cls");
	while(flag!=2){
		system("cls");
		cout<<"\nEnter Your Expression: ";
		cin>>temp;
		l=strlen(temp);
		for(i=0;i<l;++i){
			if((temp[i]=='[') || (temp[i]=='(') || (temp[i]=='{')){
				push(temp[i]);
			}
			else if((temp[i]==']') || (temp[i]==')') || (temp[i]=='}')){
				pop();
			}
		}
		if(top==-1){
			cout<<"\nExpression is Well-Paranthesised!!!"<<endl;
		}
		else{
			cout<<"\nExpression is Not Well-Paranthesised!!!"<<endl;
		}
		cout<<"\nDo you want to continue? (1 for Yes/ 2 for No) ";
		cin>>flag;
	}
	system("cls");
	cout<<"\nThank You!!";
	return 0;
}
void push(char x){
	top++;
	s[top]=x;
}
void pop(){
	if((s[top]=='[') || (s[top]=='(') || (s[top]=='{')){
		top--;
	}
}
