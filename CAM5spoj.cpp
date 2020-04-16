#include <bits/stdc++.h>
using namespace std;

#define MAXM 100005

bool vis[MAXM];
vector<int> adj[MAXM];

void dfs(int s){

	vis[s] = true;
	for(int x:adj[s]) if(!vis[x]) dfs(x	);

	return;
}

int main()
{
	int t;
	cin>>t;
	while(t--){
		int n, m;
		cin>>n>>m;
		int cnt =0;
		int x, y;
		for(int i=0; i<MAXM; i++) adj[i].clear();
		for(int i=0; i<m; i++){
			cin>>x>>y;
			adj[x].push_back(y);
			adj[y].push_back(x);
		}
		memset(vis, false, sizeof(vis));
		for(int i=0; i<n; i++) if(!vis[i]) cnt++, dfs(i);
		cout<<cnt<<endl;
	}
}