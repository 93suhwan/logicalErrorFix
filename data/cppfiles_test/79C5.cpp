#include <bits/stdc++.h>
using namespace std;
const double eps = 1e-10, pi = 3.1415926535898;
const int mod = 1e9 + 7, maxn = 3e5 + 10;
int T, n, m, k, x, y, a[maxn], b[maxn], check[maxn];
int dp[maxn], c[maxn], d[maxn];
set<int> s;
int main(int argc, char const *argv[]) {
  T = 1;
  for (int _ = 1; _ <= T; ++_) {
    int ans = mod;
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
      scanf("%d", a + i);
      if (a[i] == i) {
        check[i] = 1;
      }
    }
    for (int i = 1; i < n; ++i) {
      dp[i] = -1;
      s.insert(-i);
    }
    for (int i = 1; i <= n; ++i) {
      scanf("%d", &x);
      b[i] = i + x;
    }
    dp[n] = 0;
    queue<int> q;
    q.push(n);
    while (!q.empty()) {
      x = q.front();
      q.pop();
      auto it = s.lower_bound(-x);
      while (it != s.end() and x + (*it) <= a[x]) {
        y = -(*it);
        if (dp[b[y]] == -1) {
          c[b[y]] = y;
          d[b[y]] = x;
          dp[b[y]] = dp[x] + 1;
          q.push(b[y]);
        }
        it = s.erase(it);
      }
    }
    for (int i = 1; i <= n; ++i) {
      if (check[i] and dp[i] != -1) {
        if (dp[i] + 1 < ans) {
          y = i;
          ans = dp[i] + 1;
        }
      }
    }
    if (ans == mod)
      printf("-1\n");
    else {
      std::stack<int> v;
      v.push(0);
      while (y != n) {
        v.push(c[y]);
        y = d[y];
      }
      printf("%d\n", ans);
      while (!v.empty()) {
        printf("%d ", v.top());
        v.pop();
      }
    }
  }
  return 0;
}
