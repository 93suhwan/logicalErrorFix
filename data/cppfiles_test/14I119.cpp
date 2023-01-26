#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;
using namespace std;

template<typename T>
using ordered_set = tree<T,null_type,less<T>,rb_tree_tag,tree_order_statistics_node_update>;

const int infI=1e9+5;
const long long infL=1e16;
const int MOD=1e9+7;
const int MAX=2e5+5;

#define mp make_pair
#define pb push_back
#define ii pair<int,int>
#define iii pair<int,ii>
#define ll long long
#define pll pair<ll,ll>
#define vi vector<int>
#define vvi vector<vector<int> >
#define vl vector<ll>
#define forn(i,a,b) for(ll i=a;i<b;i++)
#define fastio ios_base::sync_with_stdio(0);cin.tie(0)
#define endl '\n'
#define popb pop_back()
#define se second
#define fi first
#define test(t) int t;cin>>t;while(t--)
#define debug(x) cerr<<"=>"<<#x<<" = "<<x<<endl

ll power(ll a,ll b){
    if(b==0){
        return 1;
    }
    if(b==1){
        return a;
    }
    ll temp=power(a,b/2);
    temp=(temp*temp)%MOD;
    if(b%2){
        temp=(temp*a)%MOD;
    }
    return temp;
}

//only use if mod is prime
ll mod_inv(ll a,ll mod){
    a%=mod;
    return power(a,mod-2);
}

void extended_gcd(ll a,ll b,ll &x,ll &y){
    if(b==0){
        x=1;
        y=0;
        return;
    }
    ll x1,y1;
    extended_gcd(b,a%b,x1,y1);
    x=y1;
    y=x1-((a/b)*y1);
    return;
}

ll ceiling(ll a,ll b){
    return (a+b-1)/b;
}

//TLE can also occur if vectors are not passed by reference, debug statements can also cause TLE.
//priority_queue implements max heap by default

int a[2005];
int dp[2005][2005];

int main(){
    fastio;
    // think about edge cases like n=1(especially graph questions).
    // If you need to check for overflows, add the -1 condition in power function.
    test(zz){
        int n,k;
        cin>>n>>k;
        forn(i,1,n+1){
            cin>>a[i];
        }
        forn(i,0,n+1){
            forn(j,0,n+1){
                dp[i][j] = 0;
            }
        }
        forn(i,0,n){
            forn(j,0,n+1){
                dp[i+1][j] = max(dp[i+1][j], dp[i][j]);
                if(a[i+1] == j+1){
                    dp[i+1][j+1] = max(dp[i+1][j+1], 1 + dp[i][j]);
                }
                else{
                    dp[i+1][j+1] = max(dp[i+1][j+1], dp[i][j]);
                }
            }
        }
        int ans = -1;
        forn(j,0,n+1){
            if(dp[n][j]>=k){
                ans = n-j;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}