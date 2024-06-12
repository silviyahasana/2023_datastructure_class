#include <iostream>

using std::cout;
using std::endl;

int main(){
	for (int i = 0; i < 10; i++){
		for (int j =0; j <10; j++){
			cout << i << j << endl;
		}
	}

	/*
	 * time complexity 2nd loop < 1st loop
	 * drop time complexity of 2nd loop
	 * time complexity = O(n)^2
	 */
	for (int k =0; k < 10; k++){
		cout << k << endl;
	}

	return 0;
}
