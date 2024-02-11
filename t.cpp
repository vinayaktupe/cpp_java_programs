#include<iostream>
#include <fstream>
using namespace std;
int n;
void get(int *);
void sort(int *);
void put(int *f);
void disp(int *f);
int count();

int main(){
int i;
n=count();
int arr[n];
get(arr);
sort(arr);
put(arr);
disp(arr);
return 0;
}

void put(int *f){
int i=0;
ofstream fout("output.txt");
for(i=0;i<n;++i){
fout<<f[i]<<endl;
}
fout.close();
}

void sort(int *f){
int i,j;
int temp;
get(f);
for(i=0;i<n;++i){
for(j=i;j<n;++j){
if(f[i]>f[j]){
temp=f[i];
f[i]=f[j];
f[j]=temp;
}
}
}
}

void get(int *arr){
int i=0;
ifstream fin;
fin.open("input.txt");
while(!fin.eof()){
fin>>arr[i];
++i;
}
fin.close();
}

int count(){
int i=0;
int s;
ifstream fin;
fin.open("input.txt");
while(!fin.eof()){
fin>>s;
++i;
}
fin.close();
return(i);
}

void disp(int *f){
int i;
for(i=0;i<n;++i){
cout<<"\n"<<f[i];
}
}