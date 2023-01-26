#include<bits/stdc++.h>
#include<iostream>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

#define w(x)                int x;cin>>x;while(x-->0)
#define ll                  long long int
#define mod                 1000000007
#define arin(a) for         (auto &it : a) cin >> it;
#define endl               "\n"
typedef tree<ll,null_type,less<ll>,rb_tree_tag,tree_order_statistics_node_update> PBDS;

void solve(){
    ll n;cin>>n;
    ll ar[n],b[n];
    for(ll i=0;i<n;i++){
        cin>>ar[i];
        b[i]=ar[i];
    }
    sort(b,b+n);
    ll ans=0;
    while(true){
        bool flag=true;
        for(ll i=0;i<n;i++){
            if(ar[i]!=b[i]){
                flag=false;
                break;
            }
        }
        if(flag)break;

        for(ll i=0;i<n-1;i++){
            if(ar[i]>ar[i+1]){
                swap(ar[i],ar[i+1]);
                i+=1;
            }
        }
        ans+=1;
    }
    cout<<ans<<endl;
}

int main(){
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
    w(t){
        solve();
    }
    //solve();
}