#include<iostream>
#include<cstring>
using namespace std;
int n;
bool check[10];
int arr[10][10];
pair<int, int> people[10];
pair<int, int> stair[2];
int p = 0, s = 0;
int dist[10];
int MIN = INT32_MAX;

int distance(pair<int, int> p, pair<int, int> s)
{
	int x = p.first - s.first;
	int y = p.second - s.second;
	if (x < 0)
		x = -x;
	if (y < 0)
		y = -y;
	return x + y;
}

int calc()
{
	int t1 = arr[stair[0].first][stair[0].second];
	int t2 = arr[stair[1].first][stair[1].second];
	int s1 = 0, s2 = 0;
	int count = 0;
	int dist1[10];
	bool wait[10];
	memset(wait, false, sizeof(wait));
	for (int i = 0; i < p; i++)
		dist1[i] = dist[i];
	int time = 0;
	while (count < p)
	{
		time++;
		for (int i = 0; i < p; i++)
		{
			if (dist1[i] < 0)
			{
				if (check[i] == false)
				{
					if (dist1[i] < -t1)
						continue;
					else if (dist1[i] == -t1)	//완료
					{
						s1--;
						count++;
						for (int a = 0; a < i; a++)	//대기하던 사람 입장
						{
							if (dist1[a] == 0 && check[a] == false && wait[a]==true)
							{
								dist1[a]--;
								wait[a] = false;
								s1++;
								break;
							}
						}
					}
					dist1[i]--;
				}
				else
				{
					if (dist1[i] < -t2)
						continue;
					if (dist1[i] == -t2)	//완료
					{
						s2--;
						count++; 
						for (int a = 0; a < i; a++)	//대기하던 사람 입장
						{
							if (dist1[a] == 0 && check[a] == true && wait[a] == true)
							{
								dist1[a]--;
								wait[a] = false;
								s2++;
								break;
							}
						}
					}
					dist1[i]--;
				}
			}
			else if (dist1[i] == 0)
			{
				if (check[i] == false)
				{
					if (s1 < 3)//진입 시작
					{
						dist1[i]--;
						wait[i] = false;
						s1++;
					}
					else
						wait[i] = true;
				}
				else
				{
					if (s2 < 3)	// 진입 시작
					{
						dist1[i]--;
						wait[i] = false;
						s2++;
					}
					else
						wait[i] = true;
				}
			}
			else
				dist1[i]--;
		}
	}
	return time;
}

void go(int len)
{
	if (len == p)
	{
		int time = calc();
		if (time < MIN)
		{
			MIN = time;
		}
		return;
	}

	check[len] = true;
	dist[len] = distance(people[len], stair[1]);
	go(len + 1);
	check[len] = false;
	dist[len] = distance(people[len], stair[0]);
	go(len + 1);
	return;
}
int main()
{
	int T;
	cin >> T;
	for (int t = 1; t <= T; t++)
	{
		p = 0; s = 0;
		MIN = INT32_MAX;
		memset(check, false, sizeof(check));
		cin >> n;
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
			{
				cin >> arr[i][j];
				if (arr[i][j] == 1)
					people[p++] = make_pair(i, j);
				else if (arr[i][j] > 1)
					stair[s++] = make_pair(i, j);
			}

		go(0);
		cout <<"#"<<t<<" "<< MIN<<endl;
	}
	return 0;
}