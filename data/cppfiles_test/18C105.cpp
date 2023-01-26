#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int maxn = 2e6 + 5;
int t, n, d, a[maxn];
struct node {
  int x, dep;
};
queue<node> p;
int main() {
  scanf("%d", &t);
  while (t--) {
    int f = 0, ans = 0;
    scanf("%d%d", &n, &d);
    for (int i = 0; i < n; i++) {
      scanf("%d", &a[i]);
      if (a[i] == 0) p.push({i, 0});
    }
    while (!p.empty()) {
      int x = p.front().x, dep = p.front().dep;
      p.pop();
      int y = (x + d) % n;
      if (a[y]) {
        a[y] = 0;
        p.push({y, dep + 1});
        ans = max(ans, dep + 1);
      }
    }
    for (int i = 0; i < n; i++)
      if (a[i]) f = 1;
    if (f)
      printf("-1\n");
    else
      printf("%d\n", ans);
  }
}
