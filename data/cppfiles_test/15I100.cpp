#include <bits/stdc++.h>
using namespace std;
const int maxn = 110;
const long long int mod = 1e9 + 7;
int head[maxn], sons[maxn][maxn];
long long int c[maxn][maxn];
struct edge {
  int to, next;
} e[maxn * 2];
int cnt;
void add(int x, int y) {
  e[cnt].to = y;
  e[cnt].next = head[x];
  head[x] = cnt++;
}
void dfs(int rt, int u, int fa, int deep) {
  sons[rt][deep]++;
  for (int i = head[u]; i != -1; i = e[i].next) {
    int v = e[i].to;
    if (v == fa) continue;
    dfs(rt, v, u, deep + 1);
  }
}
int main() {
  c[0][0] = 1;
  for (int i = 1; i < maxn; i++) {
    c[i][0] = 1;
    for (int j = 1; j <= i; j++) {
      c[i][j] = (c[i - 1][j - 1] + c[i - 1][j]) % mod;
    }
  }
  int t, n, x, y, k;
  cin >> t;
  while (t--) {
    long long int ans = 0;
    memset(head, -1, sizeof(head));
    cin >> n >> k;
    for (int i = 1; i < n; i++) {
      cin >> x >> y;
      add(x, y);
      add(y, x);
    }
    if (k == 2) {
      cout << c[n][2] << endl;
      continue;
    }
    for (int i = 1; i <= n; i++) {
      memset(sons, 0, sizeof(sons));
      for (int u = head[i]; u != -1; u = e[u].next) {
        int v = e[u].to;
        dfs(v, v, i, 1);
      }
      for (int j = 1; j <= 100; j++) {
        long long int tmp = 1;
        int tot = 0;
        for (int u = head[i]; u != -1; u = e[u].next) {
          int v = e[u].to;
          if (sons[v][j] > 0) {
            tot++;
            tmp = (tmp * sons[v][j]) % mod;
          }
        }
        if (tot < k)
          break;
        else
          ans = (ans + (c[tot][k] * tmp) % mod) % mod;
      }
    }
    cout << ans << endl;
  }
  return 0;
}
