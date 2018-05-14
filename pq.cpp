#include<iostream>
using namespace std;

int Q[100];
int Front,Rear;

int Maxsize=100;

void InsertPQ(int item){
    int i,j;
   if (Rear==Maxsize-1) { cout<<"Q Full"<<endl;return;}
    //find the position of insertion
    for(i=Front+1; i<=Rear;i++)
        if (Q[i]>item) break;

    if (i<=Rear) {//Check whether insertion is at the middle position of Queue
        //Shift the items to right
        for(j=Rear;j>=i;j--)
           Q[j+1]=Q[j];
    }
     Q[i]=item;
     Rear++;

}

int DeletePQ(){
  if (Front==Rear){cout<<"Q Empty"<<endl;return -1;}
  return Q[++Front];
}
int main()
{
    Front=Rear=-1;
    int item;
    cout<<"Insert Q elements : ";
    cin>>item;
    InsertPQ(item);
    cin>>item;
    InsertPQ(item);
    cin>>item;
    InsertPQ(item);
    cin>>item;
    InsertPQ(item);
    cout<<"\nQ Elements : ";
    for(int i=0;i<=Rear;i++)
        cout<<Q[i]<<"\t";
    cout<<"\nElement Deleted = " <<DeletePQ();
    cout<<"\nElement Deleted = " <<DeletePQ();
     cout<<"\nElement Deleted = " <<DeletePQ();
    cout<<"\nElement Deleted = " <<DeletePQ();
     cout<<"\nElement Deleted = " <<DeletePQ();

}
