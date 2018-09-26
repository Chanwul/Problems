#include <iostream>
#include <string.h>
using namespace std;

int arr[1000][1000];
int age[1000][1000];
int n, m, k;
int diri[4] = { 0,-1,1,0 };
int dirj[4] = { 1,0,0,-1 };
pair<int, int> pos[100000];
int num = 0;


int main()
{
	int T;
	cin >> T;
	for (int t = 1; t <= T; t++)
	{
		memset(arr, 0, sizeof(arr));
		memset(age, -1, sizeof(age));
		memset(pos, 0, sizeof(pos));
		num = 0;
		cin >> n >> m >> k;
		for (int i = 400; i < 400 + n; i++)
			for (int j = 400; j < 400 + m; j++)
			{
				cin >> arr[i][j];
				if (arr[i][j] != 0)
				{
					pos[num++] = make_pair(i, j);
					age[i][j] = 0;
				}
			}
		for(int i=0;i<k;i++)
		{
			for (int x = 0; x < num; x++)
			{
				pair<int, int>  cur = pos[x];
				int aget = age[cur.first][cur.second];
				if (aget >= k)
					break;
				if (aget >= arr[cur.first][cur.second])		//번식 시작
				{
					for (int a = 0; a < 4; a++)
					{
						int ni = diri[a] + cur.first;
						int nj = dirj[a] + cur.second;
						if (arr[ni][nj] == 0)	//비어있으면 번식
						{
							arr[ni][nj] = arr[cur.first][cur.second];
							pos[num++] = make_pair(ni, nj);
							age[ni][nj] = -1;
						}
						else if (age[ni][nj] == -1 && arr[ni][nj] > 0 && arr[ni][nj] < arr[cur.first][cur.second])	//안비었는데 방금 생긴거라면
							arr[ni][nj] = arr[cur.first][cur.second];	// 기존 것 없애고 더 큰놈으로 대체
					}
				}
				age[cur.first][cur.second]++;
			}
		}
		int cnt = 0;
		int n = 0;
		for (int i = 0; i < 800; i++)
			for (int j = 0; j < 800; j++)
			{
				if (arr[i][j] != 0 && age[i][j] < 2 * arr[i][j])
					cnt++;
			}
		cout<<"#"<<t<<" "<<cnt<<endl;
	}
	return 0;
}