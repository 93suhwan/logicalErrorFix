#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
using namespace std;
template <typename T1, typename T2>
inline void remin(T1& a, T2 b) {
  a = min(a, (T1)b);
}
template <typename T1, typename T2>
inline void remax(T1& a, T2 b) {
  a = max(a, (T1)b);
}
const int LOG = 19, maxN = 1 << LOG, mod = 998244353;
template <typename T1, typename T2>
inline void addMod(T1& a, T2 b) {
  a = (a + b) % mod;
}
template <typename T1, typename T2>
inline void multMod(T1& a, T2 b) {
  a = a * b % mod;
}
int vis[maxN], nxt[maxN], prv[maxN], T[maxN];
long long dp[maxN];
void fail() {
  printf("0\n");
  exit(0);
}
map<int, int> M;
vector<pair<int, int> > kys;
void solve() {
  int n, m, k;
  scanf("%d%d%d", &n, &m, &k);
  for (int v = (1); v < (n + 1); v++) {
    int c;
    scanf("%d", &c);
    for (int i = (0); i < (c); i++) {
      scanf("%d", T + i);
      if (vis[T[i]] == v) fail();
      vis[T[i]] = v;
    }
    for (int i = (0); i < (c - 1); i++) {
      int x = T[i];
      if (nxt[x] != 0 and nxt[x] != T[i + 1]) fail();
      nxt[x] = T[i + 1];
    }
    for (int i = (1); i < (c); i++) {
      int x = T[i];
      if (prv[x] != 0 and prv[x] != T[i - 1]) fail();
      prv[x] = T[i - 1];
    }
  }
  for (int v = (1); v < (k + 1); v++)
    if (prv[v] == 0) {
      int d = 1;
      for (int x = v; nxt[x] != 0; x = nxt[x]) d++;
      M[d]++;
    }
  for (auto it : M)
    if (it.second != 0 and it.first <= m) kys.push_back(it);
  dp[0] = 1;
  for (int i = (1); i < (m + 1); i++) {
    for (int j = (0); j < (((int)(kys).size())); j++) {
      int ki, vl;
      tie(ki, vl) = kys[j];
      if (ki <= i) dp[i] += dp[i - ki] * vl;
    }
    dp[i] %= mod;
  }
  printf("%lld\n", dp[m]);
}
int main() {
  int t = 1;
  for (int tid = (1); tid < (t + 1); tid++) {
    solve();
  }
  return 0;
}
