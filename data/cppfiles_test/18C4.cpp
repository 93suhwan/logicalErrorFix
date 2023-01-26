#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 10;
int t, n, d, a[N];
int main() {
  scanf("%d", &t);
  while (t--) {
    scanf("%d%d", &n, &d);
    queue<pair<int, int>> q;
    for (int i = 0; i < n; i++) {
      scanf("%d", &a[i]);
      if (a[i] == 0) q.push({i, 0});
    }
    int maxi = 0, f = 0;
    while (q.size()) {
      auto tp = q.front();
      q.pop();
      maxi = max(maxi, tp.second);
      int pos = tp.first, to = (pos + n - d) % n;
      if (a[to] == 1) {
        a[to] = 0;
        q.push({to, tp.second + 1});
      }
    }
    for (int i = 0; i < n; i++) {
      if (a[i] == 1) f = 1;
    }
    if (f == 1)
      printf("-1\n");
    else
      printf("%d\n", maxi);
  }
}
