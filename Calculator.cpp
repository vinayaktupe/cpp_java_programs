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
using namespace std;

int concatenate(int destination, int element) {
    int res;
    res=(destination*10)+element;
    return(res);        
}

int main(){
	char s[1000];
	int o1,o2;
	o1=o2=0;
	cout<<"\nEnter Operation: ";
	cin>>s;
	int i=0;
	while(((int)s[i])!=00){
		if(((int)s[i])==47 || ((int)s[i])==42 || ((int)s[i])==43 || ((int)s[i])==45){
			switch(((int)s[i])){
				case 47:
					//division
					cout<<"division"<<endl;
					break;
				case 42:
					//multiplication
					cout<<"multiplication"<<endl;
					break;
				case 43:
					//addition
					cout<<"Addtion"<<endl;
					break;
				case 45:
					//substraction
					cout<<"substraction"<<endl;
					break;
			}
		}
		if(((int)s[i])==48){
			//0 digit
			concatenate();
		}
		else if(((int)s[i])==49){
			//1 digit
		}
		else if(((int)s[i])==50){
			//2 digit
		}
		else if(((int)s[i])==51){
			//3 digit
		}
		else if(((int)s[i])==52){
			//4 digit
		}
		else if(((int)s[i])==53){
			//5 digit
		}
		else if(((int)s[i])==54){
			//6 digit
		}
		else if(((int)s[i])==55){
			//7 digit
		}
		else if(((int)s[i])==56){
			//8 digit
		}
		else if(((int)s[i])==57){
			//9 digit
		}
	++i;
	}
	return 0;
}
