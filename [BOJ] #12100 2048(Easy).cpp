#include<iostream>
#include<string.h>
using namespace std;

int arr[22][22];
bool check[22][22];
int maximum = 0;
int n;
int num = 0;

void up()
{
	for (int j = 1; j <= n; j++)
	{
		int a = 1;
		for (int i = 1; i <= n; i++)
		{
			if (arr[i][j] > 0)
			{
				int temp = arr[i][j];
				arr[i][j] = 0;
				arr[a++][j] = temp;
				if (arr[a - 2][j] == arr[a-1][j] && check[a - 2][j] == false)
				{
					arr[a - 2][j] += arr[a-1][j];
					check[a - 2][j] = true;
					a--;
					arr[a][j] = 0;
				}
			}
		}
	}
	memset(check, false, sizeof(check));
	return;
}

void down()
{
	for (int j = 1; j <= n; j++)
	{
		int a = n;
		for (int i = n; i >= 1; i--)
		{
			if (arr[i][j] > 0)
			{
				int temp = arr[i][j];
				arr[i][j] = 0;
				arr[a--][j] = temp;
				if (arr[a +2][j] == arr[a + 1][j] && check[a + 2][j] == false)
				{
					arr[a + 2][j] += arr[a + 1][j];
					check[a + 2][j] = true;
					a++;
					arr[a][j] = 0;
				}
			}
		}
	}
	memset(check, false, sizeof(check));
	return;
}

void left()
{
	for (int i = 1; i <= n; i++)
	{
		int a = 1;
		for (int j = 1; j <= n; j++)
		{
			if (arr[i][j] > 0)
			{
				int temp = arr[i][j];
				arr[i][j] = 0;
				arr[i][a++] = temp;
				if (arr[i][a-2] == arr[i][a-1] && check[i][a-2] == false)
				{
					arr[i][a-2] += arr[i][a-1];
					check[i][a-2] = true;
					a--;
					arr[i][a] = 0;
				}
			}
		}
	}
	memset(check, false, sizeof(check));
	return;
}

void right()
{
	for (int i = 1; i <= n; i++)
	{
		int a = n;
		for (int j = n; j >=1 ; j--)
		{
			if (arr[i][j] > 0)
			{
				int temp = arr[i][j];
				arr[i][j] = 0;
				arr[i][a--] = temp;
				if (arr[i][a + 2] == arr[i][a + 1] && check[i][a + 2] == false)
				{
					arr[i][a + 2] += arr[i][a + 1];
					check[i][a + 2] = true;
					a++;
					arr[i][a] = 0;
				}
			}
		}
	}
	memset(check, false, sizeof(check));
	return;
}

int max()
{
	int MAX = 0;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			if (arr[i][j] > MAX)
				MAX = arr[i][j];
	return MAX;
}

void go(int num)
{
	if (num == 5)
	{
		int t = max();
		if (t > ::maximum)
			::maximum = t;
		return;
	}
	int** copy = (int**)malloc(sizeof(int*)*(n+1));
	for (int i = 1; i <= n; i++)
		copy[i] = (int*)malloc(sizeof(int)*(n + 1));

	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			copy[i][j] = arr[i][j];

	up();
	go(num + 1);
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			arr[i][j] = copy[i][j];
	down();
	go(num + 1);
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			arr[i][j] = copy[i][j];
	left();
	go(num + 1);
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			arr[i][j] = copy[i][j];
	right();
	go(num + 1);
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			arr[i][j] = copy[i][j];
}

int main()
{
	memset(arr, -1, sizeof(arr));
	cin >> n;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			cin >> arr[i][j];
	go(0);
	cout << ::maximum;
	return 0;
}