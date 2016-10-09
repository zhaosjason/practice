#include <iostream>

using namespace std;

int main() {
	int a; cin >> a;
	int b; cin >> b;
	int money = a + b;
	int cost; cin >> cost;
	int sodas = 0;

	while (money >= cost) {
		int c; c = money / cost;
		money = money - c * cost + c;
		sodas += c;
	}
	
	cout << sodas << endl;

	return 0;
}
