#include <bits/stdc++.h>
using namespace std;
signed main() {
  long long T;
  cin >> T;
  while (T--) {
    long long n, m, k;
    cin >> n >> m >> k;
    long long ans = n * (n - 1) / 2;
    if (m < n - 1 || m > ans) {
      printf("NO\n");
      continue;
    }
    if (k - 2 < 0) {
      printf("NO\n");
    } else if (k - 2 >= 2) {
      printf("YES\n");
    } else if (k - 2 == 1 && m == ans) {
      printf("YES\n");
    } else if (k - 2 == 0 && n == 1) {
      printf("YES\n");
    } else
      printf("NO\n");
  }
}
