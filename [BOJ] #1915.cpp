#include<cstdio>
#include<iostream>
using namespace std;
int arr[1001][1001];
int d[1001][1001];
int n, m;
int min(int a, int b)
{
	if (a > b)
		return b;
	else return a;
}

int go(int i, int j)
{
	if (arr[i][j] == 0)
		return 0;

	if (i == n || j == m)
		return arr[i][j];

	if (d[i][j] > 0)
		return d[i][j];

	d[i][j] = 1;

	int x = go(i + 1, j + 1);
	int y = go(i + 1, j);
	int z = go(i, j + 1);

	if (x > 0 && y > 0 && z > 0)
		d[i][j] = min(x, min(y, z)) + 1;

	return d[i][j];
}

int main()
{
	int max = INT32_MIN;
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
		{
			scanf("%1d", &arr[i][j]);
			if (i == n || j == m)
				d[i][j] = arr[i][j];
		}

	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			if (arr[i][j] == 1)
			{
				int a = go(i, j);
				if (a > max)
					max = a;
			}

	cout << max*max;
	return 0;
}