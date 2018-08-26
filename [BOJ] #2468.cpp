#include<iostream>
#include<queue>
#include<cstring>
using namespace std;
int n;
int total = 0;
int arr[100][100];
bool check[100][100];
int d1[4] = { -1,1,0,0 };
int d2[4] = { 0,0,1,-1 };
int MAX = INT32_MIN;

int find()
{
	int max = INT32_MIN;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			if (max < arr[i][j])
				max = arr[i][j];
	return max;
}

int go(int h)
{
	total = 0;
	memset(check, false, sizeof(check));
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			if (arr[i][j] > h)
				total++;
	for(int i=0;i<n;i++)
		for (int j = 0; j < n; j++)
		{
			queue<pair<int, int>> q;
			if (arr[i][j] > h && check[i][j]==false)
			{
				int cnt = 0;
				q.push(make_pair(i, j));
				check[i][j] = true;
				while (!q.empty())
				{
					pair<int, int> pos = q.front();
					q.pop();
					for (int a = 0; a < 4; a++)
					{
						int ni = pos.first + d1[a];
						int nj = pos.second + d2[a];
						if (ni >= 0 && ni < n && nj >= 0 && nj<n && arr[ni][nj]>h && check[ni][nj] == false)
						{
							q.push(make_pair(ni, nj));
							check[ni][nj] = true;
							cnt++;
						}
					}
				}
				total -= cnt;
			}
		}
	return total;
}

int count()
{
	int k = find();
	for (int h = 0; h < k; h++)
	{
		int ref = go(h);
		if (ref > MAX)
			MAX = ref;
	}
	return MAX;
}

int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> arr[i][j];
	cout << count();
	return 0;
}