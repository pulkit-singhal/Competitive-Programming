#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define MAXN 1000010
#define MAXB 320
#define MOD 1000000007LL

ll cnt[MAXN], A[MAXN], func[MAXN], ifunc[MAXN], res, f[MAXN];
int n, c, q;
pair<pair<int,int>, int> queries[MAXN];

bool cmp(pair<pair<int,int>, int> a, pair<pair<int,int>, int> b)
{
	int aBlock = a.first.first/MAXB,
		bBlock = b.first.first/MAXB;
	if(aBlock != bBlock)
		return aBlock < bBlock;
	else
		return a.first.second < b.first.second;
}

ll power(ll a, ll b)
{
	ll res = 1;
	while(b)
	{
		if(b&1)
		{
			res *= a;
			res %= MOD;
		}
		a *= a;
		a %= MOD;
		b /= 2;
	}
	return res;
}

void add(int x)
{
	res *= ifunc[cnt[x]];
	res %= MOD;
	++cnt[x];
	res *= func[cnt[x]];
	res %= MOD;
}

void remove(int x)
{
	res *= ifunc[cnt[x]];
	res %= MOD;
	--cnt[x];
	res *= func[cnt[x]];
	res %= MOD;
}

int main()
{
	cin >> n >> c >> q;
	for(int i=1;i<=n;++i)
		cin >> A[i];
	for(int i=0;i<=n;++i)
	{
		cin >> func[i];
		ifunc[i] = power(func[i], MOD-2);
	}
	res = 1;
	for(int i=1;i<=c;++i)
	{
		res *= func[0];
		res %= MOD;
	}
	for(int i=0;i<q;++i)
	{
		cin >> queries[i].first.first >> queries[i].first.second;
		queries[i].second = i;
	}
	sort(queries, queries + q, cmp);
	int moLeft = 1, moRight = 0;
	ll total = 1;
	for(int i=0;i<q;++i)
	{
		int left = queries[i].first.first,
			right = queries[i].first.second;
		while(moRight < right)
		{
			++moRight;
			add(A[moRight]);	
		}	
		while(left < moLeft)
		{
			--moLeft;
			add(A[moLeft]);
		}
		while(right < moRight)
		{
			remove(A[moRight]);
			--moRight;
		}
		while(moLeft < left)
		{
			remove(A[moLeft]);
			++moLeft;
		}
		total *= res;
		total %= MOD;
	}
	cout << total;
	return 0;
}
