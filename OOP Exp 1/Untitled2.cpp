# include <iostream>
# include <cmath>
using namespace std;

int main(void) {
	double x;
	double y;
	cout << "Input x:\n";
	cin >> x;
	if (x < -3) {
		y = (pow(x, 3) + 4) / pow(x,2);
		cout << y;
	}
	else if (-2 <= x and x < 0) {
		y = abs(pow(x, 2) + 3*x -10);
		cout << y;		
	}
	else if (0 <= x and x < 4) {
		y = pow(x,2) -4*x;
		cout << y;
	}
	else {
		cout << "Wrong input";
	}
	
	
	
	return 0;
}
