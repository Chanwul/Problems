#include<iostream>
#include<cstring>
#include<queue>
using namespace std;
int R;
int C;
char arr[20][20];
int check[20][20];
bool ans;

typedef struct node
{
	pair<int, int> pos;
	int val;
	int dir;
};

pair<int, int> move(int i, int j, int dir)
{
	if (dir == 1)	//left
		return make_pair(i, j - 1);
	else if (dir == 2)	//right
		return make_pair(i, j + 1);
	else if (dir == 3)	// up
		return make_pair(i - 1, j);
	else				// down
		return make_pair(i + 1, j);
}

void go(queue<node> q)
{
	node* cur;
	while (!q.empty())
	{
		cur = &q.front();
		q.pop();
		if (cur->pos.first == -1)
			cur->pos.first = R - 1;
		else if (cur->pos.first == R)
			cur->pos.first = 0;
		if (cur->pos.second == -1)
			cur->pos.second = C - 1;
		else if (cur->pos.second == C)
			cur->pos.second = 0;

		check[cur->pos.first][cur->pos.second]++;
		if (arr[cur->pos.first][cur->pos.second] == '@')
		{
			ans = true;
			return;
		}
		if (check[cur->pos.first][cur->pos.second] > 32)
			continue;
		else if (arr[cur->pos.first][cur->pos.second] == '<')
			q.push({ move(cur->pos.first, cur->pos.second,1),cur->val,1 });
		else if (arr[cur->pos.first][cur->pos.second] == '>')
			q.push({ move(cur->pos.first, cur->pos.second,2),cur->val,2 });
		else if (arr[cur->pos.first][cur->pos.second] == '^')
			q.push({ move(cur->pos.first, cur->pos.second,3),cur->val,3 });
		else if (arr[cur->pos.first][cur->pos.second] == 'v')
			q.push({ move(cur->pos.first, cur->pos.second,4),cur->val,4 });
		else if (arr[cur->pos.first][cur->pos.second] == '_')
		{
			if (cur->val == 0)
				q.push({ move(cur->pos.first, cur->pos.second,2),cur->val,2 });
			else
				q.push({ move(cur->pos.first, cur->pos.second,1),cur->val,1 });
		}
		else if (arr[cur->pos.first][cur->pos.second] == '|')
		{
			if (cur->val == 0)
				q.push({ move(cur->pos.first, cur->pos.second,4),cur->val,4 });
			else
				q.push({ move(cur->pos.first, cur->pos.second,3),cur->val,3 });
		}
		else if (arr[cur->pos.first][cur->pos.second] == '?')
		{
			q.push({ move(cur->pos.first, cur->pos.second,1),cur->val,1 });
			q.push({ move(cur->pos.first, cur->pos.second,2),cur->val,2 });
			q.push({ move(cur->pos.first, cur->pos.second,3),cur->val,3 });
			q.push({ move(cur->pos.first, cur->pos.second,4),cur->val,4 });
		}
		else if (arr[cur->pos.first][cur->pos.second] == '.')
			q.push({ move(cur->pos.first, cur->pos.second,cur->dir),cur->val,cur->dir });
		else if (isdigit(arr[cur->pos.first][cur->pos.second]))
			q.push({ move(cur->pos.first, cur->pos.second,cur->dir),arr[cur->pos.first][cur->pos.second]-48,cur->dir });
		else if (arr[cur->pos.first][cur->pos.second] == '+')
		{
			if (cur->val == 15)
				q.push({ move(cur->pos.first, cur->pos.second,cur->dir),0,cur->dir });
			else
				q.push({ move(cur->pos.first, cur->pos.second,cur->dir),cur->val + 1,cur->dir });
		}
		else if (arr[cur->pos.first][cur->pos.second] == '-')
		{
			if (cur->val == 0)
				q.push({ move(cur->pos.first, cur->pos.second,cur->dir),15,cur->dir });
			else
				q.push({ move(cur->pos.first, cur->pos.second,cur->dir),cur->val - 1,cur->dir });
		}
	}
}

int main()
{
	int T;
	cin >> T;
	for (int t = 1; t <= T; t++)
	{
		memset(check, 0, sizeof(check));
		cin >> R >> C;
		for (int i = 0; i < R; i++)
			for (int j = 0; j < C; j++)
				cin >> arr[i][j];
		::ans = false;
		queue<node> q;
		q.push({ make_pair(0,0),0,2 });
		go(q);

		if (::ans == false)
			cout << "#" << t << " NO" << endl;
		else
			cout << "#" << t << " YES" << endl;
	}

	return 0;
}