#include<iostream>
#include<queue>
using namespace std;
int n, m, h;
int arr[100][100][100];
int day = 0;

typedef struct node {
	int k;
	int i;
	int j;
	int day;
};
queue<node*> q;
bool check()
{
	for (int i = 0; i < h; i++)
		for (int j = 0; j < n; j++)
			for (int k = 0; k < m; k++)
				if (arr[i][j][k] == 0)
					return false;
	return true;
}

void bfs()
{
	node* cur;
	while (!q.empty())
	{
		cur = q.front();
		q.pop();
		day = cur->day;
		if (cur->k > 0 && arr[cur->k - 1][cur->i][cur->j] == 0)
		{
			node* a = (node*)malloc(sizeof(node));
			*a = { cur->k - 1, cur->i, cur->j, cur->day + 1 };
			arr[a->k][a->i][a->j] = 1;
			q.push(a);
		}
		if (cur->k < h-1 && arr[cur->k + 1][cur->i][cur->j] == 0)
		{
			node* a = (node*)malloc(sizeof(node));
			*a = { cur->k + 1, cur->i, cur->j, cur->day + 1 };
			q.push(a);
			arr[a->k][a->i][a->j] = 1;
		}
		if (cur->i > 0 && arr[cur->k][cur->i-1][cur->j] == 0)
		{
			node* a = (node*)malloc(sizeof(node));
			*a = { cur->k, cur->i-1, cur->j, cur->day + 1 };
			q.push(a);
			arr[a->k][a->i][a->j] = 1;
		}
		if (cur->i < n-1 && arr[cur->k][cur->i+1][cur->j] == 0)
		{
			node* a = (node*)malloc(sizeof(node));
			*a = { cur->k, cur->i + 1, cur->j, cur->day + 1 };
			q.push(a);
			arr[a->k][a->i][a->j] = 1;
		}
		if (cur->j > 0 && arr[cur->k][cur->i][cur->j-1] == 0)
		{
			node* a = (node*)malloc(sizeof(node));
			*a = { cur->k, cur->i, cur->j-1, cur->day + 1 };
			q.push(a);
			arr[a->k][a->i][a->j] = 1;
		}
		if (cur->j < m-1 && arr[cur->k][cur->i][cur->j+1] == 0)
		{
			node* a = (node*)malloc(sizeof(node));
			*a = { cur->k, cur->i, cur->j+1, cur->day + 1 };
			q.push(a);
			arr[a->k][a->i][a->j] = 1;
		}
	}
}

int main()
{
	cin >> m >> n >> h;
	for (int i = 0; i < h; i++)
		for (int j = 0; j < n; j++)
			for (int k = 0; k < m; k++)
			{
				cin >> arr[i][j][k];
				if (arr[i][j][k] == 1)
				{
					node* a1 = (node*)malloc(sizeof(node));
					*a1 = { i,j,k,0 };
					q.push(a1);
				}
			}
	bfs();
	if (check())
		cout << day;
	else
		cout << -1;
	return 0;
}