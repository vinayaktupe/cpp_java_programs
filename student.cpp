#include<iostream>
#include<stdlib.h>
using namespace std;
class student{
		int rno,marks,ab;
		string name;
	public:
		int high(student[]);
		int low(student[]);
		float avg(student[],int,int);
		void absent(student[]);
		void display(student[]);
		void most(student[]);
		void set(int,int,int,string);
	};
int n;
int main(){
	int ch,flag,i,r,m,a,sum,hi,lo,cnt=0;
	float avg;
	string na;
	flag=0;
	sum=0;
	system("cls");
	cout<<"\nEnter The Strength of Class: ";
	cin>>n;
	student s[n],temp;
	system("cls");
	for(i=0;i<n;++i){
		r=i+1;
		cout<<"\nEnter Name of Roll no."<<r<<": ";
		cin>>na;
		cout<<"\nWas Roll no."<<r<<" present for test?(1 for yes/2 for no) ";
		cin>>a;
		if(a==1){
			cout<<"\nEnter marks of Roll no."<<r<<" ";
			cin>>m; 
			sum=sum+m;
			cnt++;
		}
		if(a==1){
			s[i].set(r,m,a,na);
		}
		else if(a==2){
			m=0;
			s[i].set(r,m,a,na);
		}
	}
	system("cls");
	while(flag!=1){
		cout<<"\nEnter Choice:\n1]Highest & Lowest Marks\n2]Average of Class\n3]Most marks scored by students\n4]Display Absent Students\n5]Display All Students\n6]Exit\n";
		cin>>ch;
		switch(ch){
			case 1:
				//Highest & Lowest Marks
				system("cls");
				hi=temp.high(s);
				lo=temp.low(s);
				cout<<"\nHighest Marks: "<<hi<<"\nLowest marks: "<<lo<<endl;
			break;
			case 2:
				//Average of Class
				system("cls");
				avg=temp.avg(s,cnt,sum);
				cout<<"\nAverage of Class: "<<avg<<endl;
			break;
			case 3:
				//Most marks scored by students
				system("cls");
				temp.most(s);
			break;
			case 4:
				//Display Absent Students
				system("cls");
				temp.absent(s);
			break;
			case 5:
				//Display All Students
				system("cls");
				temp.display(s);
			break;
			case 6:
				//Exit
				system("cls");
				cout<<"\n\t\t**************************Thank You!!!!**************************";
				flag=1;
			break;
			default:
				system("cls");
				cout<<"\nInvalid Choice!!!";
			break;
		}
	}
	return 0;
}
void student::set(int r,int m,int a,string na){
	rno=r;
	marks=m;
	ab=a;
	name=na;
}
int student::high(student a[]){
	int i,h;
	h=0;
	for(i=0;i<n;++i){
		if(a[i].ab==1 && h<a[i].marks){
			h=a[i].marks;
		}
	}
	return(h);
}
int student::low(student a[]){
	int i,l;
	l=100;
	for(i=0;i<n;++i){
		if(a[i].ab==1 && l>a[i].marks){
			l=a[i].marks;
		}
	}
	return(l);	
}
float student::avg(student a[],int cnt,int sum){
	float f;
	f=sum/cnt;
	cout<<"\nPresent No of Students: "<<cnt<<"\nSum of Their Marks: "<<sum<<endl;
	return(f);
}
void student::absent(student a[]){
	int i;
	cout<<"\nName\t\tRoll No.\n";
	for(i=0;i<n;++i){
		if(a[i].ab==2){
			cout<<a[i].name<<"\t\t"<<a[i].rno<<endl;
		}
	}
}
void student::display(student a[]){
	int i;
	cout<<"\nName\t\tRoll No.\tMarks\n"<<endl;
	for(i=0;i<n;++i){
		if(a[i].ab==1){
			cout<<a[i].name<<"\t\t"<<a[i].rno<<"\t\t"<<a[i].marks<<endl;
		}
		else if(a[i].ab==2){
			cout<<a[i].name<<"\t\t"<<a[i].rno<<"\t\tAbsent"<<endl;
		}
	}
}
void student::most(student a[]){
	int m[10],i,cat,most;
	cat=most=0;
	for(i=0;i<10;++i){
		m[i]=0;
	}
	for(i=0;i<n;++i){
		if(a[i].ab==1 && a[i].marks>=1 && a[i].marks<=10){
			++m[0];
		}
		else if(a[i].ab==1 && a[i].marks>=11 && a[i].marks<=20){
			++m[1];
		}
		else if(a[i].ab==1 && a[i].marks>=21 && a[i].marks<=30){
			++m[2];
		}
		else if(a[i].ab==1 && a[i].marks>=31 && a[i].marks<=40){
			++m[3];
		}
		else if(a[i].ab==1 && a[i].marks>=41 && a[i].marks<=50){
			++m[4];
		}
		else if(a[i].ab==1 && a[i].marks>=51 && a[i].marks<=60){
			++m[5];
		}
		else if(a[i].ab==1 && a[i].marks>=61 && a[i].marks<=70){
			++m[6];
		}
		else if(a[i].ab==1 && a[i].marks>=71 && a[i].marks<=80){
			++m[7];
		}
		else if(a[i].ab==1 && a[i].marks>=81 && a[i].marks<=90){
			++m[8];
		}
		else if(a[i].ab==1 && a[i].marks>=91 && a[i].marks<=100){
			++m[9];
		}
	}
	for(i=0;i<10;++i){
		if(most<m[i]){
			most=m[i];
			cat=i;
		}
	}
	if(cat==0){
		cout<<most<<" Students Scored Marks between 1-10"<<endl;
	}
	else if(cat==1){
	cout<<most<<" Students Scored Marks between 11-20"<<endl;	
	}
	else if(cat==2){
		cout<<most<<" Students Scored Marks between 21-30"<<endl;
	}
	else if(cat==3){
		cout<<most<<" Students Scored Marks between 31-40"<<endl;
	}
	else if(cat==4){
		cout<<most<<" Students Scored Marks between 41-50"<<endl;
	}
	else if(cat==5){
		cout<<most<<" Students Scored Marks between 51-60"<<endl;
	}
	else if(cat==6){
		cout<<most<<" Students Scored Marks between 61-70"<<endl;
	}
	else if(cat==7){
		cout<<most<<" Students Scored Marks between 71-80"<<endl;
	}
	else if(cat==8){
		cout<<most<<" Students Scored Marks between 81-90"<<endl;
	}
	else if(cat==9){
		cout<<most<<" Students Scored Marks between 91-100"<<endl;
	}
}
