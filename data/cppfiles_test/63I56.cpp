#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 1e9+7;
const ll MOD = 998244353;
typedef pair<ll,ll> ii;
#define iii pair<ii,ll>
#define f(i,a,b) for(ll i = a;i < b;i++)
#define pb push_back
#define vll vector<ll>
#define F first
#define S second
#define all(x) (x).begin(), (x).end()
///I hope I will get uprating and don't make mistakes
///I will never stop programming
///sqrt(-1) Love C++
///Please don't hack me
///@TheofanisOrfanou Theo830
///Think different approaches (bs,dp,greedy,graphs,shortest paths,mst)
///Stay Calm
///Look for special cases
///Beware of overflow and array bounds
///Think the problem backwards
///Training
int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll n;
    cin>>n;
    string s[n];
    f(i,0,n){
        cin>>s[i];
    }
    ll sum[n] = {0};
    ll off = 4e5 + 5;
    vll mp[n][off * 2 + 5];
    f(i,0,n){
        ll pos = 0;
        for(auto x:s[i]){
            if(x == '('){
                sum[i]++;
            }
            else{
                sum[i]--;
            }
            mp[i][sum[i] + off].pb(pos);
            pos++;
        }
    }
    ll dp[1LL<<n] = {0};
    ll ans = 0;
    f(i,0,(1LL<<n)){
        ll S = 0;
        f(j,0,n){
            if(i & (1LL<<j)){
                S += sum[j];
            }
        }
        if(S >= 0){
            f(j,0,n){
                if(i & (1LL<<j)){
                    continue;
                }
                else{
                    if(mp[j][-S-1 + off].empty()){
                        dp[i ^ (1LL<<j)] = max(dp[i ^ (1LL<<j)],dp[i] + mp[j][-S + off].size());
                        ans = max(ans,dp[i ^ (1LL<<j)]);
                    }
                    else{
                        ans = max(ans,dp[i] + (upper_bound(all(mp[j][-S + off]),mp[j][-S-1 + off][0]) - mp[j][-S + off].begin()));
                    }
                }
            }
        }
    }
    cout<<ans<<"\n";
}
