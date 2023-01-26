#include <bits/stdc++.h>
#include <iostream>

using namespace std;

using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using cd = complex<ld>;

const int N = 1'000'500;

vector<int> g[N];
vector<int> dsu(N);

int get(int x) {
    return dsu[x] == x ? x : dsu[x] = get(dsu[x]);
}

void unite(int a, int b) {
    dsu[get(a)] = get(b);
}

void solve() {
    vector<int> lp(N);
    iota(lp.begin(), lp.end(), 0);
    iota(dsu.begin(), dsu.end(), 0);
    for (int i = 2; i * i < N; i++) {
        if (lp[i] == i) {
            for (int j = i * i; j < N; j += i) {
                lp[j] = min(lp[j], i);
            }
        }
    }
    int n, q;
    cin >> n >> q;
    vector<int> v(n);
    vector<pair<int, int>> edges[N];
    for (int &e : v) {
        cin >> e;
        vector<int> a, b;
        int x = e, y = e + 1;
        while (x != 1) {
            int z = lp[x];
            while (x % z == 0) {
                x /= z;
            }
            a.push_back(z);
        }
        while (y != 1) {
            int z = lp[y];
            while (y % z == 0) {
                y /= z;
            }
            b.push_back(z);
        }
        for (int i : a) {
            for (int j : a) {
                if (i != j) {
                    unite(i, j);
                }
            }
        }
        for (int i : a) {
            for (int j : b) {
                edges[i].emplace_back(i, j);
                edges[j].emplace_back(j, i);
            }
        }
    }
    vector<unordered_set<int>> comps(N);
    for (int i = 0; i < N; i++) {
        for (auto [_, j] : edges[i]) {
            comps[get(i)].insert(get(j));
        }
    }
    for (int i = 0; i < q; i++) {
        int x, y;
        cin >> x >> y;
        x--; y--;
        x = v[x], y = v[y];
        if (get(lp[x]) == get(lp[y])) {
            cout << 0 << "\n";
        } else if (comps[get(lp[x])].count(get(lp[y]))){
            cout << 1 << "\n";
        } else {
            cout << 2 << "\n";
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
//    int t;
//    cin >> t;
//    for (int i = 0; i < t; i++) {
        solve();
//    }
}
