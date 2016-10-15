#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define MAXN 100010
#define MOD 1000000007LL

int main()
{
	int n;
	cin >> n;
	vector<int> A(n+1);
	for(int i=1;i<=n;++i)
		cin >> A[i];
	set<int> st;
	vector<int> DP(n+1);
	for(int i=1;i<=n;++i)
	{
		st.insert(A[i]);
		DP[i] = st.size();
	}
	st.clear();
	ll res = 0;
	for(int i=n;i>=1;--i)
	{
		if(st.count(A[i]))
			continue;
		st.insert(A[i]);
		res += DP[i-1];
	}
	cout << res << endl;
	return 0;
}
