#include <bits/stdc++.h>
using namespace std;
const int maxn = 3e5 + 2;
const int maxm = 1e5 + 5;
const int inf = 0x3f3f3f3f;
int read() {
  int s = 0, w = 1;
  char c = getchar();
  for (; !isdigit(c); c = getchar()) {
    if (c == '-') w = -1;
  }
  for (; isdigit(c); c = getchar()) {
    s = (s << 3) + (s << 1) + (c ^ 48);
  }
  return (w == 1 ? s : -s);
}
int n, m, cir;
int a[maxn], cnt[maxn], p[maxn];
bool vis[maxn];
vector<int> ans;
int fa[maxn];
int getfa(int x) {
  if (fa[x] != x) fa[x] = getfa(fa[x]);
  return fa[x];
}
int main() {
  int t = read();
  while (t--) {
    ans.clear();
    n = read(), m = read();
    for (int i = 1; i <= n; i++) {
      a[i] = read();
      cnt[(i - a[i] + n) % n]++;
    }
    for (int k = 0; k < n; k++) {
      if (n - cnt[k] <= 2 * m) {
        int sum = 0;
        for (int i = 1; i <= n; i++) fa[i] = i;
        for (int i = 1; i <= n; i++) {
          int u = i, v = a[(i - 1 + k + n) % n + 1];
          int x = getfa(u), y = getfa(v);
          if (x != y) {
            sum++;
            fa[x] = y;
          }
        }
        if (sum <= m) ans.push_back(k);
      }
    }
    printf("%d", ans.size());
    for (auto k : ans) {
      printf(" %d", k);
    }
    puts("");
  }
  return 0;
}
