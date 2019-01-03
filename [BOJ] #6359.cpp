#include<iostream>
#include<string.h>
using namespace std;

int main()
{
	int T;
	cin >> T;
	bool d[101];
	for (int t = 0; t < T; t++)
	{
		int n;
		cin >> n;
		memset(d, false, sizeof(d));
		for (int i = 1; i <= n; i++)
		{
			for (int j = i; j <= n; j += i)
				d[j] = !d[j];
		}
		int cnt = 0;
		for (int i = 1; i <= n; i++)
			if (d[i])
				cnt++;
		cout << cnt << endl;
	}
	return 0;
}