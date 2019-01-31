#include<cstdio>
#include<vector>
using namespace std;
typedef struct node
{
	int weight;
	int index;
};
int n, m;
int max(vector<node> q)
{
	int re = 0;
	for (int i = 0; i < q.size(); i++)
		if (re < q[i].weight)
			re = q[i].weight;
	return re;
}

int main()
{
	int T;
	scanf("%d", &T);
	for (int t = 0; t < T; t++)
	{
		vector<node> q;
		scanf("%d %d", &n, &m);
		for (int i = 0; i < n; i++)
		{
			int a;
			scanf("%d", &a);
			q.push_back({ a,i });
		}
		int cur = q[0].index;
		int num = 1;
		while (1) 
		{
			if (q[0].weight == max(q))
			{
				if (q[0].index == m)
					break;
				else
				{
					q.erase(q.begin());
					num++;
				}
			}
			else
			{
				q.push_back(q[0]);
				q.erase(q.begin());
			}
		}
		printf("%d\n", num);
	}
	return 0;
}