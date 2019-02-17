#include <iostream>
using namespace std;
long a, b;
int main()
{
	cin >> a >> b;
	if (a == 1)
		cout << 8 * b;
	else if (a == 5)
		cout << 4 + 8*b;
	else if (a > 1 && a < 5)
	{
		if (b % 2 == 0)
			cout << 4 * b + 1 + a - 2;
		else
			cout << 4 * b + 1 + 4 - a;
	}

	return 0;
}