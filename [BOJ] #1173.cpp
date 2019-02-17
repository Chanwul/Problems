#include <iostream>
using namespace std;
int n, m, M, T, R;

int main()
{
	cin >> n >> m >> M >> T >> R;
	int num = 0;
	int cur = m;
	int t = 0;
	while (1)
	{
		if (m + T > M)
		{
			t = -1;
			break;
		}
		if (num == n)
			break;
		if (cur + T<=M)
		{
			num++;
			cur += T;
		}
		else if (cur + T > M)
		{
			cur -= R;
			if (cur < m)
				cur = m;
		}
		t++;
	}
	cout << t;
	return 0;
}