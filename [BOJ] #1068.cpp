#include<iostream>
using namespace std;
int n;
int cnt = 0;

int main()
{
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		if (i <= 99)
		{
			::cnt++;
			continue;
		}
		else if (i<1000)
		{
			int a = i % 10;
			int b = (i / 10) % 10;
			int c = ((i / 10) / 10) % 10;
			if (a - b == b - c)
				::cnt++;
		}
	}
	cout << ::cnt;
	return 0;
}