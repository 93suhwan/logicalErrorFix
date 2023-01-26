#include<bits/stdc++.h>
#define int long long
#define pb push_back
#define F first
#define S second
using namespace std;
const int N=1e6,M=1e4;
long long minn=1e18,mux=-1e18;
const int mod=1e9+7;
int po(int x,int y)
{
    int  ans=1;
    while(y){
        if(y & 1) ans=(ans*x)%mod;
        y/=2;
        x=(x*x)%mod;
    }
    return ans;
}
int inv(int x)
{
    return po(x,mod-2);
}
int sum[N];
 main()
{
    int t;
    cin>>t;
    while(t--){
        int n,q;
        cin>>n>>q;
        string s;
        cin>>s;
        if(s[s.size()-1]=='+')
        sum[s.size()-1]=1;
        else sum[s.size()-1]=-1;
        for(int i=s.size()-2;i>=0;i--){
                if(s[i]=='+')sum[i]=-sum[i+1]+1;
                else sum[i]=-sum[i+1]-1;
        }
        while(q--){
            int l,r;
            cin>>l>>r;
            l--,r--;
            if(sum[l]-sum[r+1]==0)
                cout<<0<<endl;
            else if((r-l+1)%2!=0)
                cout<<1<<endl;
            else cout<<2<<endl;
        }
    }
    return 0;
}
