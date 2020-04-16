#include <bits/stdc++.h>
using namespace std;

int main()
{
	int t, n;
	cin>>t;
	while(t--){
		cin>>n;
		int a[n];

		vector<vector<int> > idx(27);
		int psum[27][n+1];
		memset(psum, 0, sizeof(psum));
		int res = 0;

		for(int i=0;  i<n; i++){
			cin>>a[i];
			idx[a[i]].push_back(i);
			res = max(res, (int) idx[a[i]].size());

			for(int j=0; j<27; j++){
				psum[j][i+1] = (j==a[i])?(1+psum[j][i]):psum[j][i];
			}
		}

		for(int i=0; i< (int) idx.size(); i++){

			int sz = idx[i].size();

			if(sz<2) continue;

			int ans = sz  + ((sz&1)?-1:0);
			int midelems = 0;

			for(int j=0; j< (int) idx.size(); j++){

				if(j==i || sz<=1) continue;

				if(sz&1){

					int left = idx[i][max(0, (sz/2))];
					int right = idx[i][(sz/2) + 1];
					if(left<right) midelems = max(midelems, psum[j][right + 1] - psum[j][max(0, left)]);

					left = idx[i][max(0, (sz/2) + 1)];
					right = idx[i][(sz/2) + 1];
					if(left<right) midelems = max(midelems, psum[j][right + 1] - psum[j][max(0, left)]);

				}

				else{
					int left = idx[i][max(0, (sz/2) - 1)];
					int right = idx[i][(sz/2)];
					if(left<right) midelems = max(midelems, psum[j][right + 1] - psum[j][max(0, left)]);
					// cout<<"DEBUG: "<<j<<" "<<left<<" "<<right<<" "<<midelems<<endl;
				}

			}
			ans += midelems;
			res = max(res, ans);
		}
		cout<<res<<endl;
	}
	
}
