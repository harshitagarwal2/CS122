#include<iostream>
#include<typeinfo>
using namespace std;
template< class T, int N >
class array {
private:
	//int size;
	T *myarray;
public:

	array ( ) {
	//size = s;
	myarray = new T [N];
	}

void setArray ( ) {
    T val;
    cout<<typeid( *myarray).name();
    cout<<"enter "<<N <<"  elements of the array\n";
    for(int i=0;i<N;i++)
    {
        cin>>val;
        myarray[i]=val;
    }

	}


void getArray () {
     for ( int i = 0; i< N; i++ ) {

        cout << myarray[ i ]<< endl;
	}

	}
};

int main()
{

array< int, 3 > int_array;
int_array.setArray();
cout<<"\nInteger Array\n";
int_array.getArray();

array< float , 2> float_array;
float_array.setArray();
cout<<"\nFloat Array\n";
float_array.getArray();

array< char,5 > char_array;
char_array.setArray();
cout<<"\nChar Array\n";
char_array.getArray();

return 0;
}
