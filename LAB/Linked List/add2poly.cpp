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
    Node(int x =0,int y=0){ coef=x;exp=y; rlink=NULL;llink=NULL;}
};

class Poly{
    Node *first, *last;
public:
    Poly(){first = NULL;last =NULL;}
    void Create();
    void Display();
    void InsertLast(int x,int y);
    Poly operator+(Poly b);
    int compare(int a, int b){
        if (a==b) return 0;
        else if (a>b) return 1;
        else return -1;
    }
};


void Poly::InsertLast(int x, int y)
{
        Node *temp = new Node(x,y);

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
    int c,e;

    do
    {
        cout<<"Enter the coeff: [-99 to end] ";
        cin>>c;
        cout<<"Enter the exp : ";
        cin>>e;
        InsertLast(c,e);

    }while(c!=-99);

}

void Poly::Display()
{
    Node *temp = first;
    while(temp){
        if (temp->coef)
            cout<<temp->coef;
        if (temp->exp>1)
            cout<<"X^"<<temp->exp;
        else
            if (temp->exp==1)
                cout<<"X";



        temp=temp->rlink;
        //if (temp && temp->coef!=99 && temp->coef>0)
        if (temp)
            cout<<"+";


    }
    cout<<endl;
}

Poly Poly::operator+(Poly b){

    Node *p=first;
    Node *q=b.first;
    Poly c;

    while(p && q){

        switch(compare(p->exp,q->exp))
        {
            case 0: c.InsertLast(p->coef+q->coef,p->exp);
                    p=p->rlink;
                    q=q->rlink;
                    break;
            case 1: c.InsertLast(p->coef,p->exp);
                    p=p->rlink;
                    break;
            case -1: c.InsertLast(q->coef,q->exp);
                    q=q->rlink;
                    break;
        }
    }
    while(p){
        c.InsertLast(p->coef,p->exp);
        p=p->rlink;
    }
    while(q){
        c.InsertLast(q->coef,q->exp);
        q=q->rlink;
    }
    return c;
}
int main(){
    Poly a,b,c;

    cout<<"Creating the list : "<<endl;
    a.Create();
    a.Display();

    b.Create();
    b.Display();

    c=a+b;

    c.Display();

    return 0;

}
