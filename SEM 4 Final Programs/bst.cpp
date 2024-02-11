/*1.Beginning with an empty binary search tree, Construct binary search tree by inserting the values in the order given. After constructing a binary tree -
i. Insert new node
ii. Find number of nodes in longest path
iii. Minimum data value found in the tree
iv. Change a tree so that the roles of the left and right pointers are swapped at every node
v. Search a value
*/
#include<iostream>
#include<stdlib.h>
using namespace std;
class Node
{
public:
    int data;
    Node *lptr,*rptr;
};
class bst
{
public:
    Node *root;
    Node * create(int);
    void add(int);
    void insert(Node*,Node*);
    void disp();
    void pre(Node*);
    void in(Node*);
    void post(Node*);
    void great();
    void small();
    void change(Node*);
    void search();
    bst(){
        root=NULL;
    }
};

int main(){
    int x,ch,flag=0;
    bst b;
    while(flag!=1){
        cout<<"\nEnter Choice\n1]Enter Data\n2]Display Tree\n3]Search Node\n4]Number of Nodes in Longest Path\n5]Smallest Node\n6]Swap Tree Nodes\n7]Exit";
        cin>>ch;
        switch (ch)
        {
            case 1:
                system("cls");
                cout<<"\nEnter Data to add:";
                cin>>x;
                b.add(x);
                break;
            case 2:
                system("cls");
                b.disp();
                break;
            case 3:
                system("cls");
                b.search();
                break;
            case 4:
                system("cls");
                b.great();
                break;
            case 5:
                system("cls");
                b.small();
                break;
            case 6:
                system("cls");
                b.change(b.root);
                break;
            case 7:
                flag=1;
                break;
            default:
                cout<<"\nInvalid Choice!!!";
                break;
        }
    }
    system("cls");
    cout<<"\nThank You!!!"<<endl;
    return 0;
}
Node* bst :: create(int x){
    Node *temp=new Node();
    temp->data=x;
    temp->lptr=temp->rptr=NULL;
    return(temp);
}
void bst :: add(int x){
    Node *curr;
    curr=create(x);
    if(root==NULL){
        root=curr;
    }
    else
    {
        insert(root,curr);
    }
    
}
void bst :: insert(Node *rt ,Node *curr){
    int ch;
    if(rt->data>curr->data){
        if(rt->lptr==NULL){
            rt->lptr=curr;
        }
        else{
            insert(rt->lptr,curr);
        }
    }
    else{
        if(rt->rptr==NULL){
            rt->rptr=curr;
        }
        else{
            insert(rt->rptr,curr);
        }
    }
}
void bst :: disp(){
    int x,ch,flag=0;
    bst b;
    while(flag!=1){
        cout<<"\nEnter Choice\n1]Pre Order\n2]In Order\n3]Post Order\n4]Exit";
        cin>>ch;
        switch (ch)
        {
            case 1:
                system("cls");
                cout<<"\nPreorder:";
                pre(root);
                break;
            case 2:
                system("cls");
                cout<<"\nInorder:";
                in(root);
                break;
            case 3:
                system("cls");
                cout<<"\nPostorder:";
                post(root);
                break;
            case 4:
                flag=1;
                break;
            default:
                cout<<"\nInvalid Choice!!!";
                break;
        }
    }
    system("cls");
    cout<<"\nThank You!!!"<<endl;
}
void bst :: pre(Node *rt){
    if(rt==NULL)
        return;
    cout<<"\t"<<rt->data;
    pre(rt->lptr);
    pre(rt->rptr);
}
void bst :: in(Node *rt){
    if(rt==NULL)
        return;
    in(rt->lptr);
    cout<<"\t"<<rt->data;
    in(rt->rptr);
}
void bst ::  post(Node *rt){
    if(rt==NULL)
        return;
    post(rt->lptr);
    post(rt->rptr);
    cout<<"\t"<<rt->data;
}
void bst ::  great(){
    int lcnt,rcnt,x;
    lcnt=rcnt=0;
    Node *temp;
    temp=root;
    while(temp!=NULL){
        if(temp->lptr!=NULL){
            temp=temp->lptr;
            lcnt++;
        }
        else{
            temp=temp->rptr;
            rcnt++;
        }
    }
    x=(lcnt>rcnt?lcnt:rcnt);
    cout<<"\nLongest Path: "<<x;
}
void bst ::  small(){
    int x;
    Node *temp;
    for(temp=root;temp!=NULL;temp=temp->lptr){}
    x=temp->data;
    cout<<"\nSmallest No:"<<x;
}
void bst ::  change(Node *rt){
    if(rt==NULL)
        return;
    cout<<"\t"<<rt->data;
    pre(rt->rptr);
    pre(rt->lptr);
}
void bst ::  search(){
    int key,flag=0;
    Node *temp;
    temp=root;
    cout<<"\nEnter key to search:";
    cin>>key;
    while(temp!=NULL){
        if(key==temp->data){
            cout<<"\n"<<key<<" present."<<endl;
            flag=1;
            break;
        }
        else{
            if(key>temp->data){
                temp=temp->rptr;
            }
            else{
                temp=temp->lptr;
            }
        }
    }
    if(flag==0){
        cout<<"\n"<<key<<" not present."<<endl;
    }
}