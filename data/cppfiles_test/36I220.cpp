#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("avx,avx2,fma")
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

#ifndef ONLINE_JUDGE
#define dbg(x) cerr<<#x<<" "; _print(x); cerr<<'\n';
#include "MyDebug.hpp"
#else
#define dbg(...)
#define TIME()
#endif

typedef long long int ll;
typedef long double ld;

typedef tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
typedef tree<ll, null_type, less_equal<ll>, rb_tree_tag, tree_order_statistics_node_update> ordered_multiset;
typedef tree<pair<ll,ll>, null_type, less<pair<ll,ll> >, rb_tree_tag, tree_order_statistics_node_update> ordered_pair_set;
#define forder(x) find_by_order(x)
#define okey(x) order_of_key(x)

typedef pair<ll,ll> pii;
typedef vector<ll> vi;
typedef vector<pii> vpii;
typedef vector<vector<ll> > vvi;
typedef vector<vector<pii> > vvpii;

#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()
#define minv(a) *min_element(all(a))
#define maxv(a) *max_element(all(a))
 
#define cases() int test_case; cin >> test_case; while(test_case--)
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define input(v) for(auto &invec:v) cin>>invec
#define output(v) for(auto prvec:v) cout<<prvec<<" "; cout<<'\n'
#define uniq(v) auto uniqit=unique(all(v)); v.resize(distance(v.begin(), uniqit));

const ll MOD = 1e9+7;
const ld PI = acos(-1);
const ld EPS = 1e-9;
const ll INF = 1e18;

ll power(ll a,ll b) {ll p=1;a%=MOD; assert(b>=0); for(;b;b>>=1){if(b&1)p=p*a%MOD;a=a*a%MOD;}return p;}
const int N=1e5;
vector<bool> is_prime(N+1, true);
void seive(){
    is_prime[0] = is_prime[1] = false;
    for (int i = 2; i <= N; i++) {
        if (is_prime[i] && (long long)i * i <= N) {
            for (int j = i * i; j <= N; j += i)
                is_prime[j] = false;
        }
    }
}

void solve(){
    int n;
    cin>>n;
    vi v(n);
    input(v);
    ll sum=0;
    for(auto i:v){
        sum+=i;
    }
    if(is_prime[sum]==false){
        cout<<n<<'\n';
        for(auto i:v){
            cout<<i<<" ";
        }cout<<'\n';
        return;
    }
    cout<<n-1<<'\n';
    int in=0;
    for(int i=0;i<n;i++){
        ll pp=sum-v[i];
        if(is_prime[pp]==false){
            in=i;
            break;
        }
    }
    for(int i=0;i<n;i++){
        if(i!=in){
            cout<<v[i]<<" ";
        }
    }cout<<'\n';
}
	
int main(){
    fastio
    seive();
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    freopen("error.txt", "w", stderr);
    #endif
    cases()
    solve();

    TIME();
	return 0; 
}