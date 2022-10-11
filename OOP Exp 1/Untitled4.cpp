# include <iostream>
# include <cmath>
using namespace std;

int digitsum(int n)
{	int s;
    while (n != 0) {
      s = s + n % 10;
      n = n / 10;
    
}   return s;
}
int main(void) {
	int x, digit = 0, remain, sum=0;
	cin >> x;
	while (x != 0) {
		
		if (digit % 2 == 0) {
			sum = sum + (x % 10);
		}
		else {
			sum = sum + digitsum((x % 10) * 2);
		}
		++digit;
		int a=0;
		x = x / 10;
	}
	if (sum % 10 == 0) {
		cout << "Valid: " << sum;
	}
	else {
		cout << "Unvalid: "<< sum;
	}
	return 0;
}
