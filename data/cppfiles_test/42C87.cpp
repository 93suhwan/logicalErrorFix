#include <bits/stdc++.h>
using namespace std;
inline long long read() {
  long long x = 0, f = 1;
  char c = getchar();
  while ((c < '0' || c > '9') && (c != '-')) c = getchar();
  if (c == '-') f = -1, c = getchar();
  while (c >= '0' && c <= '9') x = x * 10 + c - '0', c = getchar();
  return x * f;
}
const int N = 4e5 + 10, mod = 1e9 + 7;
int n, m, dp[N];
pair<int, int> a[N], b[N];
bool vis[N];
map<pair<int, int>, int> pos;
int c[N];
inline int Mod(int x) { return x >= mod ? x - mod : x; }
inline void Add(int x, int y) {
  for (; x <= 2 * n; x += x & -x) c[x] = Mod(c[x] + y);
}
inline int Query(int x) {
  int ret = 0;
  for (; x; x -= x & -x) ret = Mod(ret + c[x]);
  return ret;
}
int main() {
  n = read();
  for (int i = (1); i <= (n); i++)
    a[i].first = read(), a[i].second = read(), b[i] = a[i];
  sort(a + 1, a + 1 + n);
  for (int i = (n); i >= (1); i--) {
    pos[a[i]] = i;
    dp[i] = 1 + Query(a[i].second);
    Add(a[i].second, dp[i]);
  }
  m = read();
  for (int i = (1); i <= (m); i++) {
    int x = read();
    vis[pos[b[x]]] = 1;
  }
  int mx = 0, ans = 0;
  for (int i = (n); i >= (1); i--) {
    if (vis[i])
      mx = max(mx, a[i].second), ans = Mod(ans + dp[i]);
    else if (a[i].second < mx)
      ans = Mod(ans + dp[i]);
  }
  printf("%d\n", ans);
}
