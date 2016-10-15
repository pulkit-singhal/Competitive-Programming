#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define MAXN 21
#define MOD 1000000007LL

int n, preq[MAXN];
ll DP[(1<<MAXN)];

ll solve(int mask)
{
	if(__builtin_popcount(mask) == n)
		return 1;
	if(DP[mask]!=-1)
		return DP[mask];
	ll &res = DP[mask];
	res = 0;
	for(int i=1;i<=n;++i)
		if(!(mask&(1<<i)))
		{
			int nmask = (preq[i] & mask);
			if(nmask == preq[i])
				res += solve(mask | (1<<i));
		}
	return res;
}

int main()
{
	cin >> n;
	for(int i=1;i<=n;++i)
		for(int j=1;j<=n;++j)
			if(i!=j)
				if((i&j)==i)
					preq[j] |= (1<<i);
//	for(int i=1;i<=n;++i)
//		cout << i << " :: " << preq[i] << endl;
	memset(DP, -1, sizeof DP);
	cout << solve(0);
	return 0;
}
