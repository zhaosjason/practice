#include <iostream>

using namespace std;

int main() {
	while(1) {
		int num; cin >> num;

		if (num == -1)
			break;

		int sum = 1;
		string out = to_string(num) + " = 1 + ";
		for (int i = 2; i <= num / 2; i++) {
			if (num % i == 0) {
				out += to_string(i) + " + ";
				sum += i;
			}
		}

		if (sum == num)
			cout << out.substr(0, out.length() - 3) << endl;
		else
			cout << num << " is NOT perfect." << endl;
	}

	return 0;
}