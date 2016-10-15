#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define MAXN 100010
#define MOD 1000000007LL

int p[MAXN], n;
vector<ll> pr, A;

ll DP[505][64];

ll solve(int idx, int xorVal)
{
	if(idx==n)
		return xorVal > 0;
	if(DP[idx][xorVal] != -1)
		return DP[idx][xorVal];
	DP[idx][xorVal] = 0;
	DP[idx][xorVal] += solve(idx+1, xorVal);
	DP[idx][xorVal] += solve(idx+1, xorVal ^ A[idx]);
	DP[idx][xorVal] %= MOD;
	return DP[idx][xorVal];
}

long long mulmod(long long a,long long b,long long c){
    long long x = 0,y=a%c;
    while(b > 0){
        if(b%2 == 1){
            x = (x+y)%c;
        }
        y = (y*2)%c;
        b /= 2;
    }
    return x%c;
}

ll modpow(ll a, ll b, ll c)
{
	ll res = 1%c;
	while(b)
	{
		if(b&1)
			res = mulmod(res, a, c);
		b /= 2;
		a = mulmod(a, a, c);
	}
	return res;
}

bool Miller(ll p, int iteration)
{
    if(p<2)
        return false;
    if(p != 2 and p%2 == 0)
        return false;
    ll s = p-1;
    while(s%2 == 0)
        s /= 2;
    for(int i=0;i<iteration;i++)
	{
        ll a = rand()%(p-1)+1, temp = s;
    	ll mod = modpow(a, temp, p);
        while(temp != p-1 and mod != 1 and mod != p-1)
		{
            mod = mulmod(mod, mod, p);
            temp *= 2;
        }
        if(mod != p-1 and temp%2 == 0)
            return false;
    }
    return true;
}

int main()
{
	p[0] = p[1] = true;
	for(int i=2;i*i<MAXN;++i)
		if(!p[i])
			for(int j=i*i;j<MAXN;j+=i)
				p[j] = true;
	for(int i=0;i<MAXN;++i)
		if(!p[i])
			pr.push_back(i);
	cin >> n;
	A.resize(n);
	for(int i=0;i<n;++i)
	{
		cin >> A[i];
		int res = 0, pwr;
		for(int j=0;j<pr.size() and pr[j]*pr[j]*pr[j] <= A[i];++j)
			if((A[i]%pr[j])==0)
			{
				pwr = 0;
				while((A[i]%pr[j])==0)
				{
					A[i] /= pr[j];
					++pwr;
				}
				res += pwr;
			}
		if(A[i]!=1)
		{
			if(Miller(A[i], 40))
				res += 1;
			else
				res += 2;
		}
		A[i] = res;
	}
	memset(DP, -1, sizeof DP);
	cout << solve(0,0);
	return 0;
}
