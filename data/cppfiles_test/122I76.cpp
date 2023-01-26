// Problem: X(or)-mas Tree
// Contest: Codeforces
// URL: https://m2.codeforces.com/contest/1615/problem/D
// Memory Limit: 256 MB
// Time Limit: 2000 ms
//
// Powered by CP Editor (https://cpeditor.org)

#define print_debug true

#include <bits/stdc++.h>

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

const long long MOD = 1000000007;

using namespace __gnu_pbds;
using namespace std;

typedef tree<int, null_type, less<int>, rb_tree_tag,
             tree_order_statistics_node_update>
    indexed_set;

typedef long long ll;

void fileIO(string name) {
    freopen((name + ".in").c_str(), "r", stdin);
    freopen((name + ".out").c_str(), "w", stdout);
}

template <class T>
void debug(const T& n) {
    if (print_debug) cerr << n << "\n\n";
}

template <class T>
void debug(const vector<T>& k) {
    if (print_debug) {
        for (int i = 0; i < (int)k.size(); ++i) {
            cerr << k[i] << " ";
        }
        cerr << "\n\n";
    }
}

template <class T>
void debug(const vector<vector<T>>& k) {
    if (print_debug) {
        for (int i = 0; i < (int)k.size(); ++i) {
            for (int j = 0; j < (int)k[i].size(); ++j) {
                cerr << k[i][j] << " ";
            }
            cerr << "\n";
        }
        cerr << "\n";
    }
}

template <class T>
int bin_upper(const vector<T>& k, const T& value) {
    return distance(k.begin(), upper_bound(k.begin(), k.end(), value));
}

template <class T>
int bin_lower(const vector<T>& k, const T& value) {
    return distance(k.begin(), lower_bound(k.begin(), k.end(), value));
}

bool odd(int n) {
    bool ret = 0;
    for (int i = 0; i <= 30; ++i) {
        if (n & (1 << i)) {
            ret = !ret;
        }
    }

    return ret;
}

vector<vector<pair<int, int>>> adj;

class DSU {
   public:
    vector<int> size;
    vector<int> up;

    DSU(int n) {
        size.resize(n);
        fill(size.begin(), size.end(), 1);
        up.resize(n);

        for (int i = 0; i < (int)up.size(); ++i) {
            up[i] = i;
        }
    }

    int find_root(int node) {
        if (up[node] == node) return node;
        return up[node] = find_root(up[node]);
    }

    bool same(int a, int b) { return find_root(a) == find_root(b); }

    void join(int a, int b) {
        a = find_root(a);
        b = find_root(b);

        if (a == b) return;

        if (size[a] > size[b]) {
            size[a] += size[b];
            up[b] = a;
        } else {
            size[b] += size[a];
            up[a] = b;
        }
    }

    int get_size(int node) { return size[find_root(node)]; }
};

void solve() {
    adj.clear();

    int n, m;
    cin >> n >> m;
    adj.resize(n);

    DSU d(n);
    vector<int> oppo(n, -1);

    for (int i = 0; i < n - 1; ++i) {
        int a, b, w;
        cin >> a >> b >> w;
        a--;
        b--;
        adj[a].push_back({b, w});
        adj[b].push_back({a, w});
        if (w != -1) {
            if (odd(w)) {
                if (oppo[a] != -1) {
                    d.join(oppo[a], b);
                } else if (oppo[b] != -1) {
                    d.join(oppo[b], a);
                } else {
                    oppo[a] = b;
                    oppo[b] = a;
                }
            } else {
                d.join(a, b);
            }
        }
        // debug(oppo);
    }

    vector<vector<pair<int, bool>>> elves(n);

    for (int i = 0; i < m; ++i) {
        int a, b, w;
        cin >> a >> b >> w;
        a--;
        b--;

        elves[a].push_back({b, w});
        elves[b].push_back({a, w});

        if (w) {
            if (oppo[a] != -1) {
                d.join(oppo[a], b);
                oppo[b] = a;
            } else if (oppo[b] != -1) {
                d.join(oppo[b], a);
                oppo[a] = b;
            } else {
                oppo[a] = b;
                oppo[b] = a;
            }
        } else {
            d.join(a, b);
        }
        // debug(oppo);
    }

    for (int a = 0; a < n; ++a) {
        for (pair<int, int>& p : adj[a]) {
            int& b = p.first;
            int& w = p.second;
            if (w == -1) continue;
            if (odd(w)) {
                if (d.same(a, b)) {
                    cout << "NO\n";
                    return;
                }
            } else {
                assert(d.same(a, b));
            }
        }
    }

    for (int a = 0; a < n; ++a) {
        for (pair<int, bool>& p : elves[a]) {
            int& b = p.first;
            bool& w = p.second;
            if (w == 1) {
                if (d.same(a, b)) {
                    cout << "NO\n";
                    return;
                }
            } else {
                assert(d.same(a, b));
            }
        }
    }

    cout << "YES\n";

    for (int a = 0; a < n; ++a) {
        for (pair<int, int>& p : adj[a]) {
            int& b = p.first;
            int& w = p.second;
            if (b > a) continue;
            if (w == -1) {
                if (d.same(a, b)) {
                    w = 0;
                } else {
                    if ((oppo[a] != -1 && d.same(oppo[a], b)) ||
                        (oppo[b] != -1 && d.same(oppo[b], a))) {
                        w = 1;
                    } else {
                        d.join(a, b);
                        w = 0;
                    }
                }
            }

            cout << (a + 1) << " " << (b + 1) << " " << w << "\n";
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}