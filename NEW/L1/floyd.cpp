 #include<iostream>
using namespace std;
int main(){
    int n,i,j;

    cout<<"Enter no. of rows for the Floyd's triangle : ";
    cin>>n;
    cout<<"Floyd's Triangle for n = "<<n<<endl<<endl;
    int x=1;
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=i;j++)//number of natural nos to be printed in a row
        {
            cout<<x<<" ";
            x++;
        }
        cout<<endl;
    }


}
