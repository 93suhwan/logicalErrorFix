#include <bits/stdc++.h>
using namespace std;
template <typename T>
void chkmax(T &first, T second) {
  first < second ? first = second : T();
}
template <typename T>
void chkmin(T &first, T second) {
  second < first ? first = second : T();
}
template <typename T>
void readint(T &first) {
  first = 0;
  int f = 1;
  char c;
  for (c = getchar(); !isdigit(c); c = getchar())
    if (c == '-') f = -1;
  for (; isdigit(c); c = getchar()) first = first * 10 + (c - '0');
  first *= f;
}
const int MAXN = 300005;
int n, m, p[MAXN], q[MAXN], cnt[MAXN], fa[MAXN];
vector<int> res;
int getfa(int u) { return u == fa[u] ? u : fa[u] = getfa(fa[u]); }
void check(int k) {
  for (int i = 1; i <= k; ++i) q[i] = n - k + i;
  for (int i = k + 1; i <= n; ++i) q[i] = i - k;
  for (int i = 1; i <= n; ++i) fa[i] = i;
  for (int i = 1; i <= n; ++i) fa[getfa(p[i])] = getfa(q[i]);
  int cnt = n;
  for (int i = 1; i <= n; ++i)
    if (i == getfa(i)) --cnt;
  if (cnt <= m) res.push_back(k);
}
void solve() {
  readint(n), readint(m);
  memset(cnt, 0, sizeof(int) * n);
  for (int i = 1; i <= n; ++i) readint(p[i]), ++cnt[(i - p[i] + n) % n];
  res.clear();
  for (int i = 0; i < n; ++i)
    if (cnt[i] >= n - 2 * m) check(i);
  printf("%d", res.size());
  for (auto i : res) printf(" %d", i);
  putchar('\n');
}
int main() {
  int T;
  readint(T);
  while (T--) solve();
  return 0;
}
