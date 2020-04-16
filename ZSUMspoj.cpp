#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define MOD 10000007


ll sumUp(ll a, ll b){
	return (long long)((a%MOD) + (b%MOD))%MOD;
}

ll productUp(ll a, ll b){
	return (long long)((a%MOD) * (b%MOD))%MOD;
}

ll powerUp(ll a, ll b){

	if(b==0) return (long long) 1;

	ll small = powerUp(a, b/2);
	if(b&1) return productUp(productUp(small, small), a);
	else return productUp(small, small);
}


int main()
{
	ll n,k;
	vector<pair<ll, ll> > v;
	while(1){
		cin>>n>>k;
		if(n==0 and k==0) break;
		v.push_back(make_pair(n,k));
	}
	for(auto x:v){

		n = x.first;
		k = x.second;

		ll res = sumUp(powerUp(n, n), powerUp(n,k));
		res = sumUp(res, productUp(2, powerUp(n-1, k)));
		res = sumUp(res, productUp(2, powerUp(n-1, n-1)));
		cout<<res<<endl;
	}
}
