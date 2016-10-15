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
	int s, e;
	cin >> s >> e;
	while(s!=e)
	{
		if(A[s] == -1)
			break;
		int ns = A[s];
		A[s] = -1;
		s = ns;
	}
	if(s==e)
		cout << "Yes";
	else
		cout << "No";
	return 0;
}
