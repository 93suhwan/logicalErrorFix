#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
template<class T> using oset =tree<T, null_type, less<T>, rb_tree_tag,tree_order_statistics_node_update> ;
typedef long long ll;
typedef vector<ll> vll;
typedef pair<ll,ll> pll;
typedef long double ld;
typedef map<ll,ll> mll;
typedef vector<int> vi;
typedef set<ll> sll;
typedef pair<int,int> ii;
typedef vector<ii> vii;
ll gcd(ll a, ll b) {return a == 0? b: gcd(b%a,a);}
ll lcm(ll a, ll b) {return a * (b / gcd(a,b));}
#define inf 1e17
#define pb(x) push_back(x)
#define rep(x,n) for (int i = x; i < n; i++)
#define all(x) (x).begin(), (x).end()
#define fo(x) find_by_order(x)
#define ok(x) order_of_key(x)
ll mod = 1e9 + 7;
int MAXN = 100000;

void solve(){
    int n; cin >> n;
    vll odds,even;
    rep(0,n){
        ll num; cin >> num;
        if (i % 2 == 0){
            odds.pb(num);
        }else even.pb(num);
    }
    ll ogcd = odds[0], egcd = even[0];
    rep(1,odds.size()) ogcd = gcd(odds[i],ogcd);
    rep(1,even.size()) egcd = gcd(even[i],egcd);
    bool ok = true;
    if (ogcd > egcd){
        rep(0,even.size()) if (even[i] % ogcd == 0) ok = false;
    }else if (egcd > ogcd){
        rep(0,odds.size()) if (odds[i] % egcd == 0) ok = false;
    }else ok = false;
    cout << (ok ? max(ogcd,egcd) : 0) << "\n";
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0);
    int t; cin >> t;
    while (t--) solve();
    return 0;
}