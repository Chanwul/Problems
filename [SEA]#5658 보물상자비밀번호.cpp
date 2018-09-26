#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
int n, k;
int ref;
char arr[28];
long val[28];
int w = 0;

bool comparator(long right, long left)
{
	return right > left;
}

void rotate()
{
	char temp = arr[n-1];
	for (int i = n-1; i > 0; i--)
		arr[i] = arr[i-1];
	arr[0] = temp;
	return;
}

int main()
{
	int T;
	cin >> T;
	for (int t = 1; t <= T; t++)
	{
		w = 0;
		cin >> n >> k;
		::ref = n / 4;	// 한 변에 있는 수의 개수
		for (int i = 0; i < n; i++)
			cin >> arr[i];
		for (int i = 0; i < ::ref; i++)		//단어 개수 만큼 회전해야함
		{
			for (int j = 0; j < 4; j++)		// 네변 모두 확인
			{
				char* str = (char*)malloc(sizeof(char)*::ref);
				for (int k = 0; k < ::ref; k++)	//
					 str[k] = arr[j*(::ref) + k];
				val[w++] = strtol(str, NULL, 16);
			}
			rotate();
		}
		sort(val, val + w, comparator);
		int q = 1;
		for (int i = 0; i < w; i++)
		{
			if (q == k)
			{
				cout <<"#"<<t<<" "<< val[i]<<endl;
				break;
			}
			if (val[i] != val[i + 1])
				q++;
		}
	}
	return 0;
}