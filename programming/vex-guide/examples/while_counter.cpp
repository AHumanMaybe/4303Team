#include <iostream>
int main(void) {
	int a = 1; //set a to 1
	while(a < 10) { //if a is less than 10, keep going
		std::cout << a << endl; //print the value
		a++; //increment by 1
	}
	std::cout << a;
	return 0;
}
