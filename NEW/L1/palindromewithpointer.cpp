 #include<iostream>
using namespace std;

int main(){
    char str[100];
    char *p, *q;
    int palin = 1;

    cout<<"Enter a string : ";
    cin>>str;

    p=str;

    q=str;
    while(*q) q++;
    q--;

    while(p<q)
    {
        if (*p != *q){
            palin = 0;
            break;
        }
        p++;
        q--;

    }
    if (palin)
        cout<<"Palindrome";
    else
        cout<<"Not a Palindrome";
}
