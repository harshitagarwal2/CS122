#include <iostream>

using namespace std;

long int fact(int n){
    if (n<=1)
        return 1;
    return (n*fact(n-1));

}
int main()
{
    int num;
    cout<<"Enter a number : ";
    cin>>num;
    long int f;

    f= fact(num);
    cout<<"Factorial = "<<f<<endl;
    return 0;
}
