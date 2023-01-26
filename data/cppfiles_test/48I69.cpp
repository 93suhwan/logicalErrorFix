#include <bits/stdc++.h>
using namespace std;
inline long long rd() {
  char c = getchar();
  long long s = 0;
  bool f = 1;
  for (; c < '0' || c > '9'; c = getchar())
    if (c == '-') f = 0;
  for (; c >= '0' && c <= '9'; c = getchar())
    s = (s << 3) + (s << 1) + (c ^ 48);
  return f ? s : ~(s - 1);
}
inline void wt(long long x) { printf("%lld", x); }
inline void wtl(long long x) { printf("%lld\n", x); }
inline void wtb(long long x) { printf("%lld ", x); }
const int N = 5e5 + 10, mod = 1e9 + 7;
int n, a[N], b[N];
int cnt[N];
int fa[N];
int find(int x) { return fa[x] == x ? x : fa[x] = find(fa[x]); }
bool same[N];
vector<int> id[N];
int to[N];
int sz[N];
bool vis[N];
inline void work() {
  n = rd();
  memset(cnt + 1, 0, n << 2);
  memset(sz + 1, 0, n << 2);
  for (int i = 1; i <= n; ++i) a[i] = rd(), b[i] = a[i];
  sort(b + 1, b + 1 + n);
  bool flag = 1;
  for (int i = 1; i < n; ++i) {
    if (a[i] > a[i + 1]) {
      flag = 0;
      break;
    }
  }
  if (flag) {
    puts("YES");
    return;
  }
  if (n == 2) {
    puts("NO");
    return;
  }
  for (int i = 1; i <= n; ++i) id[i].clear();
  for (int i = 1; i <= n; ++i) same[i] = a[i] == b[i];
  for (int i = 1; i <= n; ++i) {
    if (!same[i])
      id[b[i]].push_back(i);
    else
      ++cnt[b[i]];
  }
  for (int i = 1; i <= n; ++i) fa[i] = i;
  for (int i = 1; i <= n; ++i) {
    if (same[i])
      to[i] = i;
    else {
      to[i] = id[a[i]].back();
      id[a[i]].pop_back();
    }
  }
  int c2 = 0;
  int h = 0;
  memset(vis + 1, 0, n);
  for (int i = 1; i <= n; ++i) {
    if (vis[i]) continue;
    int ss = 1;
    int x = to[i];
    vis[i] = 1;
    while (x != i) {
      vis[x] = 1;
      x = to[x];
      ++ss;
    }
    sz[++h] = ss;
  }
  for (int i = 1; i <= h; ++i) {
    if (sz[i] == 2) ++c2;
  }
  if (c2 != 1) {
    puts("YES");
    return;
  }
  memset(vis + 1, 0, n);
  for (int i = 1; i <= n; ++i) {
    if (vis[i]) continue;
    int ss = 1;
    int x = to[i];
    vis[i] = 1;
    while (x != i) {
      vis[x] = 1;
      x = to[x];
      ++ss;
    }
    if (ss > 2) {
      x = to[i];
      while (x != i) {
        x = to[x];
        if (cnt[a[x]] >= 1) {
          puts("YES");
          return;
        }
      }
    }
  }
  puts("NO");
}
int main() {
  int T = 1;
  T = rd();
  for (int i = 1; i <= T; ++i) {
    work();
  }
  return 0;
}
