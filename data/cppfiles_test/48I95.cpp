#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace __gnu_pbds; 
typedef long long int ll;
#define ordered_set tree<ll,null_type,less<ll>, rb_tree_tag,tree_order_statistics_node_update> 
#define ordered_set_pair tree<pair<ll,ll>,null_type,less<pair<ll,ll>>, rb_tree_tag,tree_order_statistics_node_update> 
#define ordered_set_mutiset tree<ll,null_type,less_equal<ll>, rb_tree_tag,tree_order_statistics_node_update>
typedef long double ld;
typedef unsigned long long int ull;
typedef pair<int,int> pi; 
#define PI 3.1415926535897932384
#define FOR(i,vv,n) for(ll i=vv;i<n;i++)
#define FORR(i,n,vv) for(ll i=n-1;i>=vv;i--)
#define ve vector 
#define maxind(v) (max_element(v.begin(),v.end())-v.begin())
#define minind(v) (min_element(v.begin(),v.end())-v.begin())
#define maxe(v) *max_element(v.begin(),v.end())
#define mine(v) *min_element(v.begin(),v.end())
#define pb push_back
#define pf push_front
#define ppb pop_back
#define ppf pop_front
#define eb emplace_back
#define FAST ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define mp make_pair
#define M 1000000007ll
#define M1 998244353ll
#define INF 1000000000000000000ll
#define PRECISE cout.precision(18);
#define BS(v,n) binary_search(v.begin(),v.end(),n)
#define all(v) v.begin(),v.end()
#define srt(v) sort(v.begin(),v.end())
#define rsrt(v) sort(v.begin(),v.end(),greater <ll>())
#define uni(v) v.resize(unique(v.begin(),v.end())-v.begin())
#define F first
#define S second
#define GET(i,p) get<p>(i)
 
void debug(ve <ll> v){
    for(auto i : v) cout << i << " ";
        cout << "\n";
}

ll maxn = 1 << 18;
ve <ll> segtree1(2 * maxn), segtree2(2 * maxn);
ve <ll> v(maxn);

void build(ll cur, ll tl, ll tr){

    if(tl == tr){
        segtree1[cur] = v[tl];
        segtree2[cur] = v[tl];
        return;
    }
    ll mid = (tl + tr) / 2;
    build(2 * cur, tl, mid);
    build(2 * cur + 1, mid + 1, tr);
    segtree1[cur] = min(segtree1[2 * cur], segtree1[2 * cur + 1]);
    segtree2[cur] = max(segtree2[2 * cur], segtree2[2 * cur + 1]);


}


ll query(ll cur, ll tl, ll tr, ll l, ll r){
    if(l > r) return INF;
    if(tl == l && tr == r){
        return segtree1[cur];
    }
    ll mid = (tl + tr) / 2;
    ll z1 = query(2 * cur, tl, mid, l, min(r, mid));
    ll z2 = query(2 * cur + 1, mid + 1, tr, max(l, mid + 1), r);
    return min(z1, z2);
}

ll query1(ll cur, ll tl, ll tr, ll l, ll r){

    if(l > r) return -INF;
    if(tl == l && tr == r){
        return segtree2[cur];
    }
    ll mid = (tl + tr) / 2;
    ll z1 = query1(2 * cur, tl, mid, l, min(r, mid));
    ll z2 = query1(2 * cur + 1, mid + 1, tr, max(l, mid + 1), r);
    // cout << z1 << " " << z2 << "\n";
    return max(z1, z2);
}


int main(){
 
    #ifndef ONLINE_JUDGE
    // for getting input from input.txt 
    freopen("input.txt", "r", stdin);
    // for writing output to output.txt
    freopen("output.txt", "w", stdout);
     #endif
    FAST
    PRECISE

    ll n, q;
    cin >> n >> q;
    ve <ll> a(n), b(n);
    FOR(i, 0, n) cin >> a[i];
    FOR(i, 0, n) cin >> b[i];
    FOR(i, 0, n){
        v[i] = b[i] - a[i];
        if(i - 1 >= 0) v[i] += v[i - 1];
    }
    build(1, 0, n - 1);
    // cout << query1(1, 0, n - 1, 1, 1);
    FOR(i, 0, q){
        ll x, y;
        cin >> x >> y; x--; y--;
        ll z1 = query(1, 0, n - 1, x, y), z2 = query1(1, 0, n - 1, x, y);
        
        // cout << z1 << " " << z2 << "\n";

        if(x != 0)
            z1 -= v[x - 1], z2 -= v[x - 1];

        if(z1 < -z2) cout << -1;
        else cout << z2 + (z1 < 0 ? abs(z1) : 0);
        cout << "\n";

    }
    

return 0;
 }