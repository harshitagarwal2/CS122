#include <iostream>
using namespace std;
#include<string.h>

template <class T>
T& larger( T& a, T& b){
    return a>b?a:b;

}
template<class T>
T &larger(T &a, T &b, T &c){
    T temp = larger(a, b);
    return (larger(temp,c));

}
char *larger(char *a, char *b){
    return strcmp(a,b)>0?a:b;

}
int main(){
     int x=10, y=2;
    cout<<"Larger among "<<x<<" and "<<y<<" = "<<larger(x,y)<<endl;

    float p =10.5, q=5.5;
    cout<<"Larger among "<<p<<" and "<<q<<" = "<<larger(p,q)<<endl;

    char *s1="Manipal";
    char *s2="Bangalore";

    cout<<"Larger among "<<s1<<" and "<<s2<<" = "<<larger(s1,s2)<<endl;


    int z=35;
    cout<<"Larger among "<<x<<" and "<<y<<" and "<<z<<" is "<<larger(x,y,z)<<endl;

    return 0;
}
