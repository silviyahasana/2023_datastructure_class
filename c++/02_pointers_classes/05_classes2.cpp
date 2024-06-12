#include<iostream>
#include <string>

using std::cout;
using std::endl;
using std::string;

class Cookie{

	private:
		string color;

	public:
		Cookie(string color){
			this->color = color;
		}

		string getColor(){
			return color;
		}

		void setColor(string color){
			this->color = color;
		}
	
};

int main(){

	Cookie* cookieOne = new Cookie("Green");
	Cookie* cookieTwo = new Cookie("Blue");
	cout << "Cookie One = " << cookieOne->getColor()<< endl;
	cout << "Cookie Two = " << cookieTwo->getColor()<< endl;

	cookieTwo->setColor("Brown");

	cout << "Cookie One = " << cookieOne->getColor()<< endl;
        cout << "Cookie Two = " << cookieTwo->getColor()<< endl;
	return 0;
}
