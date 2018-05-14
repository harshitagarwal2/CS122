#include<iostream>
using namespace std;

#include<math.h>
int main() {
double a,b,c,root1,root2,re,im,disc;
cout<<"Enter the coefficients : ";
cin>>a>>b>>c;
disc=b*b-4*a*c;

if  (disc<0)
{
    cout<<"imaginary roots\n";
    re= - b / (2*a);
    im = pow(fabs(disc),0.5)/(2*a);
    cout<<re<<"+ i"<< im<<endl;
    cout<<re<<"-i"<< im<<endl;
 }
else if (disc==0){
         cout<<"real & equal roots"<<endl;
  re=-b / (2*a);
  cout<<"Roots are "<<re<<endl;
}

else { /*disc > 0*/
        cout<<"real & distinct roots"<<endl;
cout<<"Roots are ";
root1=(-b + sqrt(disc))/(2*a);
root1=(-b - sqrt(disc))/(2*a);
cout<<root1<<" and "<<root2;
}
}
