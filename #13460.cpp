#include<iostream>
#include<string>
using namespace std;
int n, m;
char arr[10][11];
pair<int, int> goal;
int min = INT32_MAX;

pair<int, int> left(pair<int, int> ball)
{
	int i = ball.first;
	int j = ball.second;
	while (arr[i][j - 1] == '.')
		j--;
	if (arr[i][j - 1] == 'O')
	{
		j--;
		arr[ball.first][ball.second] = '.';
	}
	else
	{
		char temp = arr[ball.first][ball.second];
		arr[ball.first][ball.second] = '.';
		arr[i][j] = temp;
	}
	return make_pair(i, j);
}
pair<int, int> right(pair<int, int> ball)
{
	int i = ball.first;
	int j = ball.second;
	while (arr[i][j + 1] == '.')
		j++;
	if (arr[i][j + 1] == 'O')
	{
		j++;
		arr[ball.first][ball.second] = '.';
	}
	else
	{
		char temp = arr[ball.first][ball.second];
		arr[ball.first][ball.second] = '.';
		arr[i][j] = temp;
	}
	return make_pair(i, j);
}
pair<int, int> up(pair<int, int> ball)
{
	int i = ball.first;
	int j = ball.second;
	while (arr[i - 1][j] == '.')
		i--;
	if (arr[i - 1][j] == 'O')
	{
		i--;
		arr[ball.first][ball.second] = '.';
	}
	else
	{
		char temp = arr[ball.first][ball.second];
		arr[ball.first][ball.second] = '.';
		arr[i][j] = temp;
	}
	return make_pair(i, j);
}
pair<int, int> down(pair<int, int> ball)
{
	int i = ball.first;
	int j = ball.second;
	while (arr[i + 1][j] == '.')
		i++;
	if (arr[i + 1][j] == 'O')
	{
		i++;
		arr[ball.first][ball.second] = '.';
	}
	else
	{
		char temp = arr[ball.first][ball.second];
		arr[ball.first][ball.second] = '.';
		arr[i][j] = temp;
	}
	return make_pair(i, j);
}

void go(pair<int, int> blue, pair<int, int> red, int len, pair<int, int> befb, pair<int, int> befr)
{
	if (befr.first == red.first && befb.first == blue.first
		&&befr.second == red.second && befb.second == blue.second)
		return;
	if (len > 10)
		return;
	if (blue.first == goal.first&&blue.second == goal.second)
		return;
	if (red.first == goal.first && red.second == goal.second)
	{
		if (::min > len)
			::min = len;
		return;
	}
	char copy[10][11];
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			copy[i][j] = arr[i][j];
	pair<int, int> nextb;
	pair<int, int> nextr;
	if (blue.second > red.second)
	{
		nextb = right(blue);
		nextr = right(red);
	}
	else
	{
		nextr = right(red);
		nextb = right(blue);
	}
	go(nextb, nextr, len + 1, blue, red);

	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			arr[i][j] = copy[i][j];
	if (blue.second < red.second)
	{
		nextb = left(blue);
		nextr = left(red);
	}
	else
	{
		nextr = left(red);
		nextb = left(blue);
	}
	go(nextb, nextr, len + 1, blue, red);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			arr[i][j] = copy[i][j];

	if (blue.first > red.first)
	{
		nextb = down(blue);
		nextr = down(red);
	}
	else
	{
		nextr = down(red);
		nextb = down(blue);
	}
	go(nextb, nextr, len + 1, blue, red);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			arr[i][j] = copy[i][j];

	if (blue.first < red.first)
	{
		nextb = up(blue);
		nextr = up(red);
	}
	else
	{
		nextr = up(red);
		nextb = up(blue);
	}
	go(nextb, nextr, len + 1, blue, red);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			arr[i][j] = copy[i][j];

	return;
}
int main()
{
	pair<int, int> blue;
	pair<int, int> red;
	cin >> n >> m;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> arr[i][j];
	for (int i = 0; i<n; i++)
		for (int j = 0; j < m; j++)
		{
			if (arr[i][j] == 'B')
			{
				blue.first = i;
				blue.second = j;
			}
			else if (arr[i][j] == 'R')
			{
				red.first = i;
				red.second = j;
			}
			else if (arr[i][j] == 'O')
			{
				goal.first = i;
				goal.second = j;
			}
		}
	go(blue, red, 0, make_pair(0, 0), make_pair(0, 0));
	if (::min > 10)
		cout << -1;
	else cout << ::min;

	return 0;
}