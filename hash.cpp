#include<iostream>
#include<stdlib.h>
#define max 100
using namespace std;
class Data{
	public:
		int roll;
		string name;
	public:
		void accept(){
			cout<<"\nEnter Student Name: ";
			cin>>this->name;
			cout<<"\nEnter Student Roll no: ";
			cin>>this->roll;
		}
		void display(){
			cout<<this->name<<"\t"<<this->roll;
		}
};
class hash:protected Data{
	void *hashtable[10];
	int address;
	public:
		hash(){
			for(int i=0;i<10;++i){
				hashtable[i]=NULL;
			}
		}
		void generateAddress();
		void mapData(void*);
		void dispHash();
		void search();
};
int main(){
	int ch,flag=0;
	int i=0;
	system("cls");
	Data d[max];
	hash h;

	while(flag!=1){
		cout<<"\nEnter Choice\n1]Enter Data\n2]Display\n3]Search\n4]Exit ";
		cin>>ch;
		switch(ch){
			case 1:
				system("cls");
				d[i].accept();
				h.mapData(&d[i]);
				++i;
				break;
			case 2:
				system("cls");
				h.dispHash();
				break;
			case 3:
				system("cls");
				cout<<"\nWorking..."<<endl;
				break;
			case 4:
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
void hash :: generateAddress(){
	this->address=this->roll%10;
	cout<<"\nAddress Generated..."<<endl;
}
void hash :: mapData(void *ptr){
	int i,flag=0;
	generateAddress();
	if(hashtable[address]==NULL){
		hashtable[address]=ptr;
		cout<<"\nData Mapped..."<<endl;
	}
	else{
		while(flag!=1){
			for(i=address;hashtable[i]!=NULL || i<=10;++i){
			}
			if(i==10 && flag==0){
				i=0;
				flag=1;
				continue;
			}
			if(i<10){
				flag=1;
			}
		}
		hashtable[i]=ptr;
		cout<<"\nData Mapped..."<<endl;
	}
}
void hash :: dispHash(){
	int i;
	Data *ptr;
	cout<<"\nName\tRoll no.";
	for(i=0;i<10;++i){
		if(hashtable[i]!=NULL){
			cout<<"\n"<<name<<"\t"<<roll;
		}
		else{
			cout<<"\nEmpty\tEmpty";
		}
	}
}
void hash :: search(){
}
