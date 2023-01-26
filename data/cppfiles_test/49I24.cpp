#include <bits/stdc++.h>

using namespace std;

void dbg_out() { cerr << endl; }
template<typename Head, typename... Tail>
void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }
#define dbg(...) cerr << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)

using ll = long long;

template<typename S, typename T> void smax(S &a, const T &b) { if (a < b) a = b; }
template<typename S, typename T> void smin(S &a, const T &b) { if (a > b) a = b; }

#define rng_init mt19937 rng(chrono::steady_clock::now().time_since_epoch().count())
#define rng_seed(x) mt19937 rng(x)
#define all(x) (x).begin(), (x).end()
#define sz(x) (int) (x).size()
// #define int long long

#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>

using namespace __gnu_pbds;

template<typename T>
using oset = tree<T, null_type, less<>, rb_tree_tag, tree_order_statistics_node_update>;

const int MXN = 1e6 + 5, INF = 1e9 + 5;
int N, Q;
vector<int> g[MXN];
int A[MXN], ans[MXN], cnt[MXN];
oset<pair<int, int>> vals;
vector<array<int, 3>> queries[MXN];

void dfs(int u, int p) {
    if (cnt[A[u]] != 0)
        vals.erase(vals.find(make_pair(cnt[A[u]], A[u])));

    cnt[A[u]]++;
    vals.insert(make_pair(cnt[A[u]], A[u]));

    for (const auto &[idx, l, k] : queries[u]) {
        int smaller = vals.order_of_key(make_pair(l, 0));
        // dbg(u + 1, idx + 1, l, k, smaller, sz(vals));

        if (smaller + k > sz(vals)) {
            ans[idx] = -1;
            continue;
        }

        ans[idx] = (*vals.find_by_order(smaller + k)).second + 1;
    }

    for (const auto &v : g[u]) {
        if (v == p) continue;
        dfs(v, u);
    }

    vals.erase(vals.find(make_pair(cnt[A[u]], A[u])));

    cnt[A[u]]--;
    if (cnt[A[u]] != 0)
        vals.insert(make_pair(cnt[A[u]], A[u]));

}

void solve() {
    cin >> N >> Q;

    for (int i = 0; i < N; i++)
        cin >> A[i];

    for (int i = 1; i < N; i++) {
        int p;
        cin >> p;
        p--;

        g[i].push_back(p);
        g[p].push_back(i);
    }

    for (int i = 0; i < Q; i++) {
        int v, l, k;
        cin >> v >> l >> k;
        v--;

        queries[v].emplace_back(array<int, 3>{i, l, k});
    }

    dfs(0, -1);

    vals.clear();
    for (int i = 0; i <= N; i++) {
        g[i].clear();
        queries[i].clear();
    }

    for (int i = 0; i < N; i++)
        cout << ans[i] << " ";

    cout << "\n";
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int TC = 1;
    cin >> TC;
    while (TC--) solve();
}