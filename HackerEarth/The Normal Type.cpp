#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define MAXN 100010
#define MOD 1000000007LL

int main()
{
	int n;
	cin >> n;
	vector<int> A(n);
	for(int i=0;i<n;++i)
		cin >> A[i];
	set<int> st;
	for(int i=0;i<n;++i)
		st.insert(A[i]);
	int k = st.size();
	map<int, int> mp;
	int L = 0, R = 0;
	ll res = 0;
	while(L<n)
	{
		while(mp.size()!=k)
		{
			if(R==n)
				break;
			mp[A[R]]++;
			++R;
		}
		res += (n-R);
		--mp[A[L]];
		if(mp[A[L]] == 0)
			mp.erase(A[L]);
		++L;
	}
	cout << res;
	return 0;
}
