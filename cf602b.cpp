/*http://codeforces.com/problemset/problem/602/B*/
#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n,res=2;
	cin>>n;
	int a[n];
	for(int i=0;i<n;i++) cin>>a[i];
	int mn=min(a[0],a[1]), mx=max(a[0],a[1]);
	int minidx=(a[0]>a[1]?1:0), maxidx=(a[0]>a[1]?0:1);
	int l=0,r=1;
	for(int i=2;i<n;i++){
		
		// if(i==4){
		// 	cout<<minidx<<" "<<maxidx<<" "<<l<<" "<<r<<endl;
		// }


		r=i;
		if(a[i]<=mx && a[i]>=mn){
			res = max(res, r-l+1);
			if(a[i]==mx) maxidx=i;
			else minidx=i;
		}

		else{
			if(a[i]>mx){
				l=minidx+1;
				minidx=maxidx;
				mn=mx;
				mx+=1;
				maxidx=i;	
			}
			else{
				l=maxidx+1;
				maxidx=minidx;
				mx=mn;
				mn-=1;
				minidx=i;
			}
		}
	}
	cout<<res<<endl;
}