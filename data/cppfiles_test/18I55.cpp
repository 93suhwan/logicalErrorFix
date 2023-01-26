#include <bits/stdc++.h>
using namespace std;

template <class T>
bool chmin(T& _old, T _new) { return _old > _new && (_old = _new, true); }
template <class T>
bool chmax(T& _old, T _new) { return _old < _new && (_old = _new, true); }

void solve() {
    int n, k;
    cin >> n >> k;
    const int m = 2 * n;
    vector<int> a(m);
    for (int i = 1, u, v; i <= k; ++i) {
        cin >> u >> v, --u, --v;
        if (u > v) {
            swap(u, v);
        }
        a[u] = -i, a[v] = i;
    }
    vector<int> state((n - k) << 1);
    iota(state.begin(), state.begin() + n - k, k + 1);
    iota(state.rbegin(), state.rbegin() + n - k, -n);
    vector<int> b(m);
    bitset<128> check;
    int ans = 0;
    for (auto base = state.begin(); base != state.end(); ++base) {
        auto it = base;
        b = a;
        for (auto& x : b) {
            if (!x) {
                x = *(it++);
                if (it == state.end()) {
                    it = state.begin();
                }
            }
        }
        int s = 0;
        for (int i = 0; i < m; ++i) {
            if (b[i] > 0) {
                continue;
            }
            check.reset();
            for (int j = i == m - 1 ? 0 : i + 1; abs(b[i]) != abs(b[j]); j = j == m - 1 ? 0 : j + 1) {
                check._Unchecked_flip(abs(b[j]));
            }
            s += check.count();
        }
        chmax(ans, s);
    }
    cout << ans / 2 << '\n';
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
#ifdef palilo
    freopen("in", "r", stdin);
    freopen("out", "w", stdout);
#endif
    int T;
    cin >> T;
    while (T--) {
        solve();
    }
}