#include<iostream>
using namespace std;
int n;
int arr[501][501];
int d[501][501];
int max(int a, int b)
{
	if (a > b)
		return a;
	else return b;
}
int main()
{
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= i; j++)
			cin >> arr[i][j];
	}
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= i; j++)
			d[i][j] = max(d[i - 1][j - 1], d[i - 1][j]) + arr[i][j];
	int MAX = 0;
	for (int i = 1; i <= n; i++)
		if (MAX < d[n][i])
			MAX = d[n][i];
	cout << MAX;

	return 0;
}