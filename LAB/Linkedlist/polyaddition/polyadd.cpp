#include<iostream>
#include<cstdlib>
using namespace std;

class Poly;//forward decln
class Node{
    friend class Poly;
private:
    int coef;
    int exp;

    Node *rlink;
    Node *llink;
public:
    Node(int x =0){ data = x; rlink=NULL;llink=NULL;}
};

class Poly{
    Node *first, *last;
public:
    Poly(){first = NULL;last =NULL;}
    void Create();
    void Display();
    void InsertLast(int x);
    Poly operator+(Poly b);

};


void Poly::InsertLast(int x)
{
        Node *temp = new Node(x);

        if (first == NULL) //empty list
        {
            first = temp;
            last = temp;
            return ;
        }
        else
        {
            last->rlink = temp;
            temp->llink = last;
            last = temp;
        }
}


void Poly::Create(){
    int item;
    cout<<"Enter the number to be inserted: [-99 to end] ";
    cin>>item;
    while(item!=-99)
    {
        InsertLast(item);
        cout<<"Enter the number to be inserted: [-99 to end] ";
        cin>>item;

    }

}

void Poly::Display()
{
    Node *temp = first;
    while(temp){
        cout<<temp->data<<"  ";
        temp=temp->rlink;
    }
    cout<<endl;
}
int main(){
    Poly a,b,c;

    cout<<"Creating the list : "<<endl;
    a.Create();
    a.Display();

    b.Create();
    b.Display();

    c=a+b;

    return 0;

}
