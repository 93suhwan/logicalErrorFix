#include <bits/stdc++.h>
using namespace std;

struct iofast_t {
    iofast_t() {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
    }
} iofast;

struct uns_t {} uns;
template <typename Element, typename Head, typename ...Args>
auto vec(Element init, Head arg, Args ...args) {
    if constexpr (sizeof...(Args) == 0) return std::vector(arg, init);
    else return std::vector(arg, vec(init, args...));
}
template <typename Element, typename Head, typename ...Args>
auto vec(uns_t, Head arg, Args ...args) {
    return vec(Element(), arg, args...);
}

template <typename T, typename Compare = less<T>>
T &chmin(T &l, T r, Compare &&f = less<T>()) { return l = min(l, r, f); }
template <typename T, typename Compare = less<T>>
T &chmax(T &l, T r, Compare &&f = less<T>()) { return l = max(l, r, f); }

int64_t dp[100 + 1][100 + 1];

int main() {
    constexpr int64_t mod = 1000000007;

    int t; cin >> t;

    while (t--) {
        int n, k; cin >> n >> k;

        auto g = vec<int>(uns, n, 0);
        for (int i = 1; i < n; ++i) {
            int u, v; cin >> u >> v; --u; --v;
            g[u].push_back(v);
            g[v].push_back(u);
        }

        int64_t ans = 0;
        if (k == 2) {
            ans += n - 1;
        }

        auto used = vec<bool>(uns, n);
        for (int r = 0; r < n; ++r) {
            fill(begin(used), end(used), false);
            used[r] = true;

            auto c = vec<int>(1, size(g[r]));

            queue<tuple<int, int, int>> que;
            for (int i = 0; i < size(g[r]); ++i) {
                que.push({ i, 1, g[r][i] });
                used[g[r][i]] = true;
            }

            for (int d = 1; !empty(que); ++d) {
                for (int i = 0; i <= size(g[r]); ++i) {
                    for (int j = 0; j <= k; ++j) {
                        dp[i][j] = 0;
                    }
                }

                dp[0][0] = 1;
                for (int i = 1; i <= size(g[r]); ++i) {
                    for (int j = 0; j <= k; ++j) {
                        dp[i][j] = dp[i - 1][j];
                        if (0 < j) {
                            dp[i][j] += dp[i - 1][j - 1] * c[i - 1];
                            dp[i][j] %= mod;
                        }
                    }
                }

                ans += dp[size(g[r])][k];
                ans %= mod;

                while (!empty(que)) {
                    auto [s, v, x] = que.front();
                    if (d != v) {
                        break;
                    }
                    que.pop(); --c[s];

                    for (auto u : g[x]) {
                        if (used[u]) {
                            continue;
                        }
                        used[u] = true;
                        que.push({ s, v + 1, u }); ++c[s];
                    }
                }
            }
        }

        cout << ans << endl;
    }
}

