#include<iostream>
#include<queue>
#include <vector>
using namespace std;

int r, c;
char arr[50][50];
int di[4] = { 0, 0 ,1, -1 };
int dj[4] = { 1,-1, 0, 0 };
pair<int, int> src;
pair<int, int> dest;
vector<pair<int, int>> water;
vector<pair<int, int>> q;
bool wcheck[50][50];
bool check[50][50];
int map[50][50];		///0 : 물이 안찬곳 / 1: 물이 찬곳	/2: 돌	/3:비버 동굴
int answer = -1;

void go()
{
	int res = 0;
	while (q.size()>0)
	{
		if (res > r*c)
			return;
		int z = water.size();
		cout << q.size() << endl;
		for (int i = 0; i < z; i++)
		{
			for (int x = 0; x < 4; x++)
			{
				int ni = water[i].first + di[x];
				int nj = water[i].second + dj[x];
				if (ni >= 0 && ni < r && nj >= 0 && nj < c && wcheck[ni][nj] == false && map[ni][nj] == 0)
				{
					water.push_back(make_pair(ni, nj));
					map[ni][nj] = 1;
					wcheck[ni][nj] = true;
				}
			}
		}
		for (int i = 0; i < z; i++)
			water.erase(water.begin(), water.begin());
		int y = q.size();
		for (int i = 0; i < y; i++)
		{
			if (q[i] == dest)
			{
				answer = res;
				return;
			}
			for (int x = 0; x < 4; x++)
			{
				int ni = q[i].first + di[x];
				int nj = q[i].second + dj[x];
				if (ni >= 0 && ni < r && nj >= 0 && nj < c && check[ni][nj] == false && (map[ni][nj] == 0 || map[ni][nj] == 3))
				{
					q.push_back(make_pair(ni, nj));
					check[ni][nj] = true;
				}
			}
		}
		for (int i = 0; i < y; i++)
			q.erase(q.begin(), q.begin());
		res++;
	}
	return;
}

int main()
{
	cin >> r >> c;
	for (int i = 0; i < r; i++)
		for (int j = 0; j < c; j++)
		{
			map[i][j] = 0;
			cin >> arr[i][j];
			if (arr[i][j] == '*')
			{
				water.push_back(make_pair(i, j));
				map[i][j] = 1;
				wcheck[i][j] = true;
			}
			else if (arr[i][j] == 'S')
			{
				src = make_pair(i, j);
				q.push_back(make_pair(i, j));
				check[i][j] = true;
			}
			else if (arr[i][j] == 'D')
			{
				dest = make_pair(i, j);
				map[i][j] = 3;
			}
			else if (arr[i][j] == 'X')
				map[i][j] = 2;
		}
	go();
	if (answer == -1)
		cout << "KAKTUS";
	else
		cout << answer;
	return 0;
}