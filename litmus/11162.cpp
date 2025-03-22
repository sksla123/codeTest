#include <iostream>
#include <string>
using namespace std;

int stoi(string& num) {
	int ret = 0;
	for (size_t i = 0; i < num.length(); i++) {
		if (num[i] < '0' || num[i] > '9')
			throw num[i];
		ret = ret * 10 + num[i] - '0';
	}
	return ret;
}

int main() {
    string x, y;
    cin >> x >> y;

    try {
        if (x[0] == '0' && x.length() > 1) throw string("Error: first number is 0");
        if (y[0] == '0' && y.length() > 1) throw string("Error: first number is 0");

        int n1 = ::stoi(x);
        int n2 = ::stoi(y);

        cout << "+: " << n1 + n2 << endl;
        cout << "-: " << n1 - n2 << endl;
        cout << "*: " << n1 * n2 << endl;

        if (n2 == 0) throw string("Error: y is 0");
        cout << "/: " << n1 / n2 << endl;

    }
    catch (char c) {
        cout << "Error: input character '" << c << "'" << endl;
    }
    catch (string& error) {
        cout << error << endl;
    }

    return 0;
}