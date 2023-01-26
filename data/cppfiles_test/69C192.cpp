#include <bits/stdc++.h>
using namespace std;
long long T, n, m, ans;
long long cnt, cntn, cntm, lst;
long long a[35], b[35];
signed main() {
  scanf("%lld", &T);
  a[0] = -1, b[0] = -2;
  for (long long Case = 1; Case <= T; ++Case) {
    cntn = cntm = 0;
    ans = 1e9;
    scanf("%lld", &n);
    while (n) {
      a[++cntn] = n % 10;
      n /= 10;
    }
    for (long long c = 0; c <= 63; ++c) {
      m = (1ll << c);
      lst = cntn;
      cnt = 0;
      cntm = 0;
      while (m) {
        b[++cntm] = m % 10;
        m /= 10;
      }
      for (long long i = cntm; i; --i) {
        bool flag = false;
        for (long long j = lst; j; --j) {
          if (a[j] == b[i]) {
            lst = j - 1;
            ++cnt;
            flag = true;
            break;
          }
        }
        if (!flag) break;
      }
      ans = std::min(ans, cntm - cnt + cntn - cnt);
    }
    printf("%d\n", ans);
  }
  return 0;
}
