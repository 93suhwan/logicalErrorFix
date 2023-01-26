#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    long long n, m, k;
    cin >> n >> m >> k;
    if (m >= n - 1 and m <= n * (n - 1) / 2) {
      int x = 2;
      if (n * (n - 1) / 2 == m) x = 1;
      if (x < k - 1)
        printf("YES\n");
      else
        printf("NO\n");
    } else
      printf("NO\n");
  }
  return 0;
}
