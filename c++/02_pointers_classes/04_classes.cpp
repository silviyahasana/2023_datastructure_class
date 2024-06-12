#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::string;

class User{
	public:
		string name;
};

int main(){
	User u;
	u.name = "object_datastruc";
	cout << "class User = " <<  u.name << endl;

	/* initializing a new dynamic memory heap
	 * using pointer */

	User* u2 = new User();
	// assigning name by defrerencing the pointer
	(*u2).name = "object_datastruc_with_pointer";
	cout << "new class user using pointer = " << (*u2).name << endl;	
	// do not forget to delete
	delete u2;

	User* u3 = new User();
	u3->name = "object_datastruc_with_arrow";
	cout << "new class user using arrow pointer = " << u3->name << endl;
	delete u3;

	return 0;
}
