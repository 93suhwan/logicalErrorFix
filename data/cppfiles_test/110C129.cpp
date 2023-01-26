#include <bits/stdc++.h>
using namespace std;
int T, n, tot, ans, num;
const int maxn = 1e6 + 10;
int d[maxn], head[maxn], v[maxn], Next[maxn], dp[maxn];
priority_queue<int, vector<int>, greater<int> > q;
void init() {
  num = n;
  tot = 0;
  ans = 1;
  for (int i = 1; i <= n; i++) head[i] = d[i] = 0, dp[i] = 1;
}
void add(int x, int y) {
  v[++tot] = y;
  Next[tot] = head[x];
  head[x] = tot;
}
void bfs() {
  while (q.size()) {
    int x = q.top();
    q.pop();
    num--;
    ans = max(ans, dp[x]);
    for (int i = head[x]; i; i = Next[i]) {
      int y = v[i];
      d[y]--;
      if (y < x)
        dp[y] = max(dp[y], dp[x] + 1);
      else
        dp[y] = max(dp[y], dp[x]);
      if (!d[y]) {
        q.push(y);
      }
    }
  }
}
int main() {
  scanf("%d", &T);
  while (T--) {
    scanf("%d", &n);
    init();
    for (int i = 1; i <= n; i++) {
      int len;
      scanf("%d", &len);
      for (int j = 1; j <= len; j++) {
        int t;
        scanf("%d", &t);
        add(t, i);
        d[i]++;
      }
    }
    for (int i = 1; i <= n; i++) {
      if (!d[i]) q.push(i);
    }
    bfs();
    if (num)
      printf("-1\n");
    else
      printf("%d\n", ans);
  }
  return 0;
}
