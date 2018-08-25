#include<iostream>
using namespace std;

char arr[50][50];
int n;
int MAX = INT32_MIN;
int max(int a, int b)
{
	if (a > b)
		return a;
	else return b;
}

void swap(int i, int j, int a, int b)
{
	char temp = arr[i][j];
	arr[i][j] = arr[a][b];
	arr[a][b] = temp;
	return;
}
int count(int i, int j)
{
	int row = 1;
	int col = 1;
	int a = i - 1;
	char ans = arr[i][j];
	while (1)
	{
		if (arr[a][j] == ans)
		{
			row++;
			a--;
		}
		else
			break;
	}
	a = i + 1;
	while (1)
	{
		if (arr[a][j] == ans)
		{
			row++;
			a++;
		}
		else
			break;
	}
	a = j + 1;
	while (1)
	{
		if (arr[i][a] == ans)
		{
			col++;
			a++;
		}
		else
			break;
	}
	a = j - 1;
	while (1)
	{
		if (arr[i][a] == ans)
		{
			col++;
			a--;
		}
		else
			break;
	}
	if (row > col)
		return row;
	else return col;
}

int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> arr[i][j];
	for (int i = 0; i<n; i++)
		for (int j = 0; j < n; j++)
		{
			if (i < n - 1)
			{
				swap(i, j, i + 1, j);
				int temp1 = count(i, j);
				int temp2 = count(i + 1, j);
				if (MAX < max(temp1, temp2))
					MAX = max(temp1, temp2);
				swap(i, j, i + 1, j);
			}
			if (j < n - 1)
			{
				swap(i, j, i, j + 1);
				int temp1 = count(i, j);
				int temp2 = count(i, j + 1);
				if (MAX < max(temp1, temp2))
					MAX = max(temp1, temp2);
				swap(i, j, i, j + 1);
			}
		}
	cout << MAX;
	return 0;
}