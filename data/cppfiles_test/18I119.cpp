#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int maxn = 2e6 + 5;
int t, n, d, vis[maxn];
queue<int> p, p2;
int main() {
  scanf("%d", &t);
  while (t--) {
    int f = 0, ans = 0;
    while (!p.empty()) p.pop();
    scanf("%d%d", &n, &d);
    for (int i = 1, x; i <= n; i++) {
      scanf("%d", &x);
      if (x == 1)
        p.push(i), vis[i] = 1;
      else
        vis[i] = 0;
    }
    while (!p.empty()) {
      int k = p.size();
      while (!p.empty()) {
        int x = p.front();
        p.pop();
        if (x < n - d + 1)
          x = d + x;
        else
          x = x - (n - d);
        if (vis[x] == 1) p2.push(x);
      }
      if (k == p2.size()) {
        f = 1;
        break;
      }
      while (!p2.empty()) {
        p.push(p2.front());
        p2.pop();
      }
      ans++;
    }
    if (f)
      printf("-1\n");
    else
      printf("%d\n", ans);
  }
}
