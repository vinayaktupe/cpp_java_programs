/*
Write a C++ program create a calculator for an arithmetic operator (+, -, *, /). The program
should take two operands from user and performs the operation on those two operands
depending upon the operator entered by user. Use a switch statement to select the operation.
Finally, display the result.
Some sample interaction with the program might look like this:
Enter first number, operator, second number: 10 / 3
Answer = 3.333333
Do another (y/n)? y
Enter first number, operator, second number: 12 + 100
Answer = 112
Do another (y/n)? n
*/
#include<iostream>
#include<string.h>
#include<stdlib.h>
using namespace std;
int main(){
	int op1,op2,res;
	char op,flag='y';
	float fres;
	while(1){
		if(flag=='y'){
				system("cls");
			cout<<"\nEnter first number, operator, second number: ";
			cin>>op1>>op>>op2;
			switch(op){
				case '+':
					res=op1+op2;
					cout<<"\nAddtion: "<<res;
					break;
				case '-':
					res=op1-op2;
					cout<<"\nSubstraction: "<<res;
					break;
				case '*':
					res=op1*op2;
					cout<<"\nMultiplication: "<<res;
					break;
				case '/':
					fres=((float)op1)/((float)op2);
					cout<<"\nDivision: "<<fres;
					break;
			}
			cout<<"\nDo another (y/n)? ";
			cin>>flag;
		}
		else{
			cout<<"\nThank You!!\n\n"<<endl;
			flag='n';
			break;
		}
	}
	return 0;
}
