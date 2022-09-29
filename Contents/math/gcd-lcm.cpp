#include <bits/stdc++.h>
using namespace std;

int gcd(int a, int b)
{
	if (b == 0) return a;
	return gcd(b, a%b);
}

int lcm(int a, int b)
{
	if (a < b) swap(a, b);
	return a / gcd(a, b) * a;
}

int main()
{
	int a, b;
	cin >> a >> b;
	cout << gcd(a, b) << endl << lcm(a, b) << endl;
	return 0;
}
