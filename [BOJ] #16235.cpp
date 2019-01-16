#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int A[11][11];
int nutrients[11][11];
vector<int> map[11][11];
int n, m, k;
int di[8] = { -1,0,1,1,1,0,-1,-1 };
int dj[8] = { -1,-1,-1,0,1,1,1,0 };

void spring()
{
	for(int i=1;i<=n;i++)
		for (int j = 1; j <= n; j++)
		{
			if (!map[i][j].empty())
			{
				for (int l = map[i][j].size() - 1; l >= 0; l--)
				{
					if (nutrients[i][j] < map[i][j][l])
						map[i][j][l] *= -1;
					else
					{
						nutrients[i][j] -= map[i][j][l];
						map[i][j][l]++;
					}
				}
			}
		}
	return;
}

void summer()
{
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
		{
			if (!map[i][j].empty())
			{
				for (int l = map[i][j].size() - 1; l >= 0; l--)
				{
					if (map[i][j][l] < 0)
					{
						nutrients[i][j] += (-map[i][j][l]) / 2;
						map[i][j].erase(map[i][j].begin() + l);
					}
				}
			}
		}
	return;
}

void fall()
{
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
		{
			if (!map[i][j].empty())
			{
				for (int l = map[i][j].size() - 1; l >= 0; l--)
				{
					if (map[i][j][l] % 5 == 0)
					{
						for (int a = 0; a < 8; a++)
						{
							int ni = i + di[a];
							int nj = j + dj[a];
							if (ni >= 1 && ni <= n && nj >= 1 && nj <= n)
								map[ni][nj].push_back(1);
						}
					}
				}
			}
		}
	return;
}
void winter()
{
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			nutrients[i][j] += A[i][j];
	return;
}

int main()
{
	cin >> n >> m >> k;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
		{
			cin >> A[i][j];
			nutrients[i][j] = 5;
		}
	for (int i = 1; i <= m; i++)
	{
		int x, y, k;
		cin >> x >> y >> k;
		map[x][y].push_back(k);
	}
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
		{
			if (map[i][j].size()>1)
				sort(map[i][j].begin(), map[i][j].begin() + map[i][j].size() - 1);
		}
	for (int i = 0; i < k; i++)
	{
		spring();
		summer();
		fall();
		winter();
	}

	int answer = 0;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			answer += map[i][j].size();
	cout << answer;
	return 0;
}