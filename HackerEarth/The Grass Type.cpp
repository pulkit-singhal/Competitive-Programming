#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define MAXN 100010
#define MOD 1000000007LL

vector<int> adj[MAXN];
map<int, int> mp[MAXN];
ll A[MAXN], res;

int dfs(int v, int p)
{
	int r = v;
	mp[r][A[r]]++;
	for(int i=0;i<adj[v].size();++i)
		if(adj[v][i]!=p)
		{
			int x = dfs(adj[v][i], v);
			if(mp[r].size() < mp[x].size())
				swap(r, x);
			for(map<int,int>::iterator it = mp[x].begin(); it != mp[x].end(); ++it)
				if((A[v] % it->first) == 0)
					res += it->second * mp[r][A[v]/(it->first)];
			for(map<int,int>::iterator it = mp[x].begin(); it != mp[x].end(); ++it)
				mp[r][it->first] += it->second;
		}
	return r;
}

int main()
{
	int n;
	cin >> n;
	int u, v;
	for(int i=1;i<n;++i)
	{
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	for(int i=1;i<=n;++i)
		cin >> A[i];
	dfs(1, -1);
	cout << res << endl;
	return 0;
}
