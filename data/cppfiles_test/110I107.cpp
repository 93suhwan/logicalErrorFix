#include <bits/stdc++.h>
using namespace std;
template <typename T>
inline void read(T &res) {
  T x = 0, f = 1;
  char ch = getchar();
  while (ch != EOF && (ch < '0' || ch > '9')) {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (ch != EOF && ch >= '0' && ch <= '9') {
    x = (x << 1) + (x << 3) + (ch ^ 48);
    ch = getchar();
  }
  res = x * f;
}
template <typename T, typename... Args>
inline void read(T &t, Args &...a) {
  read(t), read(a...);
}
const int inf_int = 0x3f3f3f3f;
const long long inf_ll = 0x3f3f3f3f3f3f3f, inf_2 = 4e13 + 11;
const long long maxn = 2e5 + 11, maxe = 1e7 + 3, mod = 1e9 + 7;
const long double eps = 1e-10;
int n, mx[maxn], ans, vis[maxn], du[maxn];
vector<vector<pair<int, int>>> e;
inline int OK() {
  for (int i = 1; i <= n; i++)
    if (!vis[i]) return false;
  return true;
}
inline void solve() {
  read(n);
  e.assign(n + 1, vector<pair<int, int>>());
  queue<int> q;
  for (int i = 1, k, x; i <= n; i++) {
    read(k), mx[i] = 0, du[i] = k;
    if (!k) q.push(i);
    while (k--) read(x), e[x].push_back(make_pair(i, (i < x)));
  }
  while (q.size()) {
    int x = q.front();
    q.pop();
    vis[x] = 1;
    for (auto [v, w] : e[x]) {
      du[v]--, mx[v] = max(mx[v], mx[x] + w);
      if (!du[v]) q.push(v);
    }
  }
  if (!OK()) {
    puts("-1");
  } else {
    printf("%d\n", *max_element(mx + 1, mx + 1 + n) + 1);
  }
}
int main() {
  int TEST = 1;
  read(TEST);
  while (TEST--) solve();
}
