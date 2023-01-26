#include <bits/stdc++.h>
using namespace std;
const int N = 100010, MOD = 998244353;
int Q, n, tot, head[N], f[N];
vector<int> d[N];
struct edge {
  int next, to;
} e[N * 2];
void add(int from, int to) {
  e[++tot] = (edge){head[from], to};
  head[from] = tot;
}
int dfs(int x, int fa, int k) {
  int cnt = 0;
  for (int i = head[x]; ~i; i = e[i].next) {
    int v = e[i].to;
    if (v != fa) {
      int val = dfs(v, x, k);
      if (val == -1) return -1;
      cnt += val;
    }
  }
  if (cnt % k == 0) return 1;
  if (cnt % k == k - 1) return 0;
  return -1;
}
int main() {
  for (int i = 2; i < N; i++)
    for (int j = i; j < N; j += i) d[j].push_back(i);
  scanf("%d", &Q);
  while (Q--) {
    memset(head, -1, sizeof(head));
    memset(f, 0, sizeof(f));
    tot = 0;
    f[1] = 1;
    scanf("%d", &n);
    for (int i = 1, x, y; i < n; i++) {
      scanf("%d%d", &x, &y);
      add(x, y);
      add(y, x);
      f[1] = f[1] * 2 % MOD;
    }
    for (int i = 0; i < d[n - 1].size(); i++)
      if (dfs(1, 0, d[n - 1][i]) == 1) f[d[n - 1][i]] = 1;
    for (int i = n; i >= 1; i--)
      for (int j = i * 2; j <= n; j += i) f[i] -= f[j];
    for (int i = 1; i <= n; i++) cout << f[i] << " ";
    cout << "\n";
  }
  return 0;
}
