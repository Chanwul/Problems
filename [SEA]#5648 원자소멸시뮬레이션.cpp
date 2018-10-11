#include<iostream>
#include<string.h>
using namespace std;
int n;
pair<int, int> pos[1000];
int energy[1000];
int dir[1000];
int arr[2001][2001];
bool move[1000];
bool check[1000];
int diri[4] = { -1,1,0,0 };
int dirj[4] = { 0,0,-1,1 };
int opposite[4] = { 1,0,3,2 };

int go()
{
	int result = 0;
	while (1)
	{
		memset(::move, false, sizeof(::move));
		int count = 0;
		for (int i = 0; i < n; i++)
		{
			if (check[i] == true)
				count++;
		}
		if (count == n)
			break;
		for (int i = 0; i < n; i++)
		{
			if (dir[i] == 0 && pos[i].first == 0)
				check[i] = true;
			else if (dir[i] == 1 && pos[i].first == 2000)
				check[i] = true;
			else if (dir[i] == 2 && pos[i].second == 0)
				check[i] = true;
			else if (dir[i] == 3 && pos[i].second == 2000)
				check[i] = true;
			// ���� ��� ����� false
			if (check[i] == true)
				continue;
			int x = pos[i].first;
			int y = pos[i].second;
			for(int k=0;k<4;k++)
			if (dir[i] == k)
			{
				int xf = x + diri[k];
				int yf = y + dirj[k];
				if (arr[xf][yf] == -1)
				{
					if (arr[x][y] == i) //�߰��� �ٸ��ְ� �ȿ�����
						arr[x][y] = -1;//�ű��
					arr[xf][yf] = i;
					pos[i].first = xf;	//�̵�
					pos[i].second = yf;
					::move[i] = true;
				}
				else if (arr[xf][yf] != -1)	//���� ������
				{
					int j = arr[xf][yf];
					if (::move[j] == true)	//�굵 ������ ���̸�
					{
						result += energy[i] + energy[j];
						energy[i] = 0; energy[j] = 0; //�������� �Ұ�
						if (arr[x][y] == i)
							arr[x][y] = -1;	//�̵� (�ڽ��� �����) �����ִ��ִ� �״��
						check[i] = true;	//�����ٰ� ǥ��
						check[j] = true;
						::move[i] = true;
					}
					else if (arr[xf][yf] != -1 && dir[j] == opposite[k])//�ȿ����̰� ������ �ݴ�
					{
						result += energy[i] + energy[j];
						energy[i] = 0; energy[j] = 0; //�������� �Ұ�
						arr[xf][yf] = -1;	//�����
						arr[pos[j].first][pos[j].second] = -1; //�ٸ��ֵ� �����
						check[i] = true;	//�����ٰ� ǥ��
						check[j] = true;
					}
					else //���� �ȿ����γ� + ���⵵ ����(�浹 x)
					{
						if (arr[x][y] == i) //�߰��� �ٸ��ְ� �ȿ�����
							arr[x][y] = -1;//�ű��
						arr[xf][yf] = i;
						pos[i].first = xf;	//�̵�
						pos[i].second = yf;
						::move[i] = true;
					}
				}
			}
		}
		for (int i = 0; i < n; i++)
			if (check[i] == true)
				if (arr[pos[i].first][pos[i].second] == i)	//������ �ڸ��� �ȿԴٸ�
					arr[pos[i].first][pos[i].second] = -1;
	}
	return result;
}

int main()
{
	int T;
	cin >> T;
	for (int t = 1; t <= T; t++)
	{
		memset(arr, -1, sizeof(arr));
		memset(check, false, sizeof(check));
		cin >> n;
		for (int i = 0; i < n; i++)
		{
			int x, y, d, e;
			cin >> x >> y >> d >> e;
			pos[i].first = -y + 1000;
			pos[i].second = x + 1000;
			dir[i] = d;
			energy[i] = e;
			arr[pos[i].first][pos[i].second] = i;
		}
		cout <<"#"<<t<<" "<< go() << endl;
	}
}