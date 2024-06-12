#include <iostream>

using std::cout;
using std::endl;

void print(int n){
	for (int i = 1; i < n; i *= 2){
		cout << i << endl;
	}
}

int main(){
	print(10);
	return 0;
}
