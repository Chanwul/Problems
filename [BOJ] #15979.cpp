#include<iostream>
#include<queue>
using namespace std;

int idx = 0;
long long arr[1000001];
queue<long long> q;
int n;

void bfs()
{
	while (!q.empty())
	{
		long long* cur = q.front();
		q.pop();
		if (idx == ::n + 1)
			break;
		if (cur > 9876543210)
			break;
		for (int i = 0; i <= 9; i++)
		{
			if (*cur % 10 > i)
			{
				q.push(*cur * 10 + i);
				::arr[idx++] = *cur * 10 + i;
			}
		}
	}
	return;
}

int main()
{
	cin >> n;
	for (int i = 0; i < 10; i++)	//i ��° 
	{
		arr[idx++] = i;
		q.push(i);
	}
	bfs();
	cout << ::arr[n];

	return 0;
}