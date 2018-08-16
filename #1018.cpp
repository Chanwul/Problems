#include<iostream>
using namespace std;

bool arr[52][52];
bool copy[52][52];
int n, m;
int MIN = INT32_MAX;

int go(int i, int j, int count)
{
	for (int x = i; x <= i + 7; x++)
		for (int y = j; y <= j + 7; y++)
		{
			if (x < i + 7)
			{
				if (arr[x][y] == arr[x + 1][y])
				{
					arr[x + 1][y] = !arr[x + 1][y];
					count++;
				}
			}
			if (y < j + 7)
			{
				if (arr[x][y] == arr[x][y + 1])
				{
					arr[x][y + 1] = !arr[x][y + 1];
					count++;
				}
			}
		}

	for (int x = i; x <= i + 7; x++)
		for (int y = j; y <= j + 7; y++)
			arr[x][y] = ::copy[x][y];
	return count;
}

int main()
{
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			char x;
			cin >> x;
			if (x == 'W')
				arr[i][j] = true;	//흰색
			else
				arr[i][j] = false;	//검은색
			::copy[i][j] = arr[i][j];
		}
	}
	for (int i = 1; i <= n - 7; i++)
		for (int j = 1; j <= m - 7; j++)
		{
			arr[i][j] = !arr[i][j];
			int a = go(i, j, 1);
			int b = go(i, j, 0);
			int c;
			if (a > b)
				c = b;
			else c = a;
			if (::MIN > c)
				::MIN = c;
		}
	cout << ::MIN;
	return 0;
}