#include<iostream>
#include<stdlib.h>
#include<fstream>
using namespace std;
int roll;
string name;
void initialize();
void accept();
void display();
int main(){
	int ch,flag=0;
	system("cls");
	initialize();
	while(flag!=1){
		cout<<"\nEnter Choice\n1]Enter Data\n2]Display Data\n3]Exit ";
		cin>>ch;
		switch(ch){
			case 1:
				//Enter Data
				system("cls");
				accept();
				break;
			case 2:
				//Display Data
				system("cls");
				display();
				break;
			case 3:
				//Exit
				system("cls");
				cout<<"\nThank You!!!"<<endl;
				flag=1;
				break;
			default: 
			system("cls");
			cout<<"\nInvalid Choice!!!"<<endl;
				break;
		}
	}
	return 0;
}
void initialize(){
	ofstream out("file.xls");
	out<<"Roll No\tName\n";
	out.close();
	cout<<"\nInitialization Over";
}
void accept(){
	ofstream fout;
	fout.open("file.xls");
	cout<<"\nEnter roll no. ";
	cin>>roll;
	cout<<"\nEnter name. ";
	cin>>name;
	fout<<"\n"<<roll<<"\t"<<name;
	fout.close();
}
void display(){
	ifstream fin;
	fin.open("file.xls");
	fin>>roll>>name;
	cout<<roll<<"\t"<<name<<endl;
	//cout<<"Roll no.\tName\n"<<roll<<"\t"<<name;
	fin.close();
}
