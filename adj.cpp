#include<iostream>
#include<stdlib.h>
#define MAX 100
using namespace std;
class Node{
	public: 
	int data;
	Node *nxt;
};
class AdjacencyMatrix{
	public:
		   int n;
		   int arr[MAX][MAX];
			void size(){
				cout<<"\nEnter Total no. of Elements in Graph: ";
				cin>>n;
			}
			void create(){
				int i,j;
				cout<<"\nEnter The Edge Connectivity Between Vertices in an Directed Graph\n";
				for(i=0;i<n;++i){
					for(j=0;j<n;++j){
						cout<<"\nIs Edge Present between "<<i<<" & "<<j<<"?(1 for Yes/2 for No): ";
						cin>>arr[i][j];
					}
				}
			}
			void disp(){
				int i,j;
				cout<<"\nThe Edge Connectivity Between Vertices in an Directed Graph";
				for(i=0;i<n;++i){
					cout<<"\n";
					for(j=0;j<n;++j){
						cout<<" "<<arr[i][j];
					}
				}
			}
};
class AdjacencyList: public AdjacencyMatrix{
	public:
		void disp(){
			int i,j;
			cout<<"\nDisplaying From AdjacencyList:\n";
			for(i=0;i<n;++i){
				cout<<"\n";
				for(j=0;j<n;++j){
					cout<<" "<<arr[i][j];
				}
			}
	2}
};
int main(){
	AdjacencyMatrix a;
	AdjacencyList l;
	a.size();
	a.create();
	l.disp();
	return 0;
}
