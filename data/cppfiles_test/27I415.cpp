#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
int main() {
  int t;
  cin >> t;
  while (t--) {
    long long n, m, k;
    scanf("%lld%lld%lld", &n, &m, &k);
    long long top = n * (n - 1) / 2;
    long long down = n - 1;
    if (n == 1) {
      if (m) {
        puts("NO");
      } else {
        puts("YES");
      }
    } else {
      if (m > top)
        puts("NO");
      else if (m == top) {
        if (k > 2)
          puts("YES");
        else
          puts("NO");
      } else if (m >= down && m < top) {
        if (k > 3)
          puts("YES");
        else
          puts("NO");
      }
    }
  }
  return 0;
}
