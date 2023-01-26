#include <bits/stdc++.h>
using namespace std;
set<int> se;
int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int n, k;
    se.clear();
    scanf("%d%d", &n, &k);
    int mark = n;
    int b[20];
    int tcnt = 0;
    while (n) {
      b[++tcnt] = n % 10;
      n /= 10;
    }
    int vis[10] = {0};
    int nowcnt = 0;
    int i;
    int markstart;
    for (i = tcnt; i >= 1; i--) {
      if (vis[b[i]] == 0) {
        nowcnt++;
        vis[b[i]] = 1;
        if (nowcnt <= k) se.insert(b[i]);
        if (nowcnt == k) markstart = i;
      }
      if (nowcnt > k) {
        if (b[i] > (*(--se.end()))) {
          for (int j = i + 1; j < markstart; j++) {
            if (b[j] < (*(--se.end()))) {
              b[j] = (*se.upper_bound(b[j]));
              i = j - 1;
              goto endd2;
            }
          }
          goto endd;
        } else {
          b[i] = (*se.lower_bound(b[i]));
          i--;
          break;
        }
      }
    }
  endd2:;
    for (; i >= 1; i--) b[i] = (*se.begin());
    if (nowcnt <= k)
      printf("%d\n", mark);
    else {
      for (int i = tcnt; i >= 1; i--) printf("%d", b[i]);
      cout << endl;
    }
    continue;
  endd:;
    se.clear();
    memset(vis, 0, sizeof(vis));
    nowcnt = 0;
    for (i = tcnt; i >= 1; i--) {
      if (vis[b[i]] == 0) {
        nowcnt++;
        vis[b[i]] = 1;
        if (nowcnt < k) se.insert(b[i]);
      }
      if (nowcnt == k) {
        se.insert(b[i] + 1);
        if (se.size() < k) se.insert(0);
        b[i]++;
        i--;
        break;
      }
    }
    for (; i >= 1; i--) b[i] = (*se.begin());
    for (int i = tcnt; i >= 1; i--) printf("%d", b[i]);
    cout << endl;
  }
  return 0;
}
