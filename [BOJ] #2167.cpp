#include<iostream>
using namespace std;
int n, m;
int arr[301][301];
int k;
int d[301][301];

int main()
{
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			cin >> arr[i][j];
	cin >> k;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			d[i][j] = d[i - 1][j] + d[i][j - 1] - d[i - 1][j - 1] + arr[i][j];
	for (int t = 0; t < k; t++)
	{
		int i, j, x, y;
		cin >> i >> j >> x >> y;
		int answer = d[x][y] - d[i - 1][y] - d[x][j - 1] + d[i - 1][j - 1];
		cout << answer << endl;
	}
	return 0;
}