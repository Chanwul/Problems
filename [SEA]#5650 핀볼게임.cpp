#include<iostream>
#include<string.h>
using namespace std;

int check[102][102];
int arr[102][102];
int MAX = INT32_MIN;
int n;
int wormNum;
int wormVal[10];
pair<int, int> wormPos[10];
int initx, inity;

void go(int i, int j, int dir, int val)
{
	if (arr[i][j] == -1 || check[i][j] == true)
	{
		if (MAX < val)
			MAX = val;
		return;
	}
	check[initx][inity] = true;

	if (dir == 1)
	{
		if (j + 1 == n+1)//º®¿¡ ºÎµú
			go(i, j+1, 2, val + 1);
		else if (arr[i][j + 1] == 0)
			go(i, j + 1, 1, val);
		else if (arr[i][j+1] == 1 || arr[i][j+1] == 2 || arr[i][j+1] == 5)
			go(i, j + 1, 2, val + 1);
		else if (arr[i][j+1] == 3)
			go(i, j + 1, 3, val + 1);
		else if (arr[i][j+1] == 4)
			go(i, j + 1, 4, val + 1);
		else if (arr[i][j+1] >= 6 && arr[i][j+1] <= 10)	//¿úÈ¦¿¡ ºüÁü
		{
			for (int a = 0; a < wormNum; a++)
				if (wormVal[a] == arr[i][j+1] && (i != wormPos[a].first || j+1!= wormPos[a].second))
				{
					go(wormPos[a].first, wormPos[a].second, 1, val);
					break;
				}
		}
		else go(i, j + 1, dir, val);
	}
	else if (dir == 2)
	{
		if (j - 1 == 0)//º®¿¡ ºÎµú
			go(i, j-1, 1, val + 1);
		else if (arr[i][j-1] == 3 || arr[i][j-1] == 4 || arr[i][j-1] == 5)
			go(i, j - 1, 1, val + 1);
		else if (arr[i][j-1] == 1)
			go(i, j - 1, 4, val + 1);
		else if (arr[i][j-1] == 2)
			go(i, j - 1, 3, val + 1);
		else if (arr[i][j-1] >= 6 && arr[i][j-1] <= 10)	//¿úÈ¦¿¡ ºüÁü
		{
			for (int a = 0; a < wormNum; a++)
				if (wormVal[a] == arr[i][j-1] && (i != wormPos[a].first || j-1!= wormPos[a].second))
				{
					go(wormPos[a].first, wormPos[a].second, 2, val);
					break;
				}
		}
		else if (arr[i][j-1] == 0)	//ºÎµúÈ÷´Â °Í ¾øÀÌ
			go(i, j - 1, 2, val);

		else go(i, j - 1, dir, val);
	}
	else if (dir == 3)
	{
		if (i + 1 == n+1)//º®¿¡ ºÎµú
			go(i+1, j, 4, val + 1);
		else if (arr[i+1][j] == 2 || arr[i+1][j] == 3 || arr[i+1][j] == 5)
			go(i + 1, j, 4, val + 1);
		else if (arr[i+1][j] == 1)
			go(i + 1, j, 1, val + 1);
		else if (arr[i+1][j] == 4)
			go(i + 1, j, 2, val + 1);
		else if (arr[i+1][j] >= 6 && arr[i+1][j] <= 10)	//¿úÈ¦¿¡ ºüÁü
		{
			for (int a = 0; a < wormNum; a++)
				if (wormVal[a] == arr[i+1][j] && (i+1!= wormPos[a].first || j != wormPos[a].second))
				{
					go(wormPos[a].first, wormPos[a].second, 3, val);
					break;
				}
		}
		else if (arr[i+1][j] == 0)	//ºÎµúÈ÷´Â °Í ¾øÀÌ
			go(i + 1, j, 3, val);
		else go(i+1, j, dir, val);
	}
	else if (dir == 4)
	{
		if (i - 1 == 0)//º®¿¡ ºÎµú
			go(i-1, j, 3, val + 1);
		else if (arr[i-1][j] == 1 || arr[i-1][j] == 4 || arr[i-1][j] == 5)
			go(i - 1, j, 3, val + 1);
		else if (arr[i-1][j] == 2)
			go(i - 1, j, 1, val + 1);
		else if (arr[i-1][j] == 3)
			go(i - 1, j, 2, val + 1);
		else if (arr[i-1][j] >= 6 && arr[i-1][j] <= 10)	//¿úÈ¦¿¡ ºüÁü
		{
			for (int a = 0; a < wormNum; a++)
				if (wormVal[a] == arr[i-1][j] && (i-1 != wormPos[a].first || j != wormPos[a].second))
				{
					go(wormPos[a].first, wormPos[a].second, 4, val);
					break;
				}
		}
		else if (arr[i-1][j] == 0)	//ºÎµúÈ÷´Â °Í ¾øÀÌ
			go(i - 1, j, 4, val);
		else go(i - 1, j, dir, val);
	}

}

int main()
{
	int T;
	cin >> T;
	memset(arr, 0, sizeof(arr));
	memset(wormPos, 0, sizeof(wormPos));
	memset(wormVal, 0, sizeof(wormVal));
	for (int t = 1; t <= T; t++)
	{
		cin >> n;
		::MAX = -1;
		wormNum = 0;
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++)
			{
				cin >> arr[i][j];
				if (6 <= arr[i][j] && arr[i][j] <= 10)
				{
					wormPos[wormNum] = make_pair(i, j);
					wormVal[wormNum++] = arr[i][j];
				}
			}
		for(int i=1;i<=n;i++)
			for (int j = 1; j <= n; j++)
			{
				if (arr[i][j] == 0)
				{
					initx = i;
					inity = j;
					for (int k = 1; k <= 4; k++)
					{
						go(i, j, k, 0);
						check[initx][inity] = false;
					}
				}
			}
		cout <<"#"<<t<<" "<< ::MAX << endl;

	}
	return 0;
}