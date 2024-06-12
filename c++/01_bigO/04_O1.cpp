#include <iostream>

using std::cout;
using std::endl;

void print(int n){

	/*
	 * regardless int(n), execute 1x
	 */

	int sum = 0;
	sum += n;
	cout << sum << endl;
}

int main(){
	print(2);
	return 0;
}
