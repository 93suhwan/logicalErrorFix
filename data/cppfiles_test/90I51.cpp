# pragma GCC optimize ("O3")
# pragma GCC optimize ("Ofast")
# pragma GCC optimize ("unroll-loops")
#include <bits/stdc++.h>
#define MEM 100002
#define sanic ios_base::sync_with_stdio(0)
#define x first
#define y second
#define pf push_front
#define pb push_back
#define all(v) v.begin(), v.end()
#define sz size()
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pi;
typedef pair<pi, pi> pii;
const ll MOD = 1e9;
const ll INF = 2e9+7;
ll lcm(ll a, ll b){
    return a*b/__gcd(a,b);
}
ll t,n,m,k;
ll a[MEM];
void solve(){
    cin >> n >> m;
    if(n>m) {
        cout << n+m;
        return;
    }
    else if(n==m){
        cout << n;
        return;
    }
    cout << (n+m)/2;
}
signed main() {
    sanic; cin.tie(0); cout.tie(0);
    cin >> t;
    while(t--){
        solve();
        cout << '\n';
    }
}
