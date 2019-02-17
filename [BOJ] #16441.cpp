#include <cstdio>
#include <iostream>
#include <string.h>
#include <queue>
using namespace std;

int n, m;
bool check[100][100];
char arr[100][100];
int di[4] = { 0,0,1,-1 };
int dj[4] = { 1,-1,0,0 };
queue<pair<int, int>> q;

void go()
{
	pair<int, int> cur;
	while (!q.empty())
	{
		cur = q.front();
		q.pop();
		for (int i = 0; i < 4; i++)
		{
			int ni = cur.first + di[i];
			int nj = cur.second + dj[i];
			if (ni >= 0 && ni < n && nj >= 0 && nj < m)
			{
				if (check[ni][nj] == false)
				{
					if (arr[ni][nj] == 'W' || arr[ni][nj] == '.')	//ÃÊ¿ø
					{
						q.push(make_pair(ni, nj));
						check[ni][nj] = true;
					}
					else if (arr[ni][nj] == '+')	//ºùÆÇ±æ
					{
						int ti = ni;
						int tj = nj;
						if (di[i] == 1)
						{
							while (arr[ti][tj] == '+')
								ti++;
							if (arr[ti][tj] == '#')
								ti--;
						}
						else if (di[i] == -1)
						{
							while (arr[ti][tj] == '+')
								ti--;
							if (arr[ti][tj] == '#')
								ti++;
						}
						else if (dj[i] == -1)
						{
							while (arr[ti][tj] == '+')
								tj--;
							if (arr[ti][tj] == '#')
								tj++;
						}
						else if (dj[i] == 1)
						{
							while (arr[ti][tj] == '+')
								tj++;
							if (arr[ti][tj] == '#')
								tj--;
						}
						if (check[ti][tj] == false)
						{
							check[ti][tj] = true;
							q.push(make_pair(ti, tj));
						}
					}
				}
			}
		}
	}
	return;
}

int main()
{
	cin >> n >> m;
	memset(check, false, sizeof(check));
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
		{
			cin >> arr[i][j];
			if (arr[i][j] == 'W')
			{
				q.push(make_pair(i, j));
				check[i][j] = true;
			}
		}
	go();
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (arr[i][j] == '.' && check[i][j] == false)
				printf("P");
			else
				printf("%c", arr[i][j]);
		}
		printf("\n");
	}
	return 0;
}