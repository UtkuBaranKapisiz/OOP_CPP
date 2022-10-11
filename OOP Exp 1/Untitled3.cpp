# include <iostream>
# include <cmath>
using namespace std;

int main(void) {
	int x, y, z, max;
	cout << "Inputs: ";
	cin >> x;
	cin >> y;
	cin >> z;
	if (x > y) {
		if (x > z) {
			max = x;
		}
	}
	else if (y > z) {
		if (y > x) {
			max = y;
		}
	}
	else if (z > y) {
		if (z > x) {
			max = z;
		}
	}
	cout << "Max: " << max;
	
	return 0;
}
