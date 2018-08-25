#include<iostream>
#include<cstdio>
using namespace std;
int arr[3];
int question[100][5];
int n;
bool check[10];
int ans = 0;
int strike(int a)
{
	int cnt = 0;
	for (int i = 0; i < 3; i++)
		if (arr[i] == question[a][i])
			cnt++;
	return cnt;
}
int ball(int a)
{
	int cnt = 0;
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if (i != j && arr[i] == question[a][j])
				cnt++;
		}
	}
	return cnt;
}

void go(int len)
{
	if(len == 3)
	{
		for (int i = 0; i < n; i++)
		{
			if (strike(i) != question[i][3] || ball(i) != question[i][4])
				break;
			if (i == n-1)
				ans++;
		}
		return;
	}
	for (int i = 1; i <= 9; i++)
	{
		if (check[i] == false)
		{
			check[i] = true;
			arr[len] = i;
			go(len + 1);
			check[i] = false;
		}
	}
}

int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		for(int j=0;j<5;j++)
			scanf("%1d", &question[i][j]);
	}
	go(0);
	cout << ans;
	return 0;
}