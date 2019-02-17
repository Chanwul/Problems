#include <iostream>
#include <cstdio>
using namespace std;

bool check[1001];
bool arr[1001][1001];
int n, m;

void go(int i)
{
	check[i] = true;
	for (int j = 1; j <= n; j++)
		if (arr[i][j] == true && check[j] == false)
		{
			check[j] = true;
			go(j);
		}	
	return;
}

int main()
{
	int ans = 0;
	scanf("%d %d", &n, &m);
	for (int i = 0; i <= n; i++)
	{
		for (int j = 0; j <= n; j++)
			arr[i][j] = false;
		check[i] = false;
	}
		
	for (int i = 0; i < m; i++)
	{
		int a, b;
		scanf("%d %d", &a, &b);
		arr[a][b] = true;
		arr[b][a] = true;
	}
	for (int i = 1; i <= n; i++)
	{
		if (check[i] == false)
		{
			go(i);
			ans++;
		}
	}
	printf("%d", ans);
	return 0;
}