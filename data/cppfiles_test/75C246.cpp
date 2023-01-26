#include <bits/stdc++.h>
using namespace std;
const int maxN = 200000 + 5;
struct noob {
  int val, pri;
  friend bool operator<(noob a, noob b) { return a.pri < b.pri; }
} e[maxN];
int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int n, k, p, tem, ans = 0, now = 0;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
      scanf("%d", &k);
      tem = 0;
      for (int j = 1; j <= k; j++) {
        scanf("%d", &p);
        p++;
        p -= j;
        p++;
        tem = max(tem, p);
      }
      e[i].pri = tem;
      e[i].val = k;
    }
    sort(e + 1, e + 1 + n);
    for (int i = 1; i <= n; i++) {
      if (now < e[i].pri) {
        ans += e[i].pri - now;
        now = e[i].pri;
      }
      now += e[i].val;
    }
    printf("%d\n", ans);
  }
}
