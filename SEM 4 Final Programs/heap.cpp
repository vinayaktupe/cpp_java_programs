  /* Heap Sort 

Problem Statement-
Read the marks obtained by students of second year in an online examination of particular
subject. Find out maximum and minimum marks obtained in that subject. Use heap data
structure. Analyze the algorithm.

*/	

#include<iostream>
using namespace std;
class heapsort
{
	int heap[20];
	int n;
	public:
		void accept();
		void disp();
		void heap_create();
		void downadj(int );
		void heap_sort();
};

void heapsort::accept()
{
	cout<<"\nEnter Number of Students= : ";
	cin>>n;
	cout<<"\nEnter marks of "<<n<<" students= : ";
	for(int i=1;i<=n;i++)
	
		cin>>heap[i];
}

void heapsort::disp()
{
	for(int i=1;i<=n;i++)
		cout<<"\t"<<heap[i];
	cout<<"\nMinimun Marks Obtained= "<<heap[1];
	cout<<"\nMaximum Marks Obtained= "<<heap[n]<<"\n";
}



void heapsort::heap_create()
{

	heap[0]=n;
	for(int i=n/2;i>=1;i--)  //take the parent of last node
	{
		downadj(i);
		
	}
}


void heapsort::heap_sort()
{

	int t,last;
	heap[0]=n;
	while(heap[0]>1)
	{
		last=heap[0];

		t=heap[last];
		heap[last]=heap[1];
		heap[1]=t;

		heap[0]--;
		downadj(1);
		
	}

}


void heapsort::downadj(int i)
{
	int j,t;
	while(2*i<=heap[0])   //i is not a leaf node
	{
		j=2*i;           // find the left child of i
		if(j+1<=heap[0] && heap[j+1]>heap[j])//j points larger of L&R
			j++;

		if(heap[i]<heap[j])//check heap property
		{
			t=heap[i];
			heap[i]=heap[j];
			heap[j]=t;
			i=j;
		}
		else
			break;
	}
}

int main()
{
	heapsort h;
	h.accept();
	
	h.heap_create();
	h.heap_sort();
	cout<<"\n\nStudents Marks After sorting: ";
	h.disp();
	
	return 0;

}




