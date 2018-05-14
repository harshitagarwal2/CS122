#include<iostream>
using namespace std;
int gcd( int A, int B)
{   if(A==0) return B;
    if(B==0) return A;
    if(A==B) return A;
    else return gcd(B, A% B);
}

int main()
{ cout<<gcd(6,10);
}
