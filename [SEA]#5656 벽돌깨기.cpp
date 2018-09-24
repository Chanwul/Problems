#include<iostream>
using namespace std;
int n, w, h;
int MIN = INT32_MAX;
int arr[15][12];
int init[15][12];

void broken(int i, int j)
{
	if (arr[i][j] == 0)
		return;
	int temp = arr[i][j];
	arr[i][j] = 0;
	for (int x = i - temp + 1; x < i + temp; x++)
		if (x >= 0 && x < h && arr[x][j]!=0)
			broken(x, j);
	for (int y = j - temp + 1; y < j + temp; y++)
		if (y >= 0 && y < w&&arr[i][y] != 0)
			broken(i, y);
	return;
}

void setting()
{
	for (int j = 0; j < w; j++)
	{
		for (int i = h - 1; i >= 0; i--)
		{
			if (arr[i][j] == 0)
			{
				int k = i;
				while (arr[k][j] == 0 && k>0)
					k--;
				arr[i][j] = arr[k][j];
				arr[k][j] = 0;
			}
		}
	}
		return;
}
int count()
{
	int cnt = 0;
	for (int i = 0; i < h; i++)
		for (int j = 0; j < w; j++)
			if (arr[i][j] != 0)
				cnt++;
	return cnt;
}

void go(int num, int j)
{
	if (num == n)
	{
		int ans = count();
		if (MIN > ans)
			MIN = ans;
		return;
	}
	int ** copy = (int**)malloc(sizeof(int*)*h);
	for (int a = 0; a < h; a++)
		copy[a] = (int*)malloc(sizeof(int)*w);

	int k = 0;
	while (arr[k][j] == 0 && k<h-1)
		k++;

	broken(k, j);
	setting();
	for (int i = 0; i < h; i++)
		for (int j = 0; j < w; j++)
			copy[i][j] = arr[i][j];

	for (int i = 0; i < w; i++)
	{
		go(num + 1, i);
		for (int x = 0; x < h; x++)
			for (int y = 0; y < w; y++)
				arr[x][y] = copy[x][y];
	}
}

int main()
{
	int T;
	cin >> T;
	for (int t = 1; t <= T; t++)
	{
		::MIN = INT32_MAX;
		cin >> n >> w >> h;
		for (int i = 0; i < h; i++)
			for (int j = 0; j < w; j++)
			{
				cin >> arr[i][j];
				::init[i][j] = arr[i][j];
			}
		for (int i = 0; i < w; i++)
		{
			go(0, i);
			for (int x = 0; x < h; x++)
				for (int j = 0; j < w; j++)
					arr[x][j] = ::init[x][j];
		}
		cout <<"#"<<t<<" "<< ::MIN<<endl;
	}
	return 0;
}