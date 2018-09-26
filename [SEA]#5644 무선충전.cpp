#include<iostream>
#include<string.h>
using namespace std;

int M;
int A;
int arr[11][11];
bool check[9];
pair<int, int> BCpos[9];
int BCrange[9];
int BCval[9];
pair<int, int> posA[101];
pair<int, int> posB[101];
int MAX = INT32_MIN;

void readInfo(pair<int, int>* pos)
{
	for (int i = 1; i <= M; i++)
	{
		int temp;
		cin >> temp;
		if (temp == 0)
		{
			pos[i].first = pos[i - 1].first;
			pos[i].second = pos[i - 1].second;
		}
		else if (temp == 1)
		{
			pos[i].first = pos[i - 1].first - 1;
			pos[i].second = pos[i - 1].second;
		}
		else if (temp == 2)
		{
			pos[i].first = pos[i - 1].first;
			pos[i].second = pos[i - 1].second + 1;
		}
		else if (temp == 3)
		{
			pos[i].first = pos[i - 1].first + 1;
			pos[i].second = pos[i - 1].second;
		}
		else if (temp == 4)
		{
			pos[i].first = pos[i - 1].first;
			pos[i].second = pos[i - 1].second - 1;
		}
	}
	return;
}

bool BCcheck(pair<int, int> pos, int k)
{
	return ((abs(BCpos[k].first - pos.first) + abs(BCpos[k].second - pos.second)) <= BCrange[k]);
}

int go()
{
	int ans = 0;
	for (int t = 0; t <= M; t++)
	{
		int max = 0;
		for (int i = 1; i <= A; i++)
		{
			memset(check, false, sizeof(check));
			int result = 0;
			int temp = 0;
			if (BCcheck(posA[t], i))
			{
				check[i] = true;
				temp = BCval[i];
			}
			for (int j = 1; j <= A; j++)
			{
				result = temp;
				if (BCcheck(posB[t], j) && check[j] == false)
				{
					check[j] = true;
;					result += BCval[j];
				}
				if (result > max)
					max = result;
			}
		}
		ans += max;
	}
	return ans;
}
int main()
{
	int T;
	cin >> T;
	for (int t = 1; t <= T; t++)
	{
		memset(arr, 0, sizeof(arr));
		MAX = INT32_MIN;
		cin >> M >> A;
		posA[0] = make_pair(1, 1);
		posB[0] = make_pair(10, 10);
		readInfo(posA);
		readInfo(posB);
		for (int i = 1; i <= A; i++)
			cin >> BCpos[i].second >> BCpos[i].first >> BCrange[i] >> BCval[i];
		cout << "#" << t << " " << go() << endl;
	}
	return 0;
}