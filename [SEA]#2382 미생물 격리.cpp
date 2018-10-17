#include<iostream>
#include<string.h>
using namespace std;
int arr[101][101];
int map[101][101];
pair<int,int> cluster[1000];
int dir[1000];
int val[1000];
int n, m, k; //n-한변 길이, m-시간, k-개수
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
			if (val[x] >0)	//아직 살아있으면
			{
				int ni = i + di[d];
				int nj = j + dj[d];
				if (ni == 0 && dir[x] == 1)	//위쪽 약품에 묻음
				{
					map[ni][nj] = val[x] / 2;
					cluster[x].first = ni;	//이동
					cluster[x].second = nj;
					arr[ni][nj] = x;
					if (arr[i][j] == x)
						arr[i][j] = -1;
					dir[x] = 2;
				}
				else if (ni == n - 1 && dir[x] == 2)	//아래쪽 약품
				{
					map[ni][nj] = val[x] / 2;
					cluster[x].first = ni;	//이동
					cluster[x].second = nj;
					arr[ni][nj] = x;
					if (arr[i][j] == x)
						arr[i][j] = -1;
					dir[x] = 1;
				}
				else if (nj == 0 && dir[x] == 3)	// 왼쪽 약품
				{
					map[ni][nj] = val[x] / 2;
					cluster[x].first = ni;	//이동
					cluster[x].second = nj;
					arr[ni][nj] = x;
					if (arr[i][j] == x)
						arr[i][j] = -1;
					dir[x] = 4;
				}
				else if (nj == n - 1 && dir[x] == 4)	// 오른쪽 약품
				{
					map[ni][nj] = val[x] / 2;
					cluster[x].first = ni;	//이동
					cluster[x].second = nj;
					arr[ni][nj] = x;
					if (arr[i][j] == x)
						arr[i][j] = -1;
					dir[x] = 3;
				}
				else if (map[ni][nj] == 0)	//아무도 없으면
				{
					map[ni][nj] = val[x];  // map에 값 옮기고 
					cluster[x].first = ni;	//이동
					cluster[x].second = nj;
					if (arr[i][j] == x)
						arr[i][j] = -1;
					arr[ni][nj] = x;
				}
				else if (map[ni][nj] > 0)	//누군가 있으면 
				{
					map[ni][nj] += val[x];	//내 값을 더해주고
					if (arr[i][j] == x)
						arr[i][j] = -1;	// 원래있던 자리는 비워준다
					if (val[arr[ni][nj]] < val[x])
					{
						cluster[x].first = ni;
						cluster[x].second = nj;
						val[arr[ni][nj]] = 0;	//죽이고
						arr[ni][nj] = x;	//내가 차지
					}
					else		//내가 더 작으면
					{
						cluster[x].first = ni;
						cluster[x].second = nj;
						val[x] = 0;	//내가 죽음
					}
				}
			}
		}
		for (int x = 0; x < k; x++)
		{
			if (val[x]>0)
			{
				val[x] = map[cluster[x].first][cluster[x].second];	//map에 있는 값을 옮김
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
			cin >> cluster[i].first >> cluster[i].second >> val[i] >> dir[i];	//입력받음
			arr[cluster[i].first][cluster[i].second] = i;
		}
		cout <<"#"<<t<<" "<< go()<<endl;
	}
	return 0;
}