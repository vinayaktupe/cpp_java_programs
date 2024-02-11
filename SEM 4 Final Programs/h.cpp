  /* Heap Sort 

Problem Statement-
Read the marks obtained by students of second year in an online examination of particular
subject. Find out maximum and minimum marks obtained in that subject. Use heap data
structure. Analyze the algorithm.

*/	
#include<iostream>
#include<stdlib.h>
#define max 100
using namespace std;
class Heap{
    int heap[max],n;
    public:
    void accept();
    void create_heap();
    void sort();
    void disp();
    void down(int);
};
int main(){
    Heap h;
    h.accept();
    h.create_heap();
    h.sort();
    h.disp();
    return 0;
}
void Heap :: accept(){
    cout<<"\nEnter Total number of students:";
    cin>>n;
    for(int i = 1; i <=n; i++)
    {
        cout<<"\nENter marks of student "<<i<<":";
        cin>>heap[i];
    }
}
void Heap :: create_heap(){
    heap[0]=n;
    for(int i = n/2; i >= 1; i--)
    {
        down(i);
    }
}
void Heap :: sort(){
    int t,last;
    heap[0]=n;
    while(heap[0]>  1){
        last=heap[0];
        t=heap[last];
        heap[last]=heap[1];
        heap[1]=t;
        heap[0]--;
        down(1);
    }
    
}
void Heap :: disp(){
    cout<<"\nSorted Marks List: ";
    for(int i = 1; i <=n; i++)
    {
        cout<<"\t"<<heap[i];
    }
    cout<<"\nMinimum Marks: "<<heap[1];
    cout<<"\nMaximum Marks: "<<heap[n]<<endl;    
}
void Heap :: down(int x){
    int j,t;
    while(2*x<=heap[0]){
        j=2*x;
        if(j+1<=heap[0] && heap[j+1]>heap[j]){
            j++;
        }
        if(heap[x]<heap[j]){
            t=heap[j];
            heap[j]=heap[x];
            heap[x]=t;
            x=j;
        }
        else
        {
            break;
        }
        
    }   
}