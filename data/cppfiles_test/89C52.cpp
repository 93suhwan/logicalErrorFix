#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 10;
int head[maxn], cnt, T, n;
int x, y, ans = 0;
struct node {
  int to, next;
  int dis;
} e[maxn * 2];
void add(int x, int y, int z) {
  e[++cnt].dis = z;
  e[cnt].to = y;
  e[cnt].next = head[x];
  head[x] = cnt;
}
int dfs(int now, int fa) {
  int u = now;
  int tot = 0;
  int yz = 0;
  int kq = 0;
  int qt = 0;
  for (int i = head[u]; i; i = e[i].next) {
    int v = e[i].to;
    if (v == fa) continue;
    tot++;
    int val = dfs(v, u);
    if (val == 1)
      yz++;
    else if (val == 2)
      kq++;
    else
      qt++;
  }
  if (tot == 0) return 1;
  if (tot == yz) {
    return 2;
  }
  if (kq != 0) {
    if (kq == tot) {
      ans -= tot - 1;
      return 1;
    }
    ans -= kq;
    if (qt == 0) {
      return 2;
    } else {
      return 3;
    }
  }
  return 3;
}
void init() {
  cnt = 0;
  ans = 0;
  for (int i = 0; i <= n; i++) {
    head[i] = 0;
  }
}
int main() {
  cin >> T;
  while (T--) {
    cin >> n;
    init();
    for (int i = 1; i < n; i++) {
      cin >> x >> y;
      add(x, y, 1);
      add(y, x, 1);
    }
    for (int i = 1; i <= n; i++) {
      int num = 0;
      for (int j = head[i]; j; j = e[j].next) {
        int v = e[j].to;
        if (v == i) continue;
        num++;
      }
      if (num == 1 && i != 1) ans++;
    }
    dfs(1, 0);
    cout << ans << endl;
  }
  return 0;
}
