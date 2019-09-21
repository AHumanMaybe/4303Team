#include <iostream>
int main(void) {
	int add = 10+5;     //add 10 and 5; total of 15
	std::cout << add << endl;
	//ignore “std::cout” lines, they print the result
	int sub = 10-5;     //subtract 10 by 5; difference of 5
	std::cout << sub << endl;
	int mult = 10*5;    //multiply 10 by 5; product of 50
	std::cout << mult << endl;
	int div = 10/5;     //divide 10 by five; quotient of 2
	std::cout << div << endl;
	int modzero = 10/5; //10 modulo 5; remainder of 0
	std::cout << modzero << endl;
	int modtwo = 12/5;  //12 modulo 5; remainder of 2
	std::cout << modtwo << endl;
}
