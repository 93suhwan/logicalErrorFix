#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define fr(a,b) for(ll i = a; i < b; i++)
#define rep(i,a,b) for(ll i = a; i < b; i++)
#define mod 1000000007
#define inf (1LL<<60)
#define all(x) (x).begin(), (x).end()
#define prDouble(x) cout << fixed << setprecision(10) << x
#define triplet pair<ll,pair<ll,ll>>
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL)
using namespace std;

#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds; 
 
template <typename num_t>
using ordered_set = tree<num_t, null_type, less_equal<num_t>, rb_tree_tag, tree_order_statistics_node_update>;


ll power(ll a,ll n,ll p){
    ll ans=1;
    while(n>0){
        if(n&1){
            ans=((ans%p)*(a%p))%p;
            n--;
        }
        else{
            a=((a%p)*(a%p))%p;
            n=n/2;
        }
    }
    return ans;
}

ll modInv(ll a,ll p){
    return power(a,p-2,p);
}

ll mod_add(ll a,ll b,ll p){
    ll ans=((a%p)+(b%p))%p;
    return ans;
}
ll mod_sub(ll a,ll b,ll p){
    ll ans=(a%p)-(b%p);
    if(ans<0)ans+=p;
    ans=ans%p;
    return ans;
}
ll mod_mul(ll a,ll b,ll p){
    ll ans=((a%p)*(b%p))%p;
    return ans;
}

ll mod_div(ll a,ll b,ll p){
    ll ans=((a%p)*(modInv(b,p)%mod))%mod;
    return ans;
}

ll gcd(ll a,ll b){
    if(b==0){
        return a;
    }
    else{
        return gcd(b,a%b);
    }
}


ll fact[1001];
ll C(ll n,ll r){
    if(n<r)return 0;
    if(n==r)return 1;
    
    ll ans=(((fact[n]*modInv(fact[r],mod))%mod)*modInv(fact[n-r],mod))%mod;
    return ans;
}



//---------------------------------------Template above---------------------------------------


void solve(){
    ll n;
    cin >> n;
    string s;
    cin >> s;
    vector<ll> a(26, INT_MAX);

    for (int i = 0; i < 26;i++){
        char ch = 'a' + i;
        int c1, c2 = 0;
        int l = 0;
        int r = n - 1;
        ll ans = 0;
        while(l<r){
            c1 = c2 = 0;
            while(s[l]==ch){
                l++;
                c1++;
            }
            while(s[r]==ch){
                r--;
                c2++;
            }
            ans += max(c1, c2) - min(c1, c2);
            if(s[l]!=s[r]){
                a[i] = 1e6;
                l = r+1;
                continue;
            }
            else{
                l++;
                r--;
                a[i] = ans;
            }
        }
    }
    ll ans = INT_MAX;
    for (int i = 0; i < 26; i++){
        ans = min(ans, a[i]);
    }

    if(ans>=1e6){
        cout << "-1\n";
    }
    else{
        cout << ans << endl;
    }
}

int main() {
    fast_io;
    ll t;
    t = 1;
    cin >> t;
    while(t--)
    {
       solve();
    }
    return 0;
}