#include <iostream>
using namespace std;

void tower (int n, char  source, char temp, char destination)
{
	if(n==1)
	{
	     cout<<"move disk 1 from "<<source<<" to "<<destination<<endl;
	     return;
	}

	/*moving n-1 disks from A to B using C as auxiliary*/
	tower(n-1, source, destination, temp);

	cout<<"move disk "<<n<<" from "<<source<<" to "<<destination<<endl;

	/*moving n-1 disks from B to C using A as auxiliary*/
	tower(n-1, temp, source, destination);
}

int main(){

   tower(4,'A', 'B','C');
}
