#include <bits/stdc++.h>
using namespace std;

bool visited[1003][1003];
int m, n;
vector<string> v;
int res = 0;
int R, C;

int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};

void reinitialise(){

	memset(visited, false, sizeof(visited));
	res = 0;

	return;
}

void dfs(int x, int y, int cnt){


	if(x<0 || x>=n || y<0 || y>=m) return;
	if(visited[x][y]) return;
	if(v[x][y]=='#') return;

	visited[x][y] = true;

	if(cnt>=res){
		R = x;
		C = y;
	}
	res = max(res, cnt);

	for(int i=0; i<4; i++)
		for(int j=0; j<4; j++)
			dfs(x + dx[i], y + dy[j], cnt + 1);

	return;
}

int main()
{
	int t;
	cin>>t;
	while(t--){
		
		reinitialise();
		v.clear();

		cin>>m>>n;
		string s;
		int i, j;
		for(i=0; i<n; i++) cin>>s, v.push_back(s);

		for(i=0; i<n; i++){
			for(j=0; j<m; j++){
				if(v[i][j]=='.'){
					break;
				}
			}
			if(v[i][j]=='.') break;
		} 
		dfs(i, j, 0);
		reinitialise();
		cout<<R<<" "<<C<<endl;
		dfs(R, C, 0);
		printf("Maximum rope length is %d.\n", res);	
	}
}