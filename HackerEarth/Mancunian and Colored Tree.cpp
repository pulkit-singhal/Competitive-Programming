#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define MAXN 100010
#define MOD 1000000007LL

vector<int> adj[MAXN];
int C[MAXN], res[MAXN];
multiset<pair<int,int> > st[MAXN];

int dfs(int v, int p)
{
	int r = v;
	st[r].insert(make_pair(C[v], v));
	for(int i=0;i<adj[v].size();++i)
		if(adj[v][i]!=p)
		{
			int x = dfs(adj[v][i], v);
			if(st[r].size() < st[x].size())
				swap(r, x);
			for(multiset<pair<int,int> >::iterator it = st[x].begin(); it != st[x].end(); ++it)
				st[r].insert(*it);
			st[x].clear();
			multiset<pair<int,int> >::iterator it = st[r].lower_bound(make_pair(C[v], -1));
			vector<pair<int,int> > toDeleted;
			while(it != st[r].end() and (*it).first == C[v])
			{
				res[(*it).second] = v;
				toDeleted.push_back(*it);
				++it;
			}
			for(int i=0;i<toDeleted.size();++i)
				st[r].erase(toDeleted[i]);
		}
	return r;
}

int main()
{
	int n, c, x;
	cin >> n >> c;
	for(int i=2;i<=n;++i)
	{
		cin >> x;
		adj[i].push_back(x);
		adj[x].push_back(i);
	}
	for(int i=1;i<=n;++i)
		cin >> C[i];
	memset(res, -1, sizeof res);
	dfs(1, -1);
	for(int i=1;i<=n;++i)
		cout << res[i] << " ";
	return 0;
}
