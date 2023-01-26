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
    ans = n * (n - 1) / 2 + 1 - m;
    if (n == 1) ans = 0;
    if (ans < k - 1)
      printf("YES\n");
    else
      printf("NO\n");
  }
}
