#include<iostream>
using namespace std;

int n, k;

int main()
{
	cin >> k >> n;
	int left = 210;
	int cur = k;
	for (int i = 0; i < n; i++)
	{
		int time;
		char answer;
		cin >> time >> answer;
		if (left >= time)
		{
			if (answer == 'T')
			{
				if (cur != 8)
					cur++;
				else
					cur = 1;
			}
			left -= time;
		}
	}
	cout << cur;
	return 0;
}