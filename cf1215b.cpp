#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;
    long long int a[n];
    long long int curr=0;
    long long int c1=0, c2=0,pos=0;

    for(int i=0;i<n;i++){

        cin>>a[i];

        if(curr&1) c2++;
        else c1++;

        if(a[i]<0) curr++;

        if(curr&1) pos+=c2;
        else pos+=c1;
    }
    long long int neg = n * 1ll * (n + 1) / 2;
    neg -= pos;
    cout<<neg<<" "<<pos<<endl;
}