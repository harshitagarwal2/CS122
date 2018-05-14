#include<iostream>

using namespace std;
#include "queue.h"
const int Maxvertices=100;

class Graph;//forward decln
class Node{
    friend class Graph;
    friend class Queue<Node *,Maxvertices>;
private:
    int vertex;
    Node *link;
public:
    Node(int x =0){ vertex = x; link=NULL;}
};
class Graph{
    Node *G[Maxvertices];
    int n;
    int visited[Maxvertices];
public:
    Graph(int Noofvertices=0){
        n=Noofvertices;
    }
    void SetNULL(){
        for(int i=0;i<n;i++){G[i]=NULL;}
    }
    void ClearVisited(){
        for(int i=0;i<n;i++){visited[i]=0;}
    }
    void Create();
    Node *InsertRear(Node *, int);
    void Display();//display adjacency list
    void dfs(int v);
    void bfs(int v);


};
void Graph::Create()
{
	int i,v;

	cout<<"Enter the number of verices\n";
	cin>>n;
	SetNULL();//set the array of pointers to null
	for (i=0;i<n;i++)
	{
	 do
	   {
	   cout<<"Enter the next adjust vertex for vertex "<<i<<" : ";
	   cin>>v;
	   if (v<0) break;
	   G[i]= InsertRear(G[i],v);
	   }
	   while (1);
	}//for
 }

 Node * Graph::InsertRear(Node *h, int v)
 {
    Node *p= new Node(v);
    Node *temp = h;

    if (h==NULL)
        return p;
    else
    {
        while(temp->link!=NULL)
            temp=temp->link;
        temp->link=p;
	}
 return h;
 }

void Graph::Display()
{
    Node *temp;
    cout<<"Adjacency List : \n";
    for(int i=0;i<n;i++)
    {
        temp = G[i];
        cout<<i<<"\t";
        while (temp!=NULL)
        {
            cout<<temp->vertex<<"\t";
            temp=temp->link;
        }
        cout<<"\n";
    }
}
void Graph::dfs(int v)
{
    Node *w;

    cout<<v<<"\t";
    visited[v]=1;
    for (w=G[v];w;w=w->link)
    {
        if (!visited[w->vertex])
            dfs(w->vertex);
    }
}

void Graph::bfs(int v){
    Queue<int, Maxvertices> q;
    Node *w;
    ClearVisited();

    q.Insert(v);
    cout<<v<<"\t";
    visited[v]=1;
    while(!q.IsEmpty()){
        v= q.Delete();
        for(w= G[v];w;w=w->link){
            if (!visited[w->vertex]){
                cout<<w->vertex<<" ";
                visited[w->vertex]=1;
                q.Insert(w->vertex);
            }
        }
    }
}

int main()
{
	int i,j;

    Graph g;
	g.Create();

	g.Display();

    g.ClearVisited();
	cout<<"\nDepth first search \n";
	g.dfs(2);
	cout<<"\nBreadth first search\n";
	g.bfs(2);

}
