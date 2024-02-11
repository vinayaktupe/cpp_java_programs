#include<iostream>
#include<stdlib.h>
using namespace std;
int main(){
	system("cd ");
	system("cd programs");
	system("cd c++");
	system("g++ hello.cpp");
	system("hello.exe");
	system("javac");
	return 0;
}
/*
cd java

java>javac Hello.java

java>java Hello
 not find or load main class Hello

java>java Hello.java
 not find or load main class Hello.java

java>java Hello
*/
