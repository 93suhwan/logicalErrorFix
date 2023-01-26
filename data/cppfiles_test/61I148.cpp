#include <bits/stdc++.h>
using namespace std;
    
typedef long long ll;
typedef long double ld;
typedef complex<ld> cd;
    
typedef pair<int, int> pi;
typedef pair<ll,ll> pl;
typedef pair<ld,ld> pd;
    
typedef vector<int> vi;
typedef vector<ld> vd;
typedef vector<ll> vl;
typedef vector<pi> vpi;
typedef vector<pl> vpl;
typedef vector<cd> vcd;
    
#define SF(v) for(auto &x: v) cin>>x
#define FOR(i, a, b) for (int i=a; i<(b); i++)
#define F0R(i, a) for (int i=0; i<(a); i++)
#define FORd(i,a,b) for (int i = (b)-1; i >= a; i--)
#define F0Rd(i,a) for (int i = (a)-1; i >= 0; i--)
#define trav(a,x) for (auto& a : x)
#define uid(a, b) uniform_int_distribution<int>(a, b)(rng)
    
#define sz(x) (int)(x).size()
#define mp make_pair
#define pb push_back
#define f first
#define s second
#define lb lower_bound
#define ub upper_bound
#define all(x) x.begin(), x.end()
#define ins insert
    
template<class T> bool ckmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }
    
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
    
const int MOD = 1000000007;
const int MX = 100001;
    
long long binpow(long long a, long long b, long long MOD) {
    a %= MOD;
    long long res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a % MOD;
        a = a * a % MOD;
        b >>= 1;
    }
    return res;
}
    
ll lcm(ll a,ll b){
    return (a*b)/(__gcd(a,b));
}
    
void solve(){
    ll n; cin>>n;
    vector<char> v(n);
    SF(v);
    ll p = -1;
    FOR(i,0,n){
        if(v[i] != '?'){
            p = i;
            break;
        }
    }
    if(p == -1){
        FOR(i,0,n){
            if(i%2 == 1){
                cout<<'R';
            }else cout<<'B';
        }
        cout<<"\n";
        return;
    }else{
        FORd(i,0,p){
            if(v[i+1] == 'R'){
                v[i] = 'B';
            }else v[i] = 'R';
        }
        FORd(i,0,p){
            if(v[i+1] == 'R'){
                v[i] = 'B';
            }else v[i] = 'R';
        }
        FOR(i,p+1,n){
            if(v[i-1] == 'R') v[i] = 'B';
            else v[i] = 'R';
        }
        for(auto x: v) cout<<x;

        cout<<"\n";
    }
}
    
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << fixed << setprecision(20);
    ll T = 1;
    cin>>T;
    while(T--) solve();
    return 0;
}