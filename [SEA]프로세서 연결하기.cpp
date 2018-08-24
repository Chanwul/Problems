#include<cstring>
#include<iostream>
using namespace std;
int n;
int arr[13][13];
pair<int, int> cand[12];

int count = 0;
int MAX = INT32_MIN;
int MIN = INT32_MAX;

bool checkDir(int dir, int i, int j)
{
	if (dir == 1)	//up
	{
		for (int a = 0; a < i; a++)
			if (arr[a][j] != 0)
				return false;
	}
	else if (dir == 2)	//down
	{
		for (int a = n - 1; a > i; a--)
			if (arr[a][j] != 0)
				return false;
	}
	else if (dir == 3)	//left
	{
		for (int b = 0; b < j; b++)
			if (arr[i][b] != 0)
				return false;
	}
	else if (dir == 4)	//right
	{
		for (int b = n - 1; b > j; b--)
			if (arr[i][b] != 0)
				return false;
	}
	return true;
}
int connect(int dir, int val, int i, int j)
{
	int len = 0;
	if (dir == 1)
	{
		for (int a = 0; a < i; a++)
		{
			arr[a][j] = val;
			len++;
		}
	}
	else if (dir == 2)
	{
		for (int a = n - 1; a > i; a--)
		{
			arr[a][j] = val;
			len++;
		}
	}
	else if (dir == 3)
	{
		for (int b = 0; b < j; b++)
		{
			arr[i][b] = val;
			len++;
		}
	}
	else if (dir == 4)
	{
		for (int b = n - 1; b > j; b--)
		{
			arr[i][b] = val;
			len++;
		}
	}
	return len;
}

void go(int len, int val, int num)
{
	if (len == ::count)
	{
		if (::MAX < num)
		{
			::MAX = num;
			::MIN = val;
		}
		else if (::MAX == num)
		{
			if (::MIN > val)
				::MIN = val;
		}
		return;
	}
	if (cand[len].first == 0 || cand[len].first == n - 1 || cand[len].second == 0 || cand[len].second == n - 1)
	{
		go(len + 1, val, num);
		return;
	}

	for(int i=1;i<=4;i++)
		if (checkDir(i, cand[len].first, cand[len].second))
		{
			go(len + 1, val + connect(i, 2, cand[len].first, cand[len].second), num + 1);
			int k = connect(i, 0, cand[len].first, cand[len].second);
		}
	go(len + 1, val, num);
}

int main()
{
	int T;
	cin >> T;
	for (int t = 1; t <= T; t++)
	{
		::MIN = INT32_MAX;
		::MAX = INT32_MIN;
		::count = 0;

		cin >> n;
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
			{
				cin >> arr[i][j];
				if (arr[i][j] == 1)
					cand[::count++] = make_pair(i, j);
			}
		go(0, 0, 0);
		cout << "#" << t << " " << ::MIN << endl;
	}
	return 0;
}