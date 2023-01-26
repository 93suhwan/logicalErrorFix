#include <bits/stdc++.h>
#define int long long 
#define double float
#define pb push_back
#define F first 
#define S second 
using namespace std;
const int N=1e6+5;
const int mod=1e9+7;
//int a[N],c[N],sp[N][40],cnt[N],b[N],logg[N];
vector<int>v;
map<int,int>mp;

main(){
    int t;
    cin>>t;
    while (t--){
        string s,z;
        cin>>s>>z;
        for(int i=0;i<s.size();i++){
            mp[s[i]]=i;
        }
        int cnt=0;
        for(int i=1;i<z.size();i++){
            if(z[i]!=z[i-1])cnt+=mp[z[i]]-mp[z[i-1]];
        }
        cout<<cnt<<endl;

    }
    
}
 