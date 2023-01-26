#include <bits/stdc++.h>
using namespace std;
template <typename T>
inline void read(T &f) {
  f = 0;
  T fu = 1;
  char c = getchar();
  while (c < '0' || c > '9') {
    if (c == '-') {
      fu = -1;
    }
    c = getchar();
  }
  while (c >= '0' && c <= '9') {
    f = (f << 3) + (f << 1) + (c & 15);
    c = getchar();
  }
  f *= fu;
}
template <typename T>
void print(T x) {
  if (x < 0) putchar('-'), x = -x;
  if (x < 10)
    putchar(x + 48);
  else
    print(x / 10), putchar(x % 10 + 48);
}
template <typename T>
void print(T x, char t) {
  print(x);
  putchar(t);
}
const int N = 1005, INF = 1e9;
vector<int> adj[N];
int a[N], b[N], st[N], used[N], fr[N];
int T, n, m, top, sum;
bool dfs1(int u, int fa, int now) {
  if (fr[u]) {
    for (int i = 1; i <= top; i++) {
      if (!used[st[i]]) {
        used[st[i]] = 1;
        sum = min(sum + b[st[i]], INF);
      }
    }
    int tem = u;
    while (!used[tem]) {
      used[tem] = 1;
      sum = min(sum + b[tem], INF);
      tem = fr[tem];
    }
    return 1;
  }
  fr[u] = fa;
  st[++top] = u;
  for (int i = 0; i < (int)adj[u].size(); i++) {
    int v = adj[u][i];
    if (v == fa) continue;
    if (now >= a[v] && !used[v] && v != fa) {
      int tem = dfs1(v, u, min(now + b[v], INF));
      if (tem) return 1;
    }
  }
  --top;
  return 0;
}
bool check(int mid) {
  memset(used, 0, sizeof(used));
  used[1] = 1;
  sum = mid;
  while (1) {
    int cando = 1;
    for (int i = 1; i <= n; i++) {
      if (!used[i]) {
        cando = 0;
        break;
      }
    }
    if (cando) return 1;
    int found = 0;
    memset(fr, 0, sizeof(fr));
    top = 0;
    for (int i = 1; i <= n; i++) {
      if (used[i]) {
        found = dfs1(i, 0, sum);
        if (found) break;
      }
    }
    if (!found) return 0;
  }
  assert(0);
}
int main() {
  read(T);
  while (T--) {
    read(n);
    read(m);
    for (int i = 1; i <= n; i++) adj[i].clear();
    for (int i = 2; i <= n; i++) read(a[i]);
    for (int i = 2; i <= n; i++) read(b[i]);
    for (int i = 1; i <= m; i++) {
      int u, v;
      read(u);
      read(v);
      adj[u].push_back(v);
      adj[v].push_back(u);
    }
    int l = 1, r = INF, ans = r;
    while (l <= r) {
      int mid = (l + r) >> 1;
      if (check(mid))
        ans = mid, r = mid - 1;
      else
        l = mid + 1;
    }
    print(ans + 1, '\n');
  }
  return 0;
}
