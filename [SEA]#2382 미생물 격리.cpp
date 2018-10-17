#include<iostream>
#include<string.h>
using namespace std;
int arr[101][101];
int map[101][101];
pair<int,int> cluster[1000];
int dir[1000];
int val[1000];
int n, m, k; //n-�Ѻ� ����, m-�ð�, k-����
int di[5] = { 0,-1,1,0,0 };
int dj[5] = { 0,0,0,-1,1 };

int go()
{
	for (int t = 0; t < m; t++)
	{
		for (int x = 0; x < k; x++)
		{
			int i = cluster[x].first;
			int j = cluster[x].second;
			int d = dir[x];
			int v = val[x];
			if (val[x] >0)	//���� ���������
			{
				int ni = i + di[d];
				int nj = j + dj[d];
				if (ni == 0 && dir[x] == 1)	//���� ��ǰ�� ����
				{
					map[ni][nj] = val[x] / 2;
					cluster[x].first = ni;	//�̵�
					cluster[x].second = nj;
					arr[ni][nj] = x;
					if (arr[i][j] == x)
						arr[i][j] = -1;
					dir[x] = 2;
				}
				else if (ni == n - 1 && dir[x] == 2)	//�Ʒ��� ��ǰ
				{
					map[ni][nj] = val[x] / 2;
					cluster[x].first = ni;	//�̵�
					cluster[x].second = nj;
					arr[ni][nj] = x;
					if (arr[i][j] == x)
						arr[i][j] = -1;
					dir[x] = 1;
				}
				else if (nj == 0 && dir[x] == 3)	// ���� ��ǰ
				{
					map[ni][nj] = val[x] / 2;
					cluster[x].first = ni;	//�̵�
					cluster[x].second = nj;
					arr[ni][nj] = x;
					if (arr[i][j] == x)
						arr[i][j] = -1;
					dir[x] = 4;
				}
				else if (nj == n - 1 && dir[x] == 4)	// ������ ��ǰ
				{
					map[ni][nj] = val[x] / 2;
					cluster[x].first = ni;	//�̵�
					cluster[x].second = nj;
					arr[ni][nj] = x;
					if (arr[i][j] == x)
						arr[i][j] = -1;
					dir[x] = 3;
				}
				else if (map[ni][nj] == 0)	//�ƹ��� ������
				{
					map[ni][nj] = val[x];  // map�� �� �ű�� 
					cluster[x].first = ni;	//�̵�
					cluster[x].second = nj;
					if (arr[i][j] == x)
						arr[i][j] = -1;
					arr[ni][nj] = x;
				}
				else if (map[ni][nj] > 0)	//������ ������ 
				{
					map[ni][nj] += val[x];	//�� ���� �����ְ�
					if (arr[i][j] == x)
						arr[i][j] = -1;	// �����ִ� �ڸ��� ����ش�
					if (val[arr[ni][nj]] < val[x])
					{
						cluster[x].first = ni;
						cluster[x].second = nj;
						val[arr[ni][nj]] = 0;	//���̰�
						arr[ni][nj] = x;	//���� ����
					}
					else		//���� �� ������
					{
						cluster[x].first = ni;
						cluster[x].second = nj;
						val[x] = 0;	//���� ����
					}
				}
			}
		}
		for (int x = 0; x < k; x++)
		{
			if (val[x]>0)
			{
				val[x] = map[cluster[x].first][cluster[x].second];	//map�� �ִ� ���� �ű�
				map[cluster[x].first][cluster[x].second] = 0;
			}
		}
	}
	int ans = 0;
	for (int x = 0; x < k; x++)
	{
		if (val[x] > 0)
			ans += val[x];
	}
	return ans;
}

int main()
{
	int T;
	cin >> T;
	for (int t = 1; t <= T; t++)
	{
		cin >> n >> m >> k;
		memset(map, 0, sizeof(map));
		memset(arr, -1, sizeof(arr));
		for (int i = 0; i < k; i++)
		{
			cin >> cluster[i].first >> cluster[i].second >> val[i] >> dir[i];	//�Է¹���
			arr[cluster[i].first][cluster[i].second] = i;
		}
		cout <<"#"<<t<<" "<< go()<<endl;
	}
	return 0;
}