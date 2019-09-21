#include <iostream>
int main(void) {
	int height = 50; //50 inches
	bool canRide;

	if(height >= 55) { //you must be at least 55 inches to ride
		canRide = true;
		std::cout << “You can ride!”;
	}
	else if(height >= 40) { //you must be at least 40 inches
		canRide = true;
		std::cout << “You can only ride with an adult.”
	}
	else { //less than 40 inches
		canRide = false;
		std::cout << “You cannot ride.”;
	}
	return 0;
}
