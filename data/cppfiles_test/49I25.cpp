//#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;

//randoms
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());

#define ll long long
#define trace(x) cout << #x << " = " << (x) << endl;
#define all(x) x.begin(), (x).end()
#define rall(x) x.rbegin(), (x).rend()
#define unique(x) x.erase(unique(all(x)), (x).end())
#define ld long double
#define sz(s) (int) size(s)


const int N = 1000001;
const ll infL = 1e18;
const int infI = 1e9 + 7;
const ll mod = 998244353;

int a[N], cnt[N], ans[N];
template<typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
ordered_set<pair<int, int>> st;
vector<int> g[N];
vector<tuple<int, int, int>> zap[N];

void add(int v) {
    st.erase({cnt[v], v});
    ++cnt[v];
    st.insert({cnt[v], v});
}

void del(int v) {
    st.erase({cnt[v], v});
    --cnt[v];
    st.insert({cnt[v], v});
}

void dfs(int v, int p) {
    add(a[v]);
    for (auto[l, k, i] : zap[v]) {
        int num = (int) st.order_of_key({l, -infI});
        if (num + k > sz(st)) ans[i] = -1;
        else ans[i] = st.find_by_order(num + k - 1)->second + 1;
    }
    for (int to : g[v]) {
        dfs(to, v);
    }
    del(a[v]);
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int test = 1;
    cin >> test;
    while (test--) {
        int n, q;
        cin >> n >> q;
        for (int i = 0; i < n; ++i) {
            g[i].clear();
            zap[i].clear();
            cin >> a[i];
        }
        for (int i = 1; i < n; ++i) {
            int p;
            cin >> p;
            --p;
            g[p].push_back(i);
        }
        for (int i = 0; i < q; ++i) {
            int v, l, k;
            cin >> v >> l >> k;
            --v;
            zap[v].emplace_back(l, k, i);
        }
        dfs(0, -1);
        for (int i = 0; i < q; ++i)
            cout << ans[i] << " ";
        cout << '\n';
    }
    return 0;
}