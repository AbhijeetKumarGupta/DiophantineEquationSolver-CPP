#include <iostream>
using namespace std;

int main() {

	int val;
	float x = 0, xTemp = 2, xMax = 0, dMax = 0, y = 0, yTemp = 1, d = 0, f = 0;

	cin >> val;

	for (int i = 2; i <= val; i++) {

		// This loop check weather the current value of i is a valid value for D
		A: for (int j = 1; j < i; j++) {
			if (j * j == i) {
				i++;
				goto A;
			}
		}

		//If the value of i is valid then it is assigned to D
		d = i;

		//This stores the condition check to see weather it is right time to change the value of D or not
		bool conCheck;

		// This do while loop increments the value of xTemp
		do {

			//Initialize the value to false as it is not the right time to break out
			conCheck = false;

			// This loop increments the value of yTemp and checks the condition of the given equation
			// with the values of D, xTemp and yTemp
			do {

				//This is a derived formula for checking the equation where f stands for formula i.e.
				// D = (x^2 - 1) / y^2 , it is derived from the given equation x^2 - D * y^2 = 1
				f = ((xTemp * xTemp) - 1) / (yTemp * yTemp);

				//This condition checks if the value of f is equal to the value of d
				if (f == d) {

					//As our condition is satisfied we will assign the temporary value of X and Y to actual X and Y
					x = xTemp;
					y = yTemp;

					//It prints the condition to the console
					cout << x << " * " << x << " - " << d << " * " << y << " * "
							<< y << " = 1" << endl;

					//This checks if the value of x for this value of D is greater than any previous values
					if (x > xMax) {

						//If it is greater then we will assign the Max values to the Max variables
						xMax = x;
						dMax = d;
					}

					//Now we break out of the loop to get the next value of xTemp
					break;
				}
				yTemp++;
			} while (xTemp > yTemp);

			//Here we will increment the value of xTemp and reset the value of yTemp
			xTemp++;
			yTemp = 1;

			//This checks weather we have a satisfied condition or not to increment the value of D
			if (f == d) {
				//If we have satisfied the condition then it is the right time to change the value of D
				//and we will set the condition check to true
				conCheck = true;
			}
		} while (conCheck == false);

		//Now as we are going to begin with a new value of D we have to reset the value of xTemp also
		xTemp = 2;
	}

	//Finally print the value of max variables to the console
	cout << dMax;

	return 0;
}
