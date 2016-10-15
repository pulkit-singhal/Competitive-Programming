#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define MAXN 500010
#define MAXK 11
#define MOD 1000000007LL

ll DP[MAXN][MAXK], pow2[MAXN];
int cnt[MAXN], k;

ll solve(int idx, int m)
{
	if(idx > k)
		return 1;
	if(DP[idx][m] != -1)
		return DP[idx][m];
	ll &res = DP[idx][m];
	res = 0;
	res += solve(idx+1, m);
	if(cnt[idx]>0 and m>0)
	{
		ll ways = pow2[cnt[idx]] - 1;
		if(ways<0)
			ways += MOD;
		res += ways * solve(idx+1, m-1);
		res %= MOD;
	}
	return res;
}

int main()
{
	pow2[0] = 1;
	for(int i=1;i<MAXN;++i)
	{
		pow2[i] = 2*pow2[i-1];
		if(pow2[i]>=MOD)
			pow2[i] -= MOD;
	}
	int n, m;
	cin >> n >> k >> m;
	int x;
	for(int i=0;i<n;++i)
	{
		cin >> x;
		++cnt[x];
	}
	memset(DP, -1, sizeof DP);
	cout << solve(0, m);
	return 0;
}
