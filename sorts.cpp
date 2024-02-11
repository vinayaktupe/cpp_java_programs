#include<iostream>
#include<stdlib.h>
#define size 5
using namespace std;
void selection();
void insertion();
void bubble();
void shell();
void disp();
int a[size];
int main(){
	return 0;
}
void selection(){
	int i,j,temp;
	for(i=0;i<size;++i){
		for(j=i;j<size;++j){
			if(a[i]>a[j]){
				temp=a[i];
				a[i]=a[j];
				a[j]=temp;
			}
		}
	}
}
void insertion(){
	int i,j,temp;
	for(i=0;i<size-1;++i){
		j=i+1;
		while(a[j]>a[j+1] && j>=0){
			temp=a[j];
			a[j]=a[j+1];
			a[j+1]=temp;
			--j
		}
	}
}
void bubble(){
}
void shell(){
}
void disp(){
}
