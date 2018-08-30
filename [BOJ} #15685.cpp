#include<iostream>
#include<vector>
using namespace std;

bool arr[101][101];
pair<int, int> end;
int cnt = 0;
int di[4] = { 0,-1,0,1 };
int dj[4] = { 1,0,-1,0 };

void move(int g, vector<int> stk, int now)
{
	if (now == g)
		return;

	int cur = 0;
	for (int i = cnt; i >= 0; i--)
	{
		cur = stk[i];
		if (cur == 3)
		{
			::end.first += di[0];
			::end.second += dj[0];
			arr[::end.first][::end.second] = true;
			stk.push_back(0);
			cnt++;
		}
		else
		{
			::end.first += di[cur + 1];
			::end.second += dj[cur + 1];
			arr[::end.first][::end.second] = true;
			stk.push_back(cur + 1);
			cnt++;
		}
	}
	move(g, stk, now + 1);
}

int main()
{
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int x, y, d, g;
		vector<int> stk;
		cin >> y >> x >> d >> g;
		arr[x][y] = true;
		::cnt = 0;
		arr[x + di[d]][y + dj[d]] = true;
		::end = make_pair(x + di[d], y + dj[d]);
		stk.push_back(d);
		move(g, stk, 0);
	}
	int count = 0;
	for (int i = 0; i < 100; i++)
		for (int j = 0; j < 100;j++)
			if (arr[i][j] == true && arr[i + 1][j] == true && arr[i][j + 1] == true && arr[i + 1][j + 1] == true)
				count++;

	cout << count;
	return 0;
}