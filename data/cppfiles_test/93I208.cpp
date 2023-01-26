#include<bits/stdc++.h>
using namespace std;
#define ll long  
#define ff first
#define ss second 
#define all(v) v.begin(),v.end()
#define all1(v) v.rbegin(),v.rend()
const int MOD=998244353;
const int MOD1=1e9+7;


void solve(){
    ll n,k; cin>>n>>k;
    if(n==0){
        cout<<0<<endl; return;
    }
    if(k==1){
        cout<<n-1<<endl; return ;
    }

    ll k1;
    k1=__lg(k);

    if((k&(k-1))) k1++;

    // cout<<k1<<endl;
    
    if(n==((ll)1<<k1)){
        cout<<k1<<endl;
    }
    else if(n>((ll)1<<k1)){
        n-=((ll)1<<k1);
        if(n<=k) k1++;
        else k1+=ceil(n/(k*1.0));
        cout<<k1<<endl;
    }
    else{
        cout<<k1<<endl;
    }

    // cout<<endl;
}   

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin>>t;  
    while(t--) 
    solve();
}
    
    