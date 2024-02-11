/*
Write a function to get the number of vertices in an undirected graph and its edges. 
You may assume that no edge is input twice.
i. Use adjacency list representation of the graph and find runtime of the function
ii. Use adjacency matrix representation of the graph and find runtime of the function
*/
#include<iostream>
#include<stdlib.h>
#define MAX 100
using namespace std;
class Node{
	public: 
	int data;
	Node *nxt;
};
class List{
    public:
    Node *nxt;
};
class AdjacencyMatrix{
public:
	int n;
	int arr[MAX][MAX];
	void size();
	void create();
	void disp();
};
class AdjacencyList: public AdjacencyMatrix,public List,public Node{
public:
    List list[MAX];
    void calculate();
    void disp();
    Node * create(int);
    AdjacencyList(){
        for(int i = 0; i < n; i++)
        {
            list[i].nxt=NULL;
        }
        
    }
};
int main(){
	AdjacencyMatrix a;
	AdjacencyList l;
	a.size();
	a.create();
	a.disp();
    l.calculate();
    cout<<"\nAdjacency List:\n";
    l.disp();
	return 0;
}
void AdjacencyMatrix :: size(){
	cout<<"\nEnter Total no. of Elements in Graph: ";
	cin>>n;
}			
void AdjacencyMatrix :: disp(){
    int i,j;
    cout<<"\nThe Edge Connectivity Between Vertices in an Directed Graph";
    for(i=0;i<n;++i){
        cout<<"\n";
        for(j=0;j<n;++j){
            cout<<" "<<arr[i][j];
        }
    }
}
void AdjacencyMatrix :: create(){
	int i,j,ch;
	cout<<"\nEnter The Edge Connectivity Between Vertices in an Directed Graph\n";
	for(i=0;i<n;++i){
		for(j=0;j<n;++j){
			cout<<"\nIs Edge Present between "<<i<<" & "<<j<<"?(1 for Yes/2 for No): ";
			cin>>ch;
            if(ch==1){
                arr[i][j]=1;
            }
            else
            {
                arr[i][j]=0;
            }
            
		}
	}
}
void AdjacencyList :: calculate(){
    int i,j;
    Node *temp,*front;
    for(i = 0; i < n; i++)
    {
        for(j=0;j<n;++j){
            if(arr[i][j]==1){
                temp=create(j);
                if(list[i].nxt==NULL){
                    list[i].nxt=temp;
                }
                else{
                    front=list[i].nxt;
                    while(front!=NULL){
                        front=front->nxt;
                    }
                    front->nxt=temp;
                }
            }
        }
    }
    
}
void AdjacencyList :: disp(){
    Node *temp;
    for(int i=0;i<n;++i){
        temp=list[i].nxt;
        cout<<"\n"<<i;
        while(temp!=NULL){
            cout<<"->"<<temp->data;
            temp=temp->nxt;
        }
        
    }
}
Node* AdjacencyList :: create(int x){
    Node *temp;
    temp=new Node();
    temp->nxt=NULL;
    temp->data=x;
    return(temp);
}