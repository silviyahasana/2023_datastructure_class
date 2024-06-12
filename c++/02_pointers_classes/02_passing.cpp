#include <iostream>

using std::cout;
using std::endl;

void pass_value(int a){
	/* x is passed as an argument to parameter a
	 * a WILL NOT modify x
	 * a is not passed to the main func
	 * useful to copy value independently
	*/
	
	a += 10;
	cout << "Passing by value a+10" << endl;
	cout << "a = " << a << endl;
}

int pass_value_return(int aa){
	/* x is passed as an argument to parameter aa
	 * aa WILL NOT modify x
	 * aa is passed to the main func through return
	 * useful to copy value indpendently to be passed
	*/

	aa += 20;
	cout << "a is incremented by value" << endl;
	return aa;
}

void pass_reference(int& b){
	/* x is passed as a reference to parameter b
	 * b WILL modify x
	 * useful to save memory by using value in the same address
	*/
	
	b+=5;
	cout << "Passing by reference" << endl;
	cout << "b = " << b << endl;
	cout << "b = " << &b << endl;
}

void pass_pointer(int* c){

}

int main(){

	int x = 10;
	pass_value(x);
	cout << "x = " << x << endl;
	int pvr = pass_value_return(x);
	cout << "a being passed by value, returned " << pvr << endl;
	pass_reference(x);
	cout << "x = " << x << endl;
	cout << "x = " << &x << endl;
	return 0;
}
