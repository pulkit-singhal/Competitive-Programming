#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define MAXN 100010
#define MOD 1000000007LL

vector<int> adj[2][MAXN];

int main()
{
	int n, e, q, u, v;
	cin >> n >> e >> q;
	while(e--)
	{
		cin >> u >> v;
		adj[0][u].push_back(v);
		adj[1][v].push_back(u);
	}
	priority_queue<pair<int,int> > pq;
	vector<int> dist(n+1, MOD);
	dist[1] = 0;
	pq.push(make_pair(dist[1], 1));
	while(!pq.empty())
	{
		pair<int,int> p = pq.top();
		pq.pop();
		int c = dist[p.second], v = p.second;
		for(int i=0;i<adj[c&1][v].size();++i)
		{
			int u = adj[c&1][v][i];
			if(dist[u] > dist[v] + 1)
			{
				dist[u] = dist[v] + 1;
				pq.push(make_pair(-dist[u], u));
			}
		}
		int m = (1-(c&1));
		for(int i=0;i<adj[m][v].size();++i)
		{
			int u = adj[m][v][i];
			if(dist[u] > dist[v] + 2)
			{
				dist[u] = dist[v] + 2;
				pq.push(make_pair(-dist[u], u));
			}
		}
	}
	int sd = dist[n];
	while(q--)
	{
		cin >> u;
		if(u>=sd)
			cout << "GGMU" << endl;
		else
			cout << "FML" << endl;
	}
	return 0;
}
