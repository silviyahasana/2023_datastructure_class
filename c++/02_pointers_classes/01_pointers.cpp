#include <iostream>

using std::cout;
using std::endl;

void non_pointer(int& a){
        /* non pointer
        ¦* value will be copied */

	cout <<"---Reference---"<< endl;
    cout <<"Printing a = " << a << endl;
    cout <<"Printing &a = " << &a << endl;

    int& b = a;
	cout <<"-- refering int& b = a ---" << endl;
	cout <<"-- saving memory by refering to a's loc ---"<< endl;
    cout <<"Printing b = " << b << endl;
    cout <<"Printing &b = "<< &b << endl;
	
	cout << endl;
    cout << "---Reference can change value---" << endl;
	b+=5;
	cout << "b +=5" << endl;
    cout << "a = " << a << endl;
    cout << "b = " << b << endl;

    a = 20;
    cout << "Updated a value = " << a << endl;
    cout << "b value = " << b << endl;

}

void pointer_imp(int a){

    /* pointer
    ¦* value will always refer to the 
	¦* original value in said location 	
	*/

	int* b = &a;
	cout << "--- Pointer ---" << endl;
	cout << "int *b = &a" << endl;
	cout << "b = integer pointer, a = integer. b !=a" << endl;
    cout << "Pointer without * will print LOCATION " << endl;
	cout << "b = a --> b will refer to a's location" << endl;
    cout <<"a = " << a << endl;
	cout << "&a = " << &a << endl;
    cout << "b  = " << b << endl;

	cout << "Pointer with * will print VALUE " << endl;
	cout << "Known as dereferencing pointer" << endl;
    cout << "a = " << a << endl;
    cout << "*b = " << *b << endl;

    a = 20;
    cout << "Updated a value = " << a << endl;
    cout << "*b value = " << *b << endl;

}

int main(){
	int x = 10;
	non_pointer(x);
	pointer_imp(x);
	return 0;
}

