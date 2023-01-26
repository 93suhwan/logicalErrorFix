#include <bits/stdc++.h>
using namespace std;
long long binaryExponentiation(long long x, long long m) {
  if (x == 1) {
    return 0;
  } else {
    return 1 + (((binaryExponentiation((x / 2), m))));
  }
}
long long sumd(long long a) {
  long long ans = 0;
  while (a != 0) {
    ans += a % 10;
    a = a / 10;
  }
  return ans;
}
long long check(long long n, long long A[], long long m) {
  long long ans = 0;
  for (long long q = 0; q < m; q++) {
    if ((A[q] - n) > 0) ans += A[q] - n;
  }
  return ans;
}
void solve() {
  long long n;
  cin >> n;
  while (n--) {
    long long a;
    cin >> a;
    if (a == 0)
      cout << 0 << " " << 0 << endl;
    else {
      long long l, p, lp, r;
      l = sqrt(2 * a);
      while (1 > 0) {
        r = (l * (l + 1)) / 2;
        p = r - a;
        if (p >= 0) {
          lp = sqrt(2 * p);
          if (p == ((lp + 2) * (lp + 1)) / 2 || p == (lp * (lp + 1)) / 2) break;
        }
        l += 1;
      }
      cout << lp << " " << l << endl;
    }
  }
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  solve();
  return 0;
}
