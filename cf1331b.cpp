#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n;
	cin>>n;
	string res;
	for(int i=2;i<450;i++){
		if(n%i==0){
			res = to_string(i) + to_string(n/i);
			break;
		}
	}
	cout<<res<<endl;
}