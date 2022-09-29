#include <bits/stdc++.h> // #include <queue>
using namespace std;

int main()
{
	priority_queue <int, vector<int>> pq; // greater<int>
	pq.push(1);
	pq.push(2);
	pq.push(3);
	while (!pq.empty())
	{
		cout << pq.top() << endl;
		pq.pop();
	}
	return 0;
}
