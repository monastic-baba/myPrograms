#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n,m;
	cin>>n>>m;
	int a[n][m];

	for(int i=0; i<n; i++)
		for(int j=0; j<m; j++)
			cin>>a[i][j];

	int res[m][2];
	for(int i=0; i<m; i++) res[i][0] = a[0][i];

	for(int i=1; i<n; i++){

		for(int j=0; j<m; j++){
			if(j==0) res[j][1] = a[i][j] + (m>1?min(res[j][0], res[j+1][0]):res[j][0]);
			else if(j==m-1) res[j][1] = a[i][j] + (m>1?min(res[j][0], res[j-1][0]):res[j][0]);
			else res[j][1] = a[i][j] + min({res[j][0], res[j-1][0], res[j+1][0]});
		}

		for(int k=0; k<m; k++) res[k][0] = res[k][1];


	}
	int ans = res[0][0];
	for(int k=0; k<m; k++) ans = min(res[k][0], ans);
	cout<<ans<<endl;
}	