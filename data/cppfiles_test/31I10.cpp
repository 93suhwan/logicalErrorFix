#include <bits/stdc++.h>
using namespace std;
int son[2000010][2], k, n, cnt = 1;
int ans[20][2000010];
void ins(int x) {
  int u = 1;
  for (int i = k - 1; i > -1; i--) {
    int v = (x >> i) & 1;
    if (!son[u][v]) son[u][v] = ++cnt;
    u = son[u][v];
  }
}
void calc(int id, int d, int x) {
  int t = (x >> (d - 1)) & 1;
  int u = son[id][t], sum1, sum2 = x | (1 << (d - 1));
  sum1 = sum2 ^ (1 << (d - 1));
  for (int i = d - 2; i > -1; i--) {
    int v = (x >> i) & 1;
    if (son[u][v ^ 1]) {
      u = son[u][v ^ 1];
      sum1 |= 1 << i;
    } else {
      u = son[u][v];
      sum1 ^= v << i;
    }
  }
  u = son[id][t ^ 1];
  cout << sum1 << " " << sum2 << endl;
  for (int i = d - 2; i > -1; i--) {
    int v = (x >> i) & 1;
    cout << u << " " << v << " " << son[u][v] << " " << son[u][v ^ 1] << endl;
    if (son[u][v]) {
      u = son[u][v];
      sum2 ^= v << i;
    } else {
      u = son[u][v ^ 1];
      sum2 |= 1 << i;
    }
  }
  cout << d << " " << x << " " << sum1 << " " << sum2 << " " << id << endl;
  ans[d][x] = min(ans[d][x], abs(sum1 - sum2));
}
void dfs(int u, int d) {
  if (d <= 0) return;
  if (son[u][0] && son[u][1])
    for (int i = 0; i < 1 << d; i++) calc(u, d, i);
  if (son[u][0]) dfs(son[u][0], d - 1);
  if (son[u][1]) dfs(son[u][1], d - 1);
}
int main() {
  int x;
  cnt = 0;
  memset(ans, 127, sizeof(ans));
  scanf("%d%d", &k, &n);
  for (int i = 1; i <= n; i++) {
    scanf("%d", &x);
    ins(x);
  }
  cout << "input:ok\n";
  dfs(1, k);
  cout << "dfs:ok\n";
  for (int i = 0; i < 1 << k; i++) {
    int res = 2e9;
    for (int j = k; j; j--)
      res = min(res, ans[j][i & ((1 << j) - 1)]),
      cout << ans[j][i & ((1 << j) - 1)] << " " << j << " "
           << (i & ((1 << j) - 1)) << endl;
    printf("%d ", res);
    cout << endl;
  }
}
