#include <bits/stdc++.h>
using namespace std;
int T;
long long n, m, k;
int main() {
  scanf("%d", &T);
  while (T--) {
    scanf("%lld%lld%lld", &n, &m, &k);
    k -= 2;
    if (n == 1 && m == 0) {
      if (k >= 0)
        puts("YES");
      else
        puts("NO");
    } else if (m < n - 1 || n * (n - 1) / 2 < m)
      puts("NO");
    else {
      if (m >= n - 1 && m < n * (n - 1) / 2) {
        if (k >= 2)
          puts("YES");
        else
          puts("NO");
      } else if (m == n * (n - 1) / 2) {
        if (k >= 1)
          puts("YES");
        else
          puts("NO");
      }
    }
  }
  return 0;
}
