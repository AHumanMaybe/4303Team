#include <iostream>

void sayHello(void) { //define function
	std::cout << “Hello!”; //prints “Hello!” to the console
	return; //this tells the compiler that there is nothing else in the function
}

int main(void) {
	sayHello(); //call (execute) the function
	return 0; //main should always return 0 so the program exits successfully
}
