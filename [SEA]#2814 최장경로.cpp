#include<iostream>
#include<cstring>
using namespace std;
int n, m;
int arr[11][11];
bool check[11];
int MAX = INT32_MIN;

bool comp(int x)	//더이상 갈 데가 없으면 true
{
	for (int i = 1; i <= n; i++)
		if (check[i] == false && arr[x][i] == 1)
			return false;
	return true;
}

void go(int x, int len)
{
	if (comp(x))
	{
		if (MAX < len)
			MAX = len;
		return;
	}
	for (int i = 1; i <= n; i++)
		if (check[i] == false && arr[x][i] == 1)
		{
			check[i] = true;
			go(i, len + 1);
			check[i] = false;
		}
}

int main()
{
	int T;
	cin >> T;
	for (int t = 1; t <= T; t++)
	{
		memset(arr, 0, sizeof(arr));
		memset(check, false, sizeof(check));
		::MAX = INT32_MIN;
		cin >> n >> m;
		for (int a = 0; a < m; a++)
		{
			int x, y;
			cin >> x >> y;
			arr[x][y] = 1;
			arr[y][x] = 1;
		}
		for (int i = 1; i <= n; i++)
		{
			check[i] = true;
			go(i, 1);
			check[i] = false;
		}
		cout << "#" << t << " " << ::MAX << endl;
	}
}