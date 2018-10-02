#include<iostream>
#include<string.h>
using namespace std;

int n;
int arr[10][10];
int target[10];
int capa[2] = { 0,0 };
pair<int, int> people[10];
int pNum = 0;
pair<int, int> stair[10];
int sNum = 0;
int MIN = INT32_MAX;

int dist(pair<int, int> pe, pair<int, int> st)
{
	return abs(pe.first - st.first) + abs(pe.second - st.second);
}

int count()
{
	int distance[10];
	bool wait[10];
	bool finish[10];
	memset(wait, false, sizeof(wait));
	memset(finish, false, sizeof(finish));
	int t = 0;
	int num = 0;
	for (int i = 0; i < pNum; i++)
		distance[i] = dist(people[i], stair[target[i]]);
	while (num < pNum)
	{
		if (num == pNum)
			break;
		for (int i = 0; i < pNum; i++)
		{
			if (finish[i] == true)
				continue;

			if (distance[i] == -arr[stair[target[i]].first][stair[target[i]].second])	//�ٳ�����
			{
				capa[target[i]]--;
				finish[i] = true;	//����
				num++;
				if (capa[target[i]] == 2)
				{
					for (int x = 0; x < i; x++)	//��ٸ����� �ϳ� ����
						if (distance[x] == 0 && wait[x] == true && target[x] == target[i] && finish[x] == false)
						{
							distance[x]--;
							capa[target[x]]++;
							wait[x] = false;
							break;
						}
				}
			}
			else if (distance[i] > 0)	//���� �������� ������
				distance[i]--;
			else if (distance[i] == 0 && capa[target[i]] < 3)	//������ �� ������
			{
				distance[i]--;
				capa[target[i]]++;
			}
			else if (distance[i] == 0 && capa[target[i]] >= 3)	//��á���� ���
				wait[i] = true;
			else if (distance[i] < 0)	//�������� �����̸� �׳� ������
				distance[i]--;
		}
		t++;
	}
	return t;
}

void go(int i)
{
	if (i == pNum)
	{
		int temp = count();
		if (MIN > temp)
			MIN = temp;
		return;
	}
	target[i] = 0;
	go(i + 1);
	target[i] = 1;
	go(i + 1);
}

int main()
{
	int T;
	cin >> T;
	for (int t = 1; t <= T; t++)
	{
		cin >> n;
		memset(capa, 0, sizeof(capa));
		sNum = 0;
		pNum = 0;
		MIN = INT32_MAX;
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
			{
				cin >> arr[i][j];
				if (arr[i][j] == 1)
					people[pNum++] = make_pair(i, j);	//����� ��ġ
				else if (arr[i][j] > 1)
					stair[sNum++] = make_pair(i, j);	//��� ��ġ
			}
		go(0);
		cout << "#" << t << " " << MIN << endl;
	}
	return 0;
}