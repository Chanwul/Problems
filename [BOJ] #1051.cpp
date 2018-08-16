#include<iostream>
#include<cstdio>
using namespace std;

int arr[50][50];
int n, m;
int MAX = 1;

void go(int i, int j, int len)
{
	if (i + len - 1 >= n || j + len - 1 >= m)
		return;

	if (arr[i][j] == arr[i + len - 1][j] && arr[i][j] == arr[i + len - 1][j + len - 1] && arr[i][j] == arr[i][j + len - 1])
	{
		if (MAX < len*len)
			MAX = len*len;
	}
	go(i, j, len + 1);
}


int main()
{
	cin >> n >> m;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			scanf("%1d", &arr[i][j]);

	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			go(i, j, 2);

	cout << MAX;
	return 0;
}