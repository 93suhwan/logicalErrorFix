#include <bits/stdc++.h>
#define int long long 
#define double float
#define pb push_back
#define F first 
#define S second 
using namespace std;
const int N=1e6+5;
const int mod=1e9+7;
long long po(int x,int y)
{
    int ans=1;
    while(y){
        if(y & 1) ans=(ans*x)%mod;
        y/=2;
        x=(x*x)%mod;
    }
    return ans;
}
int summ(int x,int y){
    return (x%mod)+(y%mod)%mod;
}
int mult(int x,int y){
    return ((x%mod)*(y%mod))%mod;
}
int  a[N];
int prefix[N],seive[N];
main(){ 
    for(int i=2;i<=1e6;i++){
        if(seive[i]==0)
            for(int j=i+i;j<=1e6;j+=i){
                seive[j]=1;
            }
    }
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        vector<int>v;
        v.clear();
        for(int i=0;i<n;i++){
            if(a[i]%2==0)v.pb(i+1);
        }
        int cnt=0;
        for(int i=0;i<n;i++){
            if(a[i]%2!=0)cnt++;
        }
        if(cnt%2!=0)cnt--;
        for(int i=0;i<n;i++){
            if(a[i]%2!=0&&cnt>0)v.pb(i+1),cnt--;
        }
        int sum=0;
        for(int i=0;i<v.size();i++){
                sum+=a[v[i]];
        }
        for(int i=n-1;i>=0;i--){
            if(a[i]%2!=0)if(seive[sum+a[i]]==1){v.pb(i+1);break;}
                else break;
        }
        cout<<v.size()<<endl;
        for(int i=0;i<v.size();i++){
            cout<<v[i]<<" ";
        }
        cout<<endl;
    }
}