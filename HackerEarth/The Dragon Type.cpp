#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define MAXN 100010
#define MOD 1000000007LL

ll power(ll a, ll b, ll c)
{
	ll res = 1;
	while(b)
	{
		if(b&1)
		{
			res *= a;
			res %= c;
		}
		b /= 2;
		a *= a;
		a %= c;
	}
	return res;
}

int main()
{
	int n, p;
	cin >> n >> p;
	vector<int> cnt(p);
	for(int i=0;i<n;++i)
	{
		ll x;
		cin >> x;
		x %= p;
		++cnt[x];
	}
	int res = cnt[0];
	for(int i=1;i<p;++i)
	{
		int j = power(i,p-2,p);
		if(i!=j)
		{
			res += max(cnt[i], cnt[j]);
			cnt[i] = cnt[j] = 0;
		}
	}
	cout << res;
	return 0;
}
