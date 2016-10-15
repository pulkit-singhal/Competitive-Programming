#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define MAXN 100010
#define MOD 1000000007LL

int visit[MAXN];

int main()
{
	int s, q, x;
	cin >> s >> q;
	while(q--)
	{
		cin >> x;
		if(visit[__gcd(s,x)])
			cout << -1 << endl;
		else
		{
			cout << __gcd(s,x) << endl;
			visit[__gcd(s,x)] = true;
		}			
	}
	return 0;
}
