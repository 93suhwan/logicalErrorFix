#include <bits/stdc++.h>
using namespace std;
const long long P = 1e9 + 7;
signed main() {
  long long T;
  cin >> T;
  while (T--) {
    long long n, m, k;
    cin >> n >> m >> k;
    if (m > n * (n - 1) / 2 || m < n - 1) {
      puts("NO");
    } else {
      if (n == 1) {
        if (k >= 2) {
          puts("YES");
        } else {
          puts("NO");
        }
        break;
      }
      if (k >= 4) {
        puts("YES");
      } else {
        if (k <= 2) {
          puts("NO");
        } else {
          if (m == n * (n - 1) / 2) {
            puts("YES");
          } else {
            puts("NO");
          }
        }
      }
    }
  }
  return 0;
}
