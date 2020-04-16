#include<bits/stdc++.h>
using namespace std;

int main()
{
    string s, res;
    cin>>s;

    if(s[0]=='h'){
        res = "http://";
        int i;
        for(i=5;i<s.length();i++) if(s[i]=='r' && s[i+1]=='u') break;
        res += s.substr(4, i-4);
        if(i+2<s.length()){
            res += ".ru/";
            res += s.substr(i+2,s.length()-i-2);
        }
        else{
            res += ".ru";
        }
    }

    else{
        res = "ftp://";
        int i;
        for(i=4;i<s.length();i++) if(s[i]=='r' && s[i+1]=='u') break;
        res += s.substr(3, i-3);
        if(i+2<s.length()){
            res += ".ru/";
            res += s.substr(i+2,s.length()-i-2);
        }
        else{
            res += ".ru";
        }
    }
    cout<<res<<endl;
}