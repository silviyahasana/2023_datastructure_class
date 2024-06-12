#include <iostream>

using std::cout;
using std::endl;

void print(int n){

	/*
	 * printed as many times as int(n)^2
	 */

	for (int i = 0; i < n; i ++){
		for (int j = 0; j < n; j++){
			cout << i <<  endl;
		}
	}
}

int main(){
	print(10);
	return 0;
}


