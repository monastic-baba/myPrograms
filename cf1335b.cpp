#include <bits/stdc++.h>
using namespace std;

int main()
{
	int t, n, a, b;
	cin>>t;
	while(t--){
		cin>>n>>a>>b;
		string letters = "abcdefghijklmnopqrstuvwxyz";
		string s = "";
		int x = n/b;
		x += 1;
		while(x--) s += letters.substr(0, b);
		s = s.substr(0, n);
		cout<<s<<endl;
	}
}	