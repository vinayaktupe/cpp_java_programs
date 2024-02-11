#include<iostream>
#include<stdlib.h>
#define max 100
using namespace std;
class tel{
	public:
		int number;
		void accept(){
			cout<<"\nEnter Telephone no: ";
			cin>>number;
		}
};
class map: public tel{
	int hash[10];
	int address;
	public:
		map(){
			for(int i=0;i<10;++i){
				hash[i]=-1;
			}
		}
		void generateAddress(){
			this->address=this->number%10;
		}
		void mapData(){
			this->generateAddress();
			int i,flag=0;
			if(hash[this->address]==-1){
				hash[this->address]=this->number;
			}
			else{
				i=address;
				while(flag!=1){
					while(hash[i]==-1 || i<=10){
						++i;
					}
					if(i<10){
						flag=1;
					}
					if(i>=10){
						i=0;
					}
				}
				hash[i]=number;
			}
		}
		void displayHash(){
			int i;
			cout<<"\nNumber";
			for(i=0;i<10;++i){
				if(hash[i]!=-1){
					cout<<"\n"<<hash[i];
				}
				else{
					cout<<"\nEmpty";
				}
			}
		}
};
int main(){
	int ch,flag=0;
	map m;
	while(flag!=1){
		cout<<"\nEnter Choice\n1]Enter Data\n2]Display\n3]Search\n4]Exit ";
		cin>>ch;
		switch(ch){
			case 1:
				system("cls");
				m.accept();
				break;
			case 2:
				system("cls");
				m.displayHash();
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
