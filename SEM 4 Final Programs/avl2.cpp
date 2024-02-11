/*Assignment  No.11 :  Implementation of an  AVL tree. */

#include<iostream>
using namespace std;

struct node
{  int data;
   node *left,*right;
   int ht;
};
class AVL
{ node *AVLroot;
  node *insert1(node *,int);//Recursive counterpart of insert
  node *Delete1(node *,int);//Recursive counterpart of delete
  void  preorder1(node *); //Recursive counterpart of preorder
  void  inorder1(node *); //Recursive counterpart of inorder
  int   height( node *);
  node *rotateright(node *);
  node *rotateleft(node *);
  node *RR(node *);
  node *LL(node *);
  node *LR(node *);
  node *RL(node *);
  int BF(node *);
  public:
     AVL()
      {
	AVLroot=NULL;
      }
     void insert(int x) { AVLroot=insert1(AVLroot,x);}
     void Delete(int x) { AVLroot=Delete1(AVLroot,x);}
     void preorder(){preorder1(AVLroot);}
     void inorder(){inorder1(AVLroot);}
     void levelwise();
     void makenull(){
		AVLroot=NULL;
	}
};
int main()
{
	AVL A;
	int x,n,i,op;
	do
		{
			cout<<"\n1)Create : ";
			cout<<"\n2)Insert : ";
			cout<<"\n3)Delete : ";
			cout<<"\n4)Print  : ";
			cout<<"\n5)Quit   : ";
			cout<<"\nEnter Your Choice : ";
			cin >> op;
			switch(op)
			    {
				case 1:cout<<"\nEnter no.of elements :";
				       cin>>n;
				       cout<<"\n Enter tree data :";
				       A.makenull();
				       for(i=0;i<n;i++)
					   {
						cin>>x;
						A.insert(x);
					   }
				       break;
				case 2:cout<<"\nEnter a data : ";
				       cin >>x;
				       A.insert(x);
				       break;
				case 3:cout<<"\nEnter a data : ";
				       cin >>x;
				       A.Delete(x);
				       break;
				case 4:	cout<<"\nPreorder sequence :\n";
					A.preorder();
					cout<<"\nInorder sequence :\n";
					A.inorder();
					cout<<"\nPreorder sequence :\n";
					A.preorder();
					//A.levelwise();
					break;
			     }

	}while(op!=5);

}
node * AVL::insert1(node *T,int x)
{
	if(T==NULL)
	{
		T=new node;
		T->data=x;
		T->left=NULL;
		T->right=NULL;
	}
	else
		if(x > T->data)                // insert in right subtree
		{
			T->right=insert1(T->right,x);
			if(BF(T)==-2)
				if(x>T->right->data)
					T=RR(T);
				else
					T=RL(T);
		}
		else
			if(x<T->data)
			{
				T->left=insert1(T->left,x);
				if(BF(T)==2)
					if(x < T->left->data)
						T=LL(T);
					else
						T=LR(T);
			}
			T->ht=height(T);
			return(T);
}

node * AVL::Delete1(node *T,int x)
{       node *p;

	if(T==NULL)
	{
		return NULL;
	}
	else

		if(x > T->data)                // insert in right subtree
		{
			T->right=Delete1(T->right,x);
			if(BF(T)==2)
				if(BF(T->left)>=0)
					T=LL(T);
				else
					T=LR(T);
		}
		else
			if(x<T->data)
				{
					T->left=Delete1(T->left,x);
					if(BF(T)==-2)//Rebalance during windup
						if(BF(T->right)<=0)
							T=RR(T);
						else
							T=RL(T);
				}
			else
			  {
			    //data to be deleted is found
			      if(T->right !=NULL)
				  {  //delete its inorder succesor
				      p=T->right;
				      while(p->left != NULL)
					  p=p->left;

				      T->data=p->data;
				      T->right=Delete1(T->right,p->data);
				      if(BF(T)==2)//Rebalance during windup
						if(BF(T->left)>=0)
							T=LL(T);
						else
							T=LR(T);
				   }
			      else
				   return(T->left);

			  }
	T->ht=height(T);
	return(T);
}

int AVL::height(node *T)
{
	int lh,rh;
	if(T==NULL)
		return(0);
	if(T->left==NULL)
		lh=0;
	else
		lh=1+T->left->ht;
	if(T->right==NULL)
		rh=0;
	else
		rh=1+T->right->ht;
	if(lh>rh)
		return(lh);
	return(rh);
}
node * AVL::rotateright(node *x)
{
	node *y;
	y=x->left;
	x->left=y->right;
	y->right=x;
	x->ht=height(x);
	y->ht=height(y);
	return(y);
}
node * AVL::rotateleft(node *x)
{
	node *y;
	y=x->right;
	x->right=y->left;
	y->left=x;
	x->ht=height(x);
	y->ht=height(y);
	return(y);
}

node * AVL::RR(node *T)
{
	T=rotateleft(T);
	return(T);
}
node * AVL::LL(node *T)
{
	T=rotateright(T);
	return(T);
}
node * AVL::LR(node *T)
{
	T->left=rotateleft(T->left);
	T=rotateright(T);
	return(T);
}
node * AVL::RL(node *T)
{
	T->right=rotateright(T->right);
	T=rotateleft(T);
	return(T);
}
int AVL::BF(node *T)
{
	int lh,rh;
	if(T==NULL)
	return(0);
	if(T->left==NULL)
		lh=0;
	else
		lh=1+T->left->ht;
	if(T->right==NULL)
		rh=0;
	else
		rh=1+T->right->ht;
	return(lh-rh);
}
void AVL::inorder1(node *T)
{
	if(T!=NULL)
	{
		inorder1(T->left);
		cout<<" "<<T->data<<"(Bf="<<BF(T)<<")";
		inorder1(T->right);
	}
}
void AVL::preorder1(node *T)
{
	if(T!=NULL)
	{
		cout<<" "<<T->data<<"(Bf="<<BF(T)<<")";
		preorder1(T->left);
		preorder1(T->right);
	}
}