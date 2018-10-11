#include<iostream>
using namespace std;
int n;
int arr[20][20];
bool dessert[101];
int MAX = -1;

void dfs(int x, int y, int endi, int endj, int dir, int val)
{
	if (x == endi && y == endj)
	{
		if (MAX < val)
			MAX = val;
		return;
	}
	if (dir == 1)
	{
		if (x + 1 < n && y + 1 < n && dessert[arr[x + 1][y + 1]] == false)
		{
			dessert[arr[x + 1][y + 1]] = true;
			dfs(x + 1, y + 1, endi, endj, 1, val + 1);
			dessert[arr[x + 1][y + 1]] = false;
		}
		if (x + 1 < n && y - 1 >= 0 && dessert[arr[x + 1][y - 1]] == false)
		{
			dessert[arr[x + 1][y - 1]] = true;
			dfs(x + 1, y - 1, endi, endj, 2, val + 1);
			dessert[arr[x + 1][y - 1]] = false;
		}
	}
	else if (dir == 2)
	{
		if (x + 1 < n && y - 1 >= 0 && dessert[arr[x + 1][y - 1]] == false)
		{
			dessert[arr[x + 1][y - 1]] = true;
			dfs(x + 1, y - 1, endi, endj, 2, val + 1);
			dessert[arr[x + 1][y - 1]] = false;
		}
		if (x - 1 >=0 && y - 1 >= 0 && dessert[arr[x - 1][y - 1]] == false)
		{
			dessert[arr[x - 1][y - 1]] = true;
			dfs(x - 1, y - 1, endi, endj, 3, val + 1);
			dessert[arr[x - 1][y - 1]] = false;
		}
	}
	else if (dir == 3)
	{
		if (x - 1 >= 0 && y - 1 >= 0 && dessert[arr[x - 1][y - 1]] == false)
		{
			dessert[arr[x - 1][y - 1]] = true;
			dfs(x - 1, y - 1, endi, endj, 3, val + 1);
			dessert[arr[x - 1][y - 1]] = false;
		}
		if (x - 1 >= 0 && y + 1 < n && (x - 1 + y + 1) == (endi + endj) && dessert[arr[x - 1][y + 1]] == false)
		{
			dessert[arr[x - 1][y + 1]] = true;
			dfs(x - 1, y + 1, endi, endj, 4, val + 1);
			dessert[arr[x - 1][y + 1]] = false;
		}
	}
	else if (dir == 4)
	{
		if (x - 1 >= 0 && y + 1<n && (x - 1 + y + 1) == (endi + endj) && dessert[arr[x - 1][y + 1]] == false)
		{
			dessert[arr[x - 1][y + 1]] = true;
			dfs(x - 1, y + 1, endi, endj, 4, val + 1);
			dessert[arr[x - 1][y + 1]] = false;
		}
	}

}

int main()
{
	int T;
	cin >> T;
	for (int t = 1; t <= T; t++)
	{
		MAX = -1;
		cin >> n;
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				cin >> arr[i][j];
		for (int i = 0; i < n - 1; i++)
			for (int j = 1; j < n - 1; j++)
			{
				if (arr[i][j] != arr[i + 1][j + 1] && arr[i][j]!=arr[i+1][j-1] && arr[i+1][j-1]!=arr[i+1][j+1])
				{
					dessert[arr[i][j]] = true;
					dessert[arr[i + 1][j + 1]] = true;
					dfs(i + 1, j + 1, i+1, j-1, 1, 2);
					dessert[arr[i][j]] = false;
					dessert[arr[i + 1][j + 1]] = false;
				}
			}
		cout <<"#"<<t<<" "<< MAX << endl;
	}
	return 0;
}