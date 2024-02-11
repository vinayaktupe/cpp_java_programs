#include<iostream>
#include<string.h>
using namespace std;
class base{
	public:
		base(){
			cout<<"\nFrom Base";
		}
};
class d:public base{
	public:
		d(){
			cout<<"\nFrom D";
		}
};
int main(){
	cout<<"\nCreate Base";
	cout<<"\nCreate D";
	d d;
	return 0;
}
