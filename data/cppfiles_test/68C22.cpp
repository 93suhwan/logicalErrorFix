#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 10;
int a[maxn];
int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    long long k;
    scanf("%lld", &k);
    int cnt;
    for (int i = 1; i <= 100000; i++) {
      if (k <= (long long)i * i) {
        cnt = i;
        break;
      }
    }
    if (k == cnt * cnt) {
      printf("%d %d\n", cnt, 1);
      continue;
    }
    int cn = k - (cnt - 1) * (cnt - 1);
    if (cn <= cnt) {
      printf("%d %d\n", cn, cnt);
    } else {
      printf("%d %d\n", cnt, 2 * cnt - cn);
    }
  }
  return 0;
}
