#include <bits/stdc++.h>
using namespace std;
long long mdc(long long a, long long b) {
  if (a < b) return mdc(b, a);
  if (b == 0) return a;
  return mdc(b, a % b);
}
long long answer(long long n) {
  if (n % 2 == 1) return n / 2;
  for (long long i = 2; i < n; i++) {
    if (mdc(n, i) == 1) return i;
  }
}
signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long t;
  cin >> t;
  while (t--) {
    long long n;
    cin >> n;
    long long ans = answer(n - 1);
    cout << ans << ' ' << n - ans - 1 << ' ' << 1 << '\n';
  }
  return 0;
}
