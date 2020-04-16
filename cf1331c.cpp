#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n;
	cin>>n;
	int in[6];
	int i=5;
	
	while(n || i>=0){

		if(n&1) in[i]=1;
		else in[i]=0;

		i--;
		n/=2;
	}

	int temp = in[3];
	in[3] = in[2];
	in[2] = temp;

	temp = in[1];
	in[1] = in[5];
	in[5] = temp;

	int res=0, p=1;
	for(int i=5;i>=0;i--){
		res += in[i]*p;
		p*=2;
	}
	cout<<res<<endl;
}
