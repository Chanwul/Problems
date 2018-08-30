#include<iostream>
using namespace std;

int arr[50][50];
pair<int, int> chicken[13];
pair<int, int> house[100];
bool check[13];
int n, m;
int Chicken = 0;
int House = 0;
int min = INT32_MAX;

int distance()
{
	int val = 0;
	for (int i = 0; i < House; i++)
	{
		int MIN = INT32_MAX;
		for (int j = 0; j < Chicken; j++)
		{
			if (check[j] == true)
			{
				int dist = abs(chicken[j].first - house[i].first) + abs(chicken[j].second - house[i].second);
				if (MIN > dist)
					MIN = dist;
			}
		}
		val += MIN;
	}
	return val;
}

void go(int len, int val, int i)
{
	if (i == Chicken || len == m)
	{
		if (len != 0)
		{
			if (::min > val)
			{
				::min = val;
			}
		}
		return;
	}

	check[i] = true;
	go(len + 1, distance(), i + 1);	// 고른다.
	check[i] = false;
	go(len, val, i + 1);	//안고른다.
}

int main()
{
	cin >> n >> m;
	for (int i = 0; i<n; i++)
		for (int j = 0; j < n; j++)
		{
			cin >> arr[i][j];
			if (arr[i][j] == 1)
				house[House++] = make_pair(i, j);
			else if (arr[i][j] == 2)
				chicken[Chicken++] = make_pair(i, j);
		}
	go(0, 0, 0);
	cout << ::min;

	return 0;
}