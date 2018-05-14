#include<iostream>
#include<typeinfo>
using namespace std;
template< class T >
class array {
private:
	int size;
	T *myarray;
public:

	array (int s) {
	size = s;
	myarray = new T [size];
	}

void setArray ( ) {
    T val;
    cout<<typeid( *myarray).name();
    cout<<"enter "<<size <<"  elements of the array\n";
    for(int i=0;i<size;i++)
    {
        cin>>val;
        myarray[i]=val;
    }

	}


void getArray () {
     for ( int i = 0; i< size; i++ ) {

        cout << myarray[ i ]<< endl;
	}

	}
};

int main()
{

array< int > int_array(2);
int_array.setArray();
cout<<"\nInteger Array\n";
int_array.getArray();

array< float > float_array(3);
float_array.setArray( );
cout<<"\nFloat Array\n";
float_array.getArray();

array< char > char_array(5);
char_array.setArray( );
cout<<"\nChar Array\n";
char_array.getArray();

return 0;
}
