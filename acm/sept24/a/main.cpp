#include <iostream>

using namespace std;

int main() {
	int cases;
	cin >> cases;
	for (int i = 0; i < cases; i++) {
		int ans = 0;
		int ships;
		int dist;
		cin >> ships;
		cin >> dist;

		for (int j = 0; j < ships; j++) {
			int speed, fuel, mpg;
			cin >> speed;
			cin >> fuel;
			cin >> mpg;

			double time = (double) dist / (double) speed;
			double needed_fuel = time * (double) mpg;

			if (needed_fuel <= fuel) 
				ans++;
		}

		cout << ans << endl;
	}

	return 0;
}