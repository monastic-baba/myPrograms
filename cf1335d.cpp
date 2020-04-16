#include <bits/stdc++.h>
using namespace std;

int main()
{
	int t;
	char a[9][9];
	cin>>t;
	vector<pair<int, int> > v;

	v.push_back(make_pair(0, 0));
	v.push_back(make_pair(3, 1));
	v.push_back(make_pair(6, 2));

	v.push_back(make_pair(1, 3));
	v.push_back(make_pair(4, 4));
	v.push_back(make_pair(7, 5));

	v.push_back(make_pair(2, 6));
	v.push_back(make_pair(5, 7));
	v.push_back(make_pair(8, 8));

	while(t--){

		for(int i=0; i<9; i++)
			for(int j=0; j<9; j++)
				cin>>a[i][j];

		for(auto pp: v) a[pp.first][pp.second] = a[pp.first][pp.second]=='9'?'1':a[pp.first][pp.second]+1;

		for(int i=0; i<9; i++){
			for(int j=0; j<9; j++) cout<<a[i][j];
			cout<<endl;
		}
	}
	
	
}
