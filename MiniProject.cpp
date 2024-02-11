/*
Write a C++ program to implement a small database mini project to understand persistent
objects and operations on sequential files (ex- library information, inventory systems,
automated banking system, reservation systems etc.) For example, write a program to create a
database for reservation system using information such as Name, sex, age, starting place of
journey and destination. Program should have following facilities a) To display entire
passenger list b) To display particular record c) To update record d) To delete and sort record.
Use Exception Handling for data verification
*/
#include <iostream>
#include <string>
#include <fstream>
#include <cstdio>

using namespace std;
void input();
void search();
void display();
void update();
void del();
void delpar();
void searchname();
void searchage();
void searchsex();
void searchstart();
void searchdesti();
int main(){
	system("clear");
	 cout<<"Welcome to Reservation System Database\n\n"<<endl;
       int choice,flag=0;
       while(flag!=1){
		       cout << "\n\n1.Input a new passenger" << endl;
		       cout << "2.Display Passengers" << endl;
		       cout << "3.Search Passengers" << endl;
		       cout << "4.Update Reservations" << endl;
		       cout << "5.Clear Reservations" << endl;
		       cout << "6.Exit Program" << endl;
		       cin >> choice;
		 
			switch (choice){
			       case 1:
			            input();
			            break;
			       case 2:
			            display();
			            break;
			      case 3:
			            search();
			            break;
			       case 4:
			            update();
			            break;
			       case 5:
			            del();
			            break;
			       case 6:
			       	flag=1;
			            break;
			      default:
			      	cout<<"\nInvalid Choice!!";
			      	break;
			      }
	}
	cout<<"\nThank You!!"<<endl;
	return 0;	
	}
