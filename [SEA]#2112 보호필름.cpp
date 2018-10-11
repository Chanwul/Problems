#include <iostream>
#include <string.h>
using namespace std;
int d, w, k;
int arr[13][20];
int MIN;
int copy[13][20];

bool testSample(int j)
{
	int r = 1;
	for (int i = 0; i < d-1; i++)
	{
		if (arr[i][j] == arr[i + 1][j])
			r++;
		else
			r = 1;
		if (r >= k)
			return true;
	}
	return false;
}

bool test()
{
	for (int j = 0; j < w; j++)
		if (!testSample(j))
			return false;
	return true;
}

void go(int x, int val)
{
	if (test())
	{
		if (MIN > val)
			MIN = val;
		return;
	}

	if (x == d)
		return;
	if (val == k)
		return;
	for (int i = x; i < d; i++)
	{
		for (int j = 0; j < w; j++)	//0 약품 투입
			arr[i][j] = 0;
		go(i + 1, val + 1);
		for (int j = 0; j < w; j++)	//1 약품 투입
			arr[i][j] = 1;
		go(i + 1, val + 1);
		for (int j = 0; j < w; j++)	//되돌리기
			arr[i][j] = ::copy[i][j];
	}
}

int main()
{
	int T;
	cin >> T;
	for (int t = 1; t <= T; t++)
	{
		cin >> d >> w >> k;
		for (int i = 0; i < d; i++)
			for (int j = 0; j < w; j++)
			{
				cin >> arr[i][j];
				::copy[i][j] = arr[i][j];
			}
		MIN = k;
		go(0, 0);
		cout << "#" << t << " " << MIN << endl;
	}
}