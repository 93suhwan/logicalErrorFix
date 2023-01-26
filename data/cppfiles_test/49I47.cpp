#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

#pragma GCC optimize("O3")

#define Size(a) (int)a.size()
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define ll long long
#define ld long double

// #define int long long

using namespace std;
using namespace __gnu_pbds;

const int N = 1e6 + 500;

vector<int> G[N];
int a[N];
vector<array<int, 3>> query[N];
int ans[N];
int cnt[N];
tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update> st;

void dfs(int v) {
    st.erase({ cnt[a[v]], a[v] });
    cnt[a[v]]++;
    st.insert({ cnt[a[v]], a[v] });

    for (auto [l, k, num] : query[v]) {
        int pos = st.order_of_key({ l, INT32_MIN });
        pos += k;
        if (pos >= st.size())
            ans[num] = -2;
        else
            ans[num] = st.find_by_order(pos)->second;
    }
    for (int to : G[v]) {
        dfs(to);
    }
    st.erase({ cnt[a[v]], a[v] });
    cnt[a[v]]--;
    if (cnt[a[v]])
        st.insert({ cnt[a[v]], a[v] });
}

void solve() {
    int n, q;
    cin >> n >> q;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        a[i]--;
        G[i].clear();
        query[i].clear();
    }
    for (int i = 1; i < n; i++) {
        int p;
        cin >> p;
        p--;
        G[p].push_back(i);
    }

    for (int t = 0; t < q; t++) {
        int v, l, k;
        cin >> v >> l >> k;
        v--; k--;
        query[v].push_back({ l, k, t });
    }

    dfs(0);

    for (int i = 0; i < n; i++)
        cout << ans[i] + 1 << " ";
    cout << "\n";
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    #ifdef DIMSS
        freopen("test.txt", "r", stdin);
    #endif

    int T = 1;
    cin >> T;
    while (T--) {
        solve();
        #ifdef DIMSS
            cerr << "-------\n";
        #endif
    }

    return 0;
}
