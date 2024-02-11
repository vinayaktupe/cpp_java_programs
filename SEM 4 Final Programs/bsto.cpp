/*
Given sequence k = k1 <k2 < … < kn of n sorted keys, with a search probability pi for each key ki . Build the Binary search tree that has the least search cost given the access probability for each key.[OBST]
*/
#include <iostream>
#include <stdlib.h>
#define max 100
using namespace std;
class OBST
{
public:
    int n,r[max][max];
    float w[max][max],c[max][max],p[max],q[max];
    void accept();
    void calculate();
    void disp();
};

int main(){
    OBST o;
    o.accept();
    o.calculate();
    o.disp();
    return 0;
}
void OBST :: accept(){
    cout<<"\nEnter Number of nodes:";
    cin>>n;
    for(int i = 0; i < n; i++)
    {
        cout<<"\nEnter successful probability: ";
        cin>>p[i];
    }
    for(int i = 0; i <= n; i++)
    {
        cout<<"\nEnter unsuccessful probability: ";
        cin>>q[i];
    }
}
void OBST :: calculate(){
    int i,j,k;
    for(i=0;i<n;++i){
        r[i][i]=0;
        c[i][i]=0;
        w[i][i]=q[i];

        w[i][i+1]=w[i][i]+p[i+1]+q[i+1];
        c[i][i+1]=w[i][i+1];
        r[i][i+1]=i+1;
    }
    c[n][n]=0;
    r[n][n]=0;
    w[n][n]=q[n];
    for(i=2;i<=n;++i){
        for(j=0;j<=n-i;++j){
            w[j][j+1]=p[i+j]+q[i+j]+w[j][j+i-1];
            c[j][j+i]=999;
            for( k = j+1; k <=j+i ; k++)
            {
                if (c[j][j+i]>c[j][k-1]+c[k][j+i]) {
                    c[j][j+i]=c[j][k-1]+c[k][j+i];
                    r[j][j+i]=k;
                }
                
            }
            c[j][j+i]+=w[j][j+i];
        }
    }
}
void OBST :: disp(){
    int i,j,k=0;
    while(k<=n){
        for(i = 0,j=i+k; i < n,j<=n; i++,++j)
        {
            cout<<"w"<<i<<j<<"="<<w[i][j]<<"\t";
        }
        cout<<"\n"<<endl;
        for(i = 0,j=i+k; i < n,j<=n; i++,++j)
        {
            cout<<"c"<<i<<j<<"="<<c[i][j]<<"\t";
        }
        cout<<"\n"<<endl;;
        for(i = 0,j=i+k; i < n,j<=n; i++,++j)
        {
            cout<<"r"<<i<<j<<"="<<r[i][j]<<"\t";
        }
        cout<<"\n"<<endl;
        ++k;
    }
    
}