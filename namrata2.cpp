#include<iostream>
#include<string.h>

using namespace std;
void showMenu(){
    cout<<"We have burgers with following costs:"<<endl;
    cout<<"Veg: Rs. 30"<<endl;
    cout<<"Chicken: Rs. 40"<<endl;
    cout<<"Fish: Rs. 50"<<endl;
    cout<<"Double-Chicken: Rs. 60"<<endl;
}
int cal(int arr[],int n){
    int sum=0;
    for (int i = 0; i < n; i++){
        sum+=arr[i];
    }
    return sum;
}
void placeOrder(){
    int n;
    cout<<"How many burgers do you want to buy? ";
    cin>>n;
    int order[n];
    int no=n;
    for (int i = n-1; i >=0; i--){
        cout<<"Enter the cost of Burger "<<no<<" to order for it: ";
        no--;
        cin>>order[i];
    }
    cout<<"The total cost of your oder is: Rs. "<<cal(order,n);
}
int main(int argc, char const *argv[])
{
    char ch;
    cout<<"Do you want to place an order? ";
    cin>>ch;
    if (ch=='Y'|| ch=='y'){
        showMenu();
        placeOrder();
    }
    else{
        cout<<"Plese do visit us again";
    }
    return 0;
}