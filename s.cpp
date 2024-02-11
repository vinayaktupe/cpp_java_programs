#include<iostream>
#include <fstream>
using namespace std;
void get(int *);
void put(int *);
void disp(int *);
int count();
void sort();
int n;
int main(){
sort();
return 0;
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
put(f);
}
void get(int *f){
int i=0;
ifstream fin;
fin.open("input.txt");
while(!fin.eof()){
fin>>f[i];
++i;
}
fin.close();
disp(f);
}
void put(int *f){
int i=0;
ofstream fout("output.txt");
for(i=0;i<n;++i){
fout<<f[i]<<endl;
}
fout.close();
disp(f);
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