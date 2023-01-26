#include<bits/stdc++.h>
#define int  long long
#define ull unsigned ll
#define f first
#define s second
#define pii pair<int,int>
#define pll pair<ll,ll>
#define pb push_back
#define epb emplace_back
#define inf 1e9+1
#define linf 1e18+1
using namespace std;
void solve(){
    int n;cin>>n;
    int a[n+1];
    for(int i=1;i<=n;i++)cin>>a[i];
    int ans=inf;
    for(int i=0;i<6;i++){
        for(int j=0;j<6;j++){
            int mn=-1;
            for(int k=1;k<=n;k++){
                int mn1=inf;
                for(int x=0;x<=i;x++){
                    for(int y=0;y<=j;y++){
                        if((a[k]-(x*2+y))%3==0)mn1=min(mn1,(a[k]-(x*2+y))/3);
                    }
                }
                mn=max(mn1,mn);
            }
            ans=min(ans,mn+i+j);
        }
    }
    cout<<ans<<"\n";
}

main(){
    ios_base::sync_with_stdio(false);cin.tie(0);
    int test=1;cin>>test;
    while(test--)solve();
}

