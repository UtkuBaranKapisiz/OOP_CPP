# include <iostream>
using namespace std;

int main(void) {
	double dis;
	double vel;
	cout << "Distance:\n";
	cin >> dis;
	cout << "Velocity:\n";
	cin >> vel;
	cout << "Final position is: " << dis << " meters\n" << "Final velocity is: " << vel << " m/s\n";
	double time = (dis/vel);
	cout << "Elapsed time is: " << time << " seconds";
	
	
	
	
	
	
	
	
	return 0;
}
