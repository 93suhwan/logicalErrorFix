#include <bits/stdc++.h>
using namespace std;
template <typename T>
void read(T &x) {
  x = 0;
  int op = 1;
  char c = getchar();
  while (!isdigit(c)) {
    if (c == '-') op = -1;
    c = getchar();
  }
  while (isdigit(c)) {
    x = (x << 1) + (x << 3) + (c ^ 48);
    c = getchar();
  }
  x *= op;
}
inline void swap(int &x, int &y) { x ^= y ^= x ^= y; }
inline int min(int x, int y) { return x < y ? x : y; }
inline int max(int x, int y) { return x > y ? x : y; }
const int MN = 1005;
int n, m, a[MN], b[MN];
vector<int> G[MN];
void Adde(int x, int y) {
  G[x].push_back(y);
  G[y].push_back(x);
}
queue<int> q;
int ins[MN], pre[MN], vis[MN];
long long val[MN];
bool Judge(int S) {
  ins[1] = 1;
  for (int i = (2); i <= (n); ++i) ins[i] = 0;
  long long sum = S;
  while (1) {
    for (int i = 1; i <= n; ++i) vis[i] = ins[i], pre[i] = 0, val[i] = 0;
    while (!q.empty()) q.pop();
    for (int i = 1; i <= n; ++i)
      if (ins[i]) q.push(i), val[i] = sum;
    pair<int, int> pos = make_pair(0, 0);
    while (!q.empty()) {
      int x = q.front();
      q.pop();
      for (int y : G[x])
        if (!ins[x] || !ins[y]) {
          if (y == pre[x] || val[x] <= a[y]) continue;
          if (vis[y]) {
            pos = make_pair(x, y);
            break;
          }
          vis[y] = 1;
          val[y] = val[x] + b[y];
          pre[y] = x;
          q.push(y);
        }
      if (pos.first) break;
    }
    if (!pos.first) return 0;
    for (int i = pos.first; !ins[i]; i = pre[i]) ins[i] = 1, sum += b[i];
    for (int i = pos.second; !ins[i]; i = pre[i]) ins[i] = 1, sum += b[i];
    bool ok = 1;
    for (int i = 1; i <= n; ++i) ok &= ins[i];
    if (ok) return 1;
  }
  return 0;
}
int main() {
  int Tests;
  read(Tests);
  while (Tests--) {
    read(n);
    read(m);
    for (int i = (1); i <= (n); ++i) G[i].clear();
    for (int i = (2); i <= (n); ++i) read(a[i]);
    for (int i = (2); i <= (n); ++i) read(b[i]);
    for (int i = 1, u, v; i <= m; ++i) read(u), read(v), Adde(u, v);
    int l = 1, r = 1e9 + 1, mid, ans = 0;
    while (l <= r) {
      mid = (l + r) >> 1;
      if (Judge(mid))
        ans = mid, r = mid - 1;
      else
        l = mid + 1;
    }
    printf("%d\n", ans);
  }
  return 0;
}
