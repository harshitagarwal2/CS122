#include<iostream>
using namespace std;

struct Student{
    int rollno;
    char name[10];
    int sub1;
    int sub2;
    int total;
};

int main(){

    Student s1;
    int n,i;


    Student s[100];
    cout<<"Enter no of students : ";
    cin>>n;
    cout<<"Enter details : ";

    for (i=0;i<n;i++){
        cin>>s[i].rollno>>s[i].name>>s[i].sub1>>s[i].sub2;
        s[i].total = s[i].sub1 + s[i].sub2;
    }

    cout<<"Given details : ";
     for (i=0;i<n;i++){
        cout<<s[i].rollno<<" "<<s[i].name<<" "<<s[i].sub1<<" "<<s[i].sub2<<" " <<s[i].total<<endl;
    }
    int hs1=s[0].sub1;
    int hs2=s[0].sub2;
    int r1=s[0].rollno,r2=s[0].rollno;
    for(i=1;i<n;i++){
        if (hs1<s[i].sub1)
        {
            hs1=s[i].sub1;
            r1=s[i].rollno;
        }
        if (hs2<s[i].sub2)
        {
            hs2=s[i].sub2;
            r2=s[i].rollno;
        }


    }

    cout<<"Roll and highest marks "<<endl;
    cout<<r1<<hs1<<endl;
    cout<<r2<<hs2<<endl;


}