void input(){
	string name,sex,start,destination;
	int age;
	ofstream reservation("reservation.txt", ios::app);
 	system("clear");
 	cout << "Enter the new passenger's name" << endl;
	 cin >> name;
	 cin.sync();
	 system("clear");
	 cout << "Enter the passenger's age." << endl;
	 cin >> age;
	 system("clear");
	 cout << "Enter the passenger's gender[M/F][m/f]" << endl;
	 cin >> sex;
	 system("clear");
	 cout << "Enter the passenger's starting point of journey" << endl;
	 cin >> start;
	 system("clear");
	 cout << "Enter the passenger's destination point of journey" << endl;
	 cin >> destination;
    	 reservation << name << ' ' << age << ' ' << sex << ' ' << start << ' ' << destination << endl;     
	 reservation.close(); 
	
}
void search(){
	int choice2;
	system ("clear"); 
	cout << "1.Search by Name" << endl;
	cout << "2.Search by Age" << endl;
	cout << "3.Search by Gender" << endl;
	cout << "4.Search by Start of Journey" << endl;
	cout << "5.Search by Destination of Journey" << endl;
	cout << "6.Display All Passengers" << endl;
	cout << "7.Exit Program" << endl;
	cin >> choice2;      
	switch (choice2){
		case 1:
			searchname();
			break;
		case 2:
			searchage();
			break;
		case 3:
			searchsex();
			break;
		case 4:
			searchstart();
			break;
		case 5:
			searchdesti();
			break;
		case 6:
			display();
			break;
		default:
			cout<<"\nInvalid Choice!!"<<endl;
			break;
	}
}
void searchname(){
	ifstream reservation("reservation.txt");
	string name,sex,start,destination,str;
	int age, offset;
	system("clear");
	cout << "Enter the passenger's name:";
	cin >> str;            
	while (!reservation.eof()){ 
	reservation >> name >> age >> sex >> start >> destination; 
		if (str == name){
			system ("clear");
			cout << "Passenger found" << endl;
			cout << "Name" << ' ' << "Age" << ' ' << "Gender" << ' ' << "Start" << ' ' << "Destination" << endl;
			cout << "---------------------------------------------------------------------------------" << endl;     
			cout << name << ' ' << age << ' ' << sex << ' ' << start <<' ' << destination << endl ;
		}
	}           

		if (str != name){
			system ("clear") ;   
			cout << "Nobody under that name exists" << endl;       
		}


}
void searchage(){
	ifstream reservation("reservation.txt");
	string name,sex,start,destination;
	int age, fage;
	system("clear");
	cout << "Enter the passenger's age:";
	cin >> fage;            
	while (!reservation.eof()){ 
	reservation >> name >> age >> sex >> start >> destination;  
		if (fage == age){
			system ("clear");
			cout << "Passenger found" << endl;
			cout << "Name" << ' ' << "Age" << ' ' << "Gender" << ' ' << "Start" << ' ' << "Destination" << endl;
			cout << "---------------------------------------------------------------------------------" << endl;     
			cout << name << ' ' << age << ' ' << sex << ' ' << start <<' ' << destination << endl ;
		}
	}           
	
		if (fage != age){
			system ("clear") ;   
			cout << "Nobody under that age exists" << endl;       
		}

}
void searchsex(){
	ifstream reservation("reservation.txt");
	string name,sex,start,destination,str;
	int age;
	system("clear");
	cout << "Enter the passenger's gender:";
	cin >> str;            
	while (!reservation.eof()){ 
	reservation >> name >> age >> sex >> start >> destination;  
		if (str == sex){
			system ("clear");
			cout << "Passenger found" << endl;
			cout << "Name" << ' ' << "Age" << ' ' << "Gender" << ' ' << "Start" << ' ' << "Destination" << endl;
			cout << "---------------------------------------------------------------------------------" << endl;     
			cout << name << ' ' << age << ' ' << sex << ' ' << start <<' ' << destination << endl ;
		}
	}           
	
		if (str != sex){
			system ("clear") ;   
			cout << "Nobody under that gender exists" << endl;       
		}
	

}
void searchstart(){
	ifstream reservation("reservation.txt");
	string name,sex,start,destination,str;
	int age;
	system("clear");
	cout << "Enter the passenger's starting point of journey:";
	cin >> str;            
	while (!reservation.eof()){ 
	reservation >> name >> age >> sex >> start >> destination;  
		if (str == start){
			system ("clear");
			cout << "Passenger found" << endl;
			cout << "Name" << ' ' << "Age" << ' ' << "Gender" << ' ' << "Start" << ' ' << "Destination" << endl;
			cout << "---------------------------------------------------------------------------------" << endl;     
			cout << name << ' ' << age << ' ' << sex << ' ' << start <<' ' << destination << endl ;
		}
	}           
	
		if (str != start){
			system ("clear") ;   
			cout << "Nobody under that starting point exists" << endl;       
		}
	

}
void searchdesti(){
	ifstream reservation("reservation.txt");
	string name,sex,start,destination,str;
	int age;
	system("clear");
	cout << "Enter the passenger's destination of journey:";
	cin >> str;            
	while (!reservation.eof()){ 
	reservation >> name >> age >> sex >> start >> destination;  
		if (str == destination){
			system ("clear");
			cout << "Passenger found" << endl;
			cout << "Name" << ' ' << "Age" << ' ' << "Gender" << ' ' << "Start" << ' ' << "Destination" << endl;
			cout << "---------------------------------------------------------------------------------" << endl;     
			cout << name << ' ' << age << ' ' << sex << ' ' << start <<' ' << destination << endl ;
		}
	}           
	
		if (str != start){
			system ("clear") ;   
			cout << "Nobody under that destination exists" << endl;       
		}
	

}
void display(){
	ifstream reservation("reservation.txt");
	string name,sex,start,destination;
	int age;
	system ("clear");
	cout << "Entire Reservation System Databasee"<< endl;
	cout << "Name" << ' ' << "Age" << ' ' << "Gender" << ' ' << "Start" << ' ' <<" Destination"<< endl;
	cout << "----------------------------------------------------------------------------------" << endl;
	while (reservation >> name >> age >> sex >> start >> destination){
		cout << name << ' ' << age << ' ' << sex << ' ' << start <<' ' << destination << endl ;
	}

}
void update(){
	string newName,newsex,newstart,newdestination,decision,input;
	string name,sex,start,destination,str;
 int age,newage;
 ifstream reservation("reservation.txt");
 ifstream reservation1("reservation.txt");
ofstream temp;
temp.open("temp.txt");
 system("clear");
  
 cout << "Enter the name of the passenger:";
 cin >> input;
 while(!reservation.eof()){
 	reservation >> name >> age >> sex >> start >> destination;
 if (input == name)
 {
      
     cout << name << ' ' << age << ' ' << sex <<' ' << start << ' ' << destination << endl;
     cout << "Is this the correct passenger[y][n]:";
     cin >> decision;
     if (decision == "y"){
     	while (!reservation1.eof())
  {
  	reservation1 >> name >> age >> sex >> start >> destination;
    if (name != input)
      temp << name << ' ' << age << ' ' << sex << ' ' << start << ' ' << destination << endl;
  }
  temp.close();
  reservation1.close();
	remove("reservation.txt");
  rename("temp.txt", "reservation.txt");
     cout << "Enter the new name:";
     cin >> newName;
     name = newName; 
     cout << "Enter the age:";
     cin >> newage;
     age = newage;
     cout << "Enter the gender:";
     cin >> newsex;
     sex = newsex;
     cout << "Enter the new starting point:";
     cin >> newstart;
     start = newstart;
     cout << "Enter the new destination point:";
     cin >> newdestination;
     destination = newdestination;
     break;     
           } 
     }    
     reservation.close();
     }
     ofstream reservation2("reservation.txt", ios::app);
     reservation2 << name << ' ' << age << ' ' << sex << ' ' << start << ' ' << destination << endl;
     reservation2.close();

}
void del(){
	char des;
	cout<<"\nDo you want to delete entire reservation list?[y/n]";
	cin>>des;
	if(des=='y'){
		remove("reservation.txt");
		cout<<"\nAll Reservations Cleared";
	}
	else if(des=='n'){
		delpar();
	}
}
void delpar(){
	string line, fname;
		string name,sex,start,destination,str;
	int age;
  cout << "Please Enter the name of passenger you want to delete reservation: ";
  cin >> fname;
  ifstream myfile;
  ofstream temp;
  myfile.open("reservation.txt");
  temp.open("temp.txt");
  while (!myfile.eof())
  {
  	myfile >> name >> age >> sex >> start >> destination;
    if (fname != name)
      temp << name << ' ' << age << ' ' << sex << ' ' << start << ' ' << destination << endl;
  }
  cout << "The record with the name " << name << " has been deleted if it exsisted" << endl;
  myfile.close();
  temp.close();
  remove("reservation.txt");
  rename("temp.txt", "reservation.txt");
}
