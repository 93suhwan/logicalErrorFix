#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e6 + 9;
int a[maxn], use[maxn];
int main() {
  int T, n, d;
  cin >> T;
  while (T--) {
    memset(use, 0, sizeof(use));
    cin >> n >> d;
    for (int i = 0; i < n; i++) scanf("%d", &a[i]);
    int flag = 0, res = 0;
    for (int i = 0; i < n; i++) {
      if (use[i]) continue;
      int cur = i, pref = 0, Last = 0, iter = 0, ans = 0;
      do {
        use[cur] = 1;
        if (a[cur] == 0) {
          ans = max(ans, Last);
          Last = 0;
        } else {
          Last++;
          if (iter == pref) pref++;
        }
        cur = (cur + d) % n;
        iter++;
      } while (cur != i);
      if (iter != pref)
        ans = max(ans, pref + Last);
      else {
        flag = true;
        break;
      }
      res = max(res, ans);
    }
    if (flag)
      cout << "-1\n";
    else
      cout << res << "\n";
  }
}
