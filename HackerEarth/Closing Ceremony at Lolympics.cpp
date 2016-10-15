#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define MAXN 100010
#define MOD 1000000007LL

ll modpow(ll a, ll b)
{
	ll res = 1;
	while(b)
	{
		if(b&1)
		{
			res *= a;
			res %= MOD;
		}
		b /= 2;
		a *= a;
		a %= MOD;
	}
	return res;
}

ll DP[MAXN][2];

int main()
{
	int n, k;
	cin >> n >> k;
	vector<int> A(n);
	for(int i=0;i<n;++i)
		cin >> A[i];
	ll total = 0;
	for(int i=0;i<n;++i)
		total += A[i];
	if(total < 2*k)
		cout << 0;
	else
	{
		DP[0][1] = 1;
		for(int i=0;i<n;++i)
		{
			for(int j=0;j<k;++j)
				DP[j][0] = DP[j][1];
			for(int j=A[i];j<k;++j)
			{
				DP[j][1] += DP[j-A[i]][0];
				DP[j][1] %= MOD;
			}
		}	
		total = 0;
		for(int i=0;i<k;++i)
			total += DP[i][1];
		total = modpow(2, n) - total;
		total %= MOD;
		if(total < 0)
			total += MOD;
		cout << total;
	} 
	return 0;
}
