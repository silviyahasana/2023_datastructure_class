#include <iostream>

using std::cout;
using std::endl;

int main(){
	// normal var
	int x = 5;

	/* pointer
	 * 'new' keyword will dynamically allocate memory on the heap
	 *  instead of on the stack */
	int* y = new int(5);
	cout << "The pointer " << y << "points to " << *y << endl;

	/* 'delete' will deallocate memory associated with the object
	 * to avoid memory leak */
	delete y;
	return 0;
}
