#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define MAXN 100010
#define MOD 1000000007LL

int main()
{
	int t;
	cin >> t;
	while(t--)
	{
		int n, res = 0;
		cin >> n;
		for(int i=1;i<=n;++i)
			for(int j=i+1;j<=n;++j)
				if((i^j)<=n)
					res++;
		cout << res << endl;
	}
	return 0;
}
