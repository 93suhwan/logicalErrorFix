#include <bits/stdc++.h>
using namespace std;
const int dx[] = {-1, 1, 0, 0, -1, -1, 1, 1};
const int dy[] = {0, 0, -1, 1, -1, 1, -1, 1};
int64_t brute(int64_t x0, int64_t n) {
  for (int i = 0; i < n; ++i) {
    if (x0 % 2 == 0) {
      x0 -= (i + 1);
    } else {
      x0 += (i + 1);
    }
  }
  return x0;
}
long long MOD(long long N, long long M) {
  long long ans = N % M;
  if (ans < 0) return ans + M;
  return ans;
}
int main() {
  int t = 1;
  cin >> t;
  while (t--) {
    long long x0, n;
    cin >> x0 >> n;
    long long ans = 0;
    if (x0 % 2 == 0) {
      if (MOD(n, 4) == 1)
        ans = x0 - n;
      else if (MOD(n, 4) == 2)
        ans = x0 - n + (n + 1);
      else if (MOD(n, 4) == 3)
        ans = x0 + n + 1;
      else {
        ans = x0;
      }
    } else {
      if (MOD(n, 4) == 3)
        ans = x0 - n - 1;
      else if (MOD(n, 4) == 0)
        ans = x0 - n + n;
      else if (MOD(n, 4) == 2)
        ans = x0 - 1;
      else
        ans = x0 + n;
    }
    cout << ans << '\n';
  }
  return 0;
}
