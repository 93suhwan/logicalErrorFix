#include <bits/stdc++.h>
using namespace std;
int n, n_, m, K, e[15], u[15], v[15], s;
long long pw[15], ans;
vector<long long> st;
void dfs2(int k1, int k2, long long k3) {
  if (k1 >= n_) {
    st.push_back(k3);
    return;
  }
  for (int i = (0); i <= (k2 + 1); ++i) {
    k3 += pw[u[k1]] * i;
    k3 += pw[v[k1]] * i;
    dfs2(k1 + 1, k2 + (i > k2), k3);
    k3 -= pw[u[k1]] * i;
    k3 -= pw[v[k1]] * i;
  }
}
void dfs1(int k1, int k2, int k3) {
  if (k1 >= n) {
    vector<vector<int> > dp((1 << n_), vector<int>(n_));
    for (int i = (0); i <= (n_ - 1); ++i)
      if (e[u[i]] >> v[i] & 1) dp[1 << i][i] = 1;
    for (int i = (0); i <= ((1 << n_) - 1); ++i) {
      for (int j = (0); j <= (n_ - 1); ++j)
        if (i >> j & 1)
          if (dp[i][j]) {
            for (int k = (0); k <= (n_ - 1); ++k)
              if ((~i >> k & 1) &&
                  (((e[u[j]] >> u[k] & 1) && (e[v[j]] >> v[k] & 1)) ||
                   ((e[v[j]] >> u[k] & 1) && (e[u[j]] >> v[k] & 1)))) {
                dp[i ^ (1 << k)][k] = 1;
              }
          }
    }
    bool flg = 0;
    for (int i = (0); i <= (n_ - 1); ++i)
      if (dp[(1 << n_) - 1][i]) flg = 1;
    if (flg) {
      dfs2(1, 0, 0);
    }
    return;
  }
  if (k2 >> k1 & 1) {
    dfs1(k1 + 1, k2, k3);
  } else {
    for (int i = (k1 + 1); i <= (n - 1); ++i)
      if (~k2 >> i & 1) {
        u[k3] = k1, v[k3] = i;
        dfs1(k1 + 1, k2 ^ (1 << k1) ^ (1 << i), k3 + 1);
        u[k3] = v[k3] = 0;
      }
  }
}
int main() {
  pw[0] = 1;
  for (int i = (1); i <= (14); ++i) pw[i] = pw[i - 1] * 6;
  scanf("%d%d%d", &n, &m, &K), n_ = n >> 1;
  for (int i = (1); i <= (m); ++i) {
    int k1, k2;
    scanf("%d%d", &k1, &k2);
    --k1, --k2;
    e[k1] |= 1 << k2;
    e[k2] |= 1 << k1;
  }
  dfs1(0, 0, 0);
  sort(st.begin(), st.end());
  st.erase(unique(st.begin(), st.end()), st.end());
  auto debug_out = [&](long long x) {
    ((void)0);
    for (int i = (0); i <= (n - 1); ++i) {
      ((void)0);
      x /= 6;
    }
    ((void)0);
  };
  vector<int> f(n_);
  for (auto x : st) {
    int mx = 0;
    long long now = x;
    while (now) {
      mx = max(mx, (int)(now % 6));
      now /= 6;
    }
    ++f[mx];
  }
  auto calc = [&](int t) {
    long long res = 1;
    for (int i = (1); i <= (t); ++i) res *= K - i + 1;
    return res;
  };
  for (int i = (0); i <= (n_ - 1); ++i) {
    ans += f[i] * calc(i + 1);
  }
  printf("%lld\n", ans);
  return 0;
}
