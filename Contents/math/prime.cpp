#include <bits/stdc++.h>
using namespace std;

#define maxn 100+5
vector<int> p;
bitset<maxn> is_notp;
void PrimeTable(int n)
{
    is_notp.reset();
    is_notp[0] = is_notp[1] = 1;
    for (int i = 2; i <= n; i++)
    {
        if (is_notp[i])
            continue;
        p.push_back(i);
        for (int j = i * i; j <= n; j += i)
        {
            is_notp[j] = 1;
        }
    }
}

int main()
{
	PrimeTable(100);
	cout << is_notp[3];
	return 0;
}
