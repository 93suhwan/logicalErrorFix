#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 10;
int t, n, d, a[N];
int cnt[N];
int main() {
  scanf("%d", &t);
  while (t--) {
    memset(cnt, 0, sizeof cnt);
    scanf("%d%d", &n, &d);
    queue<pair<int, int>> q;
    for (int i = 0; i < n; i++) {
      scanf("%d", &a[i]);
      if (a[i] == 1) q.push({i, 1});
    }
    int maxi = 0, cnt = 0, fl = 0, f = 0;
    while (q.size()) {
      auto tp = q.front();
      q.pop();
      maxi = max(maxi, tp.second);
      int pos = tp.first, to = (pos + n - d) % n;
      if (fl == 0 && cnt > n) {
        f = 1;
        break;
      }
      if (a[to] == 1) {
        q.push({to, tp.second + 1});
        fl = 0;
        cnt++;
      } else {
        a[to] = 0;
        fl = 1, cnt = 0;
        ;
      }
    }
    if (f == 1)
      printf("-1\n");
    else
      printf("%d\n", maxi);
  }
}
