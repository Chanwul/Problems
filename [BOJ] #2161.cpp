#include <cstdio>
#include <vector>
using namespace std;

vector<int> card;

int main()
{
	int m;
	scanf("%d", &m);
	for (int i = 1; i <= m; i++)
		card.push_back(i);
	while (card.size() > 1)
	{
		printf("%d ", card[0]);
		card.erase(card.begin());
		int temp = card[0];
		card.erase(card.begin());
		card.push_back(temp);
	}
	printf("%d", card[0]);
	return 0;
}