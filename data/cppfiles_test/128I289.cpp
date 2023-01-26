#include <bits/extc++.h>
#include <bits/stdc++.h>

using namespace std;
using namespace __gnu_pbds;

const int maxn = 2e5 + 7;
const int maxm = 2e6 + 7;
const int mod = 998244353;

long long gcd(long long a, long long b) { return b == 0 ? a : gcd(b, a % b); }

int T;
int n;
int a, b, c;

bool check() {
  return a > 0 && b > 0 && c > 0 && a + b + c == n && gcd(a, b) == c &&
         a != b && a != c && b != c;
}

int main() {
#ifndef ONLINE_JUDGE
  freopen("1.in", "r", stdin);
  //  freopen("1.out", "w", stdout);
#endif
  scanf("%d", &T);
  while (T--) {
    scanf("%d", &n);

    for (c = 1; c * c <= n; c++) {
      if (n % c) {
        continue;
      }
      int num = n / c - 1;
      if (num & 1) {
        a = 2 * c;
        b = (num - 2) * c;
      } else {
        a = 3 * c;
        b = (num - 3) * c;
      }
      if (check()) {
        break;
      }
    }
    printf("%d %d %d\n", a, b, c);
  }
  return 0;
}
