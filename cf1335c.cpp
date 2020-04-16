#include <bits/stdc++.h>
using namespace std;

int main()
{
	int t, n;
	cin>>t;
	while(t--){
		cin>>n;
		int a[n];
		unordered_map<int, int> m;
		for(int i=0; i<n; i++) cin>>a[i], m[a[i]] += 1;
		vector<pair<int, int> > pp;
		for(auto it:m){
			pp.push_back(make_pair(it.second, it.first));
		}
		sort(pp.rbegin(), pp.rend());
		int x = pp.size();
		int y = x - 1;
		int res = max((n>1?min(y,pp[0].first):0),(n>1?min(x,pp[0].first - 1):0));
		cout<<res<<endl;
	}		
}
