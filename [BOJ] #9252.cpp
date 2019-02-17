#include <cstdio>
#include <string>
#include <iostream>
#include <string.h>
#include <vector>
using namespace std;

int d[1001][1001];
bool check[1001][1001];

int main()
{
	string a, b;
	cin >> a >> b;
	memset(d, 0, sizeof(d));
	memset(check, false, sizeof(check));
	for(int i=1;i<=a.length();i++)
		for(int j = 1; j <= b.length(); j++)
		{
			if (a[i - 1] == b[j - 1])
			{
				d[i][j] = d[i - 1][j - 1] + 1;
				check[i][j] = true;
			}
			else
			{
				if (d[i - 1][j] < d[i][j - 1])
					d[i][j] = d[i][j - 1];
				else
					d[i][j] = d[i - 1][j];
			}
		}
	printf("%d\n", d[a.length()][b.length()]);
	int max = 0;
	int ta = 0, tb = 0;
	for (int i = 1; i <= a.length(); i++)
	{
		for (int j = 1; j <= b.length(); j++)
		{
			if (max <= d[i][j] && check[i][j] == true)
			{
				max = d[i][j];
				ta = i;
				tb = j;
			}
		}
	}
	if (d[a.length()][b.length()] > 0)
	{
		vector<char> ans;
		ans.push_back(a[ta - 1]);
		for (int i = ta; i >= 1; i--)
			for (int j = tb; j >= 1; j--)
			{
				if (check[i][j] == true && i < ta &&j < tb && d[i][j] == d[ta][tb]-1)
				{
					ta = i;
					tb = j;
					ans.push_back(a[i - 1]);
				}
			}
		for (int i = ans.size() - 1; i >= 0; i--)
			printf("%c", ans[i]);
	}
	return 0;
}