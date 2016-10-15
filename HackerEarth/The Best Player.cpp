#include <bits/stdc++.h>
using namespace std;

#define ll long long

bool cmp(pair<string, int> A, pair<string, int> B)
{
	if(A.second != B.second)
		return A.second > B.second;
	else
		return A.first < B.first;
}

int main()
{
	int n, t;
	cin >> n >> t;
	vector<pair<string, int> > v;
	while(n--)
	{
		cin >> name >> fq;
		v.push_back({name, fq});
	}
	sort(v.begin(), v.end(), cmp);
	for(int i=0;i<t;++i)
		cout << v[i].first << endl;
	return 0;
}
