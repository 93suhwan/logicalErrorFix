#include <bits/stdc++.h>
using namespace std;
const int N = 1 << 19;
const int inf = 1 << 29;
vector<int> d[N + N];
void reg(int l, int r, int x, int L = 0, int R = N, int p = 1) {
  if (r <= L || R <= l) return;
  if (l <= L && R <= r) {
    d[p].push_back(x);
    return;
  }
  reg(l, r, x, L, (L + R) / 2, p + p);
  reg(l, r, x, (L + R) / 2, R, p + p + 1);
}
int a[300010], b[300010];
vector<int> e[300010];
int dp[300010], pv[300010], q[300010], qs, qe;
void go(int p, int x, int v) {
  p += N;
  while (p > 1) {
    vector<int> &w = d[p];
    for (int i = 0; i < w.size(); i++) {
      int u = w[i];
      if (dp[u] == inf) {
        dp[u] = x;
        pv[u] = v;
        q[qe++] = u;
      }
    }
    w.clear();
    p >>= 1;
  }
}
int main() {
  int n;
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%d", &a[i]);
    reg(i - a[i], i + 1, i);
  }
  for (int i = 1; i <= n; i++) {
    scanf("%d", &b[i]);
    e[i + b[i]].push_back(i);
  }
  dp[0] = 0;
  for (int i = 1; i <= n; i++) {
    dp[i] = inf;
    if (a[i] == i) {
      dp[i] = 1;
      pv[i] = 0;
      q[qe++] = i;
    }
  }
  while (qs < qe) {
    int v = q[qs++], x = dp[v];
    for (int i = 0; i < e[v].size(); i++) {
      int w = e[v][i];
      go(w, x + 1, w);
    }
  }
  if (dp[n] == inf) {
    puts("-1");
  } else {
    printf("%d\n", dp[n]);
    int x = n;
    while (x) {
      x = pv[x];
      printf("%d ", x);
      x += b[x];
    }
  }
  return 0;
}
