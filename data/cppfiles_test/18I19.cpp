#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#pragma GCC optimize("O3")
#pragma GCC target("avx,avx2,sse,sse2,sse3,sse4,popcnt,fma")
#pragma GCC optimize("unroll-loops")
using namespace __gnu_pbds;
#include <chrono>
using namespace std::chrono;
#define pb push_back
#define mk make_pair
// #define endl "\n"
#define mod 1000000007
// #define mod 998244353
// #define int long long int
#define PI 3.1415927
#define pb                push_back
#define ppb               pop_back
#define pf                push_front
#define ppf               pop_front
#define all(x)            (x).begin(),(x).end()
#define uniq(v)           (v).erase(unique(all(v)),(v).end())
#define sz(x)             (int)((x).size())
#define fr                first
#define sc                second
#define pii               pair<int,int>
#define rep(i,a,b)        for(int i=a;i<b;i++)
#define mem1(a)           memset(a,-1,sizeof(a))
#define mem0(a)           memset(a,0,sizeof(a))
#define MAXN 100005
#define N 200005
#define INF 1000000000000000000
#define LOG 19
using namespace std;
auto start = high_resolution_clock::now();
// typedef long long int ll;
typedef pair<int, int> ii;
typedef long double ld;
typedef tree<ii, null_type, less<ii>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
void solve() {
    int n, d;
    cin >> n >> d;
    vector<int> a(n);
    int ans = 0;
    rep(i, 0, n) {
        cin >> a[i];
    }
    vector<int> vis(n);
    rep(i, 0, n) {
        if (vis[i]) {
            continue;
        }
        int k = d;
        vector<int> vv;
        vv.pb(a[i]);
        vis[i] = 1;
        while (!vis[(i - k + 10000000 * n) % n]) {
            vis[(i - k + 10000000 * n) % n] = 1;
            vv.pb(a[(i - k + 10000000 * n) % n]);
            k += d;
        }
        int mx = 0;
        rep(j,0,sz(vv)){
            if(!vv[j]){
                continue;
            }
            int cnt = 1;
            int k = j + 1;
            while(k < sz(vv) && vv[k]){
                k++;
                cnt++;
            }
            j = k - 1;
            mx = max(mx, cnt);
        }
        if(mx == sz(vv)){
            cout<<-1;
            return;
        }
        ans = max(ans, mx);
        // for (auto x : vv) {
        //     cout << x << " ";
        // }
        // cout << "\n";
    }
    cout<<ans;
}
signed main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int test_cases;
    test_cases = 1;
    cin >> test_cases;
    for (int i = 0; i < test_cases; i++) {
        solve();
        // cout<<endl;
        cout << "\n";
    }
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    // cout << duration.count() << endl;
    return 0;
}