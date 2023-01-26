
#pragma GCC optimize("O3")

#include<bits/stdc++.h>
#include <ext/pb_ds/detail/standard_policies.hpp>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

#define ll int
#define pb push_back
#define ld long double
#define f first
#define s second

using namespace std;
using namespace __gnu_pbds;

typedef tree<pair<ll,ll>, null_type,
        greater<pair<ll,ll>>, rb_tree_tag,
        tree_order_statistics_node_update> oset;

mt19937 gen(time(0));

const ll MOD = 1e9 + 7;

const ll OGR = 1e9 ;

gp_hash_table<ll,ll> mp[200007];
ll n;
set<ll> ans;

bool tr(ll x, ll y) {
bool f = mp[x][y];
set<ll> v = {x, y};
for(int j = 0; j < 3; j++) {
    for(int q = 0; q < 1000; q++) {
       ll d = gen() % n;
       if(v.count(d)) continue;
       bool f2 = 0;
       for(auto to: v) {
        if(mp[to][d] != f) {
            f2 = 1; break;
        }
       }
       if(!f2) {v.insert(d); continue; }
       if(q == 99) return 0;
    }
}
ans = v; return 1;
}
int32_t main() {

    srand(time(0));
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#else
    // freopen("trick.in", "r", stdin);
    //  freopen("trick.out", "w", stdout);
#endif // LOCAL


 ll m;
 cin >> n >> m;

 while(m--) {
    ll x, y;
    cin >> x >> y;
    x--; y--;
    mp[x][y] = 1;
    mp[y][x] = 1;
 }

 for(int j = 0; j < 10000; j++) {
    ll x = gen() % n, y = gen() % n;
    if(x == y) {j--; continue;}
    if(tr(x, y)) break;
 }
 if(!ans.size()) {
    cout << -1;
 } else {
  for(auto to: ans) {
    cout << to + 1 << ' ';
  }
 }


}





