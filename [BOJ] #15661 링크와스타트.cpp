#include<iostream>
#include<string.h>

using namespace std;
int n;
int arr[20][20];
int team[20];
int MIN = INT32_MAX;

int count()
{
	int start = 0;
	int link = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (team[i] == 0 && team[j] == 0)
				start += arr[i][j];
			else if (team[i] == 1 && team[j] == 1)
				link += arr[i][j];
		}
	}
	if (start == 0 || link == 0)
		return INT32_MAX;
	else return abs(start - link);
}

void go(int i)
{
	if (i == n)
	{
		int temp = count();
		if (temp < ::MIN)
			::MIN = temp;
		return;
	}
	team[i] = 0;
	go(i + 1);
	team[i] = 1;
	go(i + 1);
}

int main()
{
	cin >> n;
	memset(team, -1, sizeof(team));
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> arr[i][j];
	go(0);
	cout << ::MIN;
	return 0;
}