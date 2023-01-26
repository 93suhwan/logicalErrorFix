#include <bits/stdc++.h>
using namespace std;
long long a[1005];
int main(void) {
  int n;
  scanf("%d", &n);
  for (int(i) = 0; (i) < (n); (i)++) {
    scanf("%lld", &a[i]);
  }
  long long ans = 0;
  for (int i = 0; i < n; i += 2) {
    long long s = a[i];
    long long add = 0;
    for (int j = i + 1; j < n; j++) {
      if (j % 2) {
        long long cur_j = a[j];
        long long mn = min(add, a[j]);
        add -= mn;
        cur_j -= mn;
        if (add == 0) {
          long long r = min(s, cur_j);
          ans += r + (j == i + 1 ? 0 : 1);
          s -= r;
          cur_j -= r;
          if (cur_j) {
            break;
          }
        }
      } else {
        add += a[j];
      }
    }
  }
  printf("%lld\n", ans);
}
