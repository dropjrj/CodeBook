#include <bits/stdc++.h> // #include <map>
using namespace std;

int main()
{
	map<int, string> m = {{1, "Tom"}};
	m.insert(pair<int, string>(7, "Jack"));
	m[15] = "John";
	for (const auto& s : m) // map<int, string>::iterator it = m.begin()
	{
		cout << s.first << " " << s.second << endl;
	}
	m.erase(7);
	for (auto it = m.rbegin(); it!= m.rend(); it++)
	{
		cout << it->first << " " << it->second << endl;
	}
	m.clear;
	return 0;
}
