#include <cstdio>
#include <vector>
using namespace std;

int target[50] = { 0 };
vector<int> second;
vector<int> third;

int go2(int t, int val)
{
	if (second[0] == t)
	{
		second.erase(second.begin());
		return val;
	}
	int temp = second[second.size() - 1];
	second.pop_back();
	second.insert(second.begin(), temp);
	go2(t, val + 1);
}
int go3(int t, int val)
{
	if (third[0] == t)
	{
		third.erase(third.begin());
		return val;
	}
	int temp = third[0];
	third.erase(third.begin());
	third.push_back(temp);
	go3(t, val + 1);
}

int main()
{
	int n, m;
	scanf("%d %d", &n, &m);
	for (int i = 0; i < m; i++)
		scanf("%d", &target[i]);
	for (int i = 1; i <= n; i++)
	{
		second.push_back(i);
		third.push_back(i);
	}
	int result = 0;
	for (int i = 0; i < m; i++)
	{
		int a = go2(target[i], 0);
		int b = go3(target[i], 0);
		if (a > b)
			result += b;
		else
			result += a;
	}
	printf("%d", result);
	return 0;
}