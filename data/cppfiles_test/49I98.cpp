#include <iostream>
#include <iomanip>
#include <ostream>
#include <fstream>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <bitset>
#include <vector>
#include <string>
#include <stack>
#include <queue>
#include <deque>
#include <array>
#include <algorithm>
#include <functional>
#include <cmath>
#include <time.h>
#include <random>
#include <chrono>
#include <cassert>
#include <cstring>
#include <limits>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
#define int long long
#define ld long double
#define pii pair<int, int>
#define sz(v) ((int)(v).size())
#define all(a) (a).begin(), (a).end()
#define rall(a) a.rbegin(), a.rend()
#define dbg(x) cerr << #x << " = " << (x) << endl;
#define F first
#define S second
mt19937 rnd(chrono::high_resolution_clock::now().time_since_epoch().count());
typedef tree<pii,null_type,less<pii>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;
const int MAXN = 2e6 + 100;
vector<vector<int>> g;
struct ask {
    int l, k, id;
};
vector<ask> me[MAXN];
int a[MAXN];
int ans[MAXN];
int cnt[MAXN];
ordered_set t;
int inf = 2e9;
void dfs(int u, int p){
    if(cnt[a[u]] > 0){
        t.erase({cnt[a[u]], a[u]});
        cnt[a[u]]++;
        t.insert({cnt[a[u]], a[u]});
    } else {
        cnt[a[u]]++;
        t.insert({cnt[a[u]], a[u]});
    }
    while(sz(me[u])){
        auto [l, k, id] = me[u].back();
        pii req = {l - 1, inf};
        int pos = t.order_of_key(req);
        if(pos + k > sz(t)){
            ans[id] = -1;
        } else {
            int npos = pos + k;
            auto gt = *t.find_by_order(npos);
            ans[id] = gt.S;
        }
        me[u].pop_back();
    }
    for(auto v: g[u]){
        if(v != p){
            dfs(v, u);
        }
    }
    t.erase({cnt[a[u]], a[u]});
    cnt[a[u]]--;
    if(cnt[a[u]] > 0){
        t.insert({cnt[a[u]], a[u]});
    }
}
void solve(){
    int n, q;
    cin >> n >> q;
    g.clear();
    g.resize(n);
    for(int i = 0;i < n;i++){
        cin >> a[i];
    }
    for(int i = 1;i < n;i++){
        int u;
        cin >> u;
        u--;
        g[u].push_back(i);
        g[i].push_back(u);
    }
    for(int i = 0;i < q;i++){
        int v, l, k;
        cin >> v >> l >> k;v--;
        me[v].push_back({l, k, i});
    }
    dfs(0, -1);
    for(int i = 0;i < q;i++){
        if(ans[i] != -1){
            ans[i]++;
        }
        cout << ans[i] << " ";
    }
    cout << '\n';
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}