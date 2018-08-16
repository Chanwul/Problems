#include<iostream>
using namespace std;

int main()
{
	long n, m;
	cin >> n >> m;
	if (n < 0)
		n = -n;
	if (m < 0)
		m = -m;
	if (n == 0 && m == 0)
	{
		cout << 0;
		return 0;
	}
	if (m == 0)
	{
		int temp = n;
		n = m;
		m = temp;
	}
	long x = n;
	long y = m;
	while (1)
	{
		long q = x / y;
		long w = x % y;
		if (w == 0)
			break;
		x = y;
		y = w;
	}
	if (y == 1)
		cout << 1;
	else
		cout << 2;


	return 0;
}