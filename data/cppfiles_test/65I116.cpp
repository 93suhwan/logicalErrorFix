#include<bits/stdc++.h>
#define pi 3.141592653589793238
#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
#define MOD 1000000007
#define INF 999999999999999999 
#define pb push_back
#define ff first
#define ss second
 
#define mt make_tuple
#define ll long long
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>

using namespace __gnu_pbds;
 
 
typedef tree<ll, null_type, less_equal<ll>, rb_tree_tag, tree_order_statistics_node_update> indexed_set;
 
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
 
struct DSU {
    vector<int> parent, sz;
    DSU (int n) {
        parent.resize(n + 1);
        sz.resize(n + 1, 1);
        iota(parent.begin(), parent.end(), 0);
    }
    int find_parent(int a) {
        if (a == parent[a]) return a;
        else return parent[a] = find_parent(parent[a]);
    }
    void merge(int a, int b) {
        a = find_parent(a);
        b = find_parent(b);
        if (a == b) return;
        if (sz[a] < sz[b]) swap(a, b);
        sz[a] += sz[b];
        parent[b] = a;
    }
};

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    fast;
    ll T = 1, i, j;
    
    // cin >> T;
    while (T--) {
        int n, m1, m2;
        cin >> n >> m1 >> m2;
        DSU a(n), b(n);
        while (m1--) {
            int x, y;
            cin >> x >> y;
            a.merge(x, y);
        }
        while (m2--) {
            int x, y;
            cin >> x >> y;
            b.merge(x, y);
        }
        vector<pair<int, int>> answer;
        for (int i = 1; i <= n; ++i) {
            int j = i % n + 1;
            if ((a.find_parent(i) != a.find_parent(j)) && (b.find_parent(i) != b.find_parent(j))) {
                answer.push_back({i, j});
                a.merge(i, j);
                b.merge(i, j);
            }
        }
        cout << answer.size() << "\n";
        for (auto u: answer) cout << u.ff << " " << u.ss << "\n";
    }
    return 0;
}