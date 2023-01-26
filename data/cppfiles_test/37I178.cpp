#include "bits/stdc++.h"
#include "ext/pb_ds/assoc_container.hpp"
#include "ext/pb_ds/tree_policy.hpp"
#define nline '\n'
#define debug(x) cout << #x << " " << x << "\n";
#define MOD 1000000007
#define INF 1e9

using namespace __gnu_pbds;
using namespace std;

typedef tree<int64_t, null_type, less_equal<int64_t>, rb_tree_tag, tree_order_statistics_node_update> ordered_multiset;
typedef tree<int64_t, null_type, less<int64_t>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

// @author: cladzen

const int N = 1e5 + 1;

int parent[N];
int sz[N];

int n, m;

void init() {
        for (int i = 1; i <= n; i++) {
                parent[i] = i;
                sz[i] = 1;
        }
}

int find(int node) {
        if (parent[node] == node) return node;

        return parent[node] = find(parent[node]);
}

void merge(int a, int b) {
        a = find(a);
        b = find(b);

        if (a == b) return;

        if (sz[a] > sz[b]) {
                parent[b] = a;
                sz[a] += sz[b];
        }
        else {
                parent[a] = b;
                sz[b] += sz[a];
        }

        return;
}

void test_case() {
        cin >> n >> m;

        init();

        for (int i = 0; i < m; i++) {
                int a, b, c;
                cin >> a >> b >> c;

                merge(a, c);

                cout << a << " " << c << nline;
        }

        set<int> st;
        for (int i = 1; i <= n; i++) {
                st.insert(find(i));
        }

        vector<int> v(st.begin(), st.end());

        for (int i = 0; i < v.size() - 1; i++) {
                cout << v[i] << " " << v[i + 1] << nline;
        }

        return;
}

int main(int argc, char **argv) {
#ifndef ONLINE_JUDGE
        freopen("Input.txt", "r", stdin);
        freopen("Output.txt", "w", stdout);
#endif
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);

        int64_t T = 1;
        cin >> T;

        while (T--) {
                test_case();
        }

        return 0;
}