#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define MAXN 100
#define MOD 1000000007LL

set<ll> DP[MAXN];
pair<string,ll> ops[MAXN];
int n;
ll res;

void solve(int idx, ll val)
{
	if(idx == n)
	{
		res = max(res, val);
		return;	
	}	
	if(DP[idx].count(val))
		return;
	DP[idx].insert(val);
	if(DP[idx].size() > 2)
	{
		if(*DP[idx].begin() == val or *DP[idx].rbegin() == val)
			;
		else
		{
			DP[idx].erase(val);
			return;
		}
	}
	solve(idx+1, val);
	if(ops[idx].first == "+")
		solve(idx+1, val + ops[idx].second);
	else if(ops[idx].first == "-")
		solve(idx+1, val - ops[idx].second);
	else if(ops[idx].first == "*")
		solve(idx+1, val * ops[idx].second);
	else if(ops[idx].first == "/")
		solve(idx+1, val / ops[idx].second);
	else
		solve(idx+1, -val);
}

int main()
{
	int t;
	scanf("%d", &t);
	while(t--)
	{
		for(int i=0;i<MAXN;++i)
			DP[i].clear();
		scanf("%d", &n);
		for(int i=0;i<n;++i)
		{
			cin >> ops[i].first;
			if(ops[i].first != "N")
				cin >> ops[i].second;
		}
		res = 0;
		solve(0, 1);
		cout << res << endl;
	}
	return 0;
}
