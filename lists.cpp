#include<iostream>
#include<stdlib.h>
using namespace std;
int m[100][100];
char n[100];
class Node{
public:
	char data;
	Node *next;
};
class Main{
public:
	   char x;
	   Node *head;
};
class List : public Node,public Main{
	  int size;
public:
	Main *array;
	List(){
		int i,j;
		for(i=0;i<size;++i){
			for(j=0;j<size;++j){
				m[i][j]=0;
			}
		}
	}
	void createList();
	void accept();
	void displayMatrix();
	void displayList();
	void add(int,char);
	void finder();
	Node * create(char);
};
int main()
{
	int ch,flag=0;
	List l;
	system("cls");
	l.accept();
	l.createList();
	l.finder();
	while(flag!=1){
		cout<<"\nEnter Choice\n1]Display Matrix\n2]Display List\n3]Re-Enter Information\n4]Exit ";
		cin>>ch;
		switch(ch){
			case 1:
				system("cls");
				cout<<"\nAdjacency Matrix:\n";
				l.displayMatrix();
				break;
			case 2:
				system("cls");
				cout<<"\nAdjacency List:\n";
				l.displayList();
				break;
			case 3:
				system("cls");
				l.accept();
				l.createList();
				l.finder();
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
}
void List :: accept(){
	int i,j,dis,ch=0;
	cout<<"\nEnter Number of Vertices: ";
	cin>>size;
	for(i=0;i<size;++i){
		cout<<"\nName of Vertex "<<i<<": ";
		cin>>n[i];
	}
	for(i=0;i<size;++i){
		for(j=0;j<size;++j){
			cout<<"\nis edge connected between "<<n[i]<<" & "<<n[j]<<"? (1 foryes/2 for no) ";
			cin>>ch;
			if(ch==1){
				cout<<"\nDistance: ";
				cin>>dis;
				m[i][j]=dis;
			}
		}
	}
}
void List :: createList(){
	array =new Main [100];
	int i;
	for(i=0;i<size;++i){
		array[i].head=NULL;
		array[i].x=n[i];
	}
}
void List :: finder(){
	int i,j;
	for(i=0;i<size;++i){
		for(j=0;j<size;++j){
			if(m[i][j]!=0){
				add(i,n[j]);
			}
		}
	}
}
void List :: add(int r,char x){
	Node *curr,*temp;
	curr=create(x);
	if(array[r].head==NULL){
		array[r].head=curr;
	}
	else{
		for(temp=array[r].head;temp!=NULL;temp=temp->next){
		}
		temp->next=curr;
	}
}
Node * List :: create(char x){
	Node *temp;
	temp=new Node();
	temp->data=x;
	temp->next=NULL;
	return(temp);
}
void List :: displayMatrix(){
	int i,j;
	for(i=0;i<size;++i){
		cout<<"\t"<<n[i];
	}
	for(i=0;i<size;++i){
		cout<<"\n"<<n[i];
		for(j=0;j<size;++j){
			cout<<"\t"<<m[i][j];
		}
	}	
}
void List :: displayList(){
	int i;
	Node *temp;
	for(i=0;i<size;++i){
		temp=array[i].head;
		cout<<"\n"<<array[i].x;
		while(temp!=NULL){
			cout<<"->"<<temp->data;
			temp=temp->next;
		}
	}
}
