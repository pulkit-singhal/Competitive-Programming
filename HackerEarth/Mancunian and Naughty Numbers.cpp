#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define MAXN 100010
#define MOD 1000000007LL

int sieve[MAXN];

int main()
{
	for(int i=2;i<MAXN;++i)
		if(!sieve[i])
			for(int j=i;j<MAXN;j+=i)
				++sieve[j];
	int lim = 1;
	for(int d=1;d<=5;++d)
	{
		for(int i=lim;i<lim*10;++i)
			sieve[i] = (sieve[i] == d);
		lim *= 10;
	}
	sieve[lim] = (sieve[lim]==6);
	for(int i=1;i<MAXN;++i)
		sieve[i] += sieve[i-1];
	int q, a, b;
	cin >> q;
	while(q--)
	{
		cin >> a >> b;
		cout << sieve[b] - sieve[a-1] << endl;
	}
	return 0;
}
