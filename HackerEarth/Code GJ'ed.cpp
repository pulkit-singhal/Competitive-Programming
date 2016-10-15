#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define MAXN 1000010
#define MOD 1000000007LL

int A[MAXN];

int main()
{
	int t;
	scanf("%d", &t);
	while(t--)
	{
		int n;
		scanf("%d", &n);
		for(int i=0;i<n;++i)
			scanf("%d", A[i]);
		ll sum, res = 0;
		sort(A, A+n);
		sum = A[n-1];
		for(int i=n-2;i>=0;--i)
		{
			sum += A[i];
			res += sum;
		}
		printf("%lld\n", res);
	}
	return 0;
}
