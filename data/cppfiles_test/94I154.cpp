#include <bits/stdc++.h>
using namespace std;
const long long mod = 1e9 + 7;
const long long inf = 1e18;
long long powerof10(long long a) {
  if (a == 0)
    return 1;
  else {
    int b = 1;
    for (int i = 1; i <= a; i++) {
      b *= 10;
    }
    return b;
  }
}
long long val(long long space) { return powerof10(space) - 1; }
int main(void) {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    long long n, k;
    cin >> n >> k;
    long long ans = 0;
    long long A[n];
    for (long long i = 0; i < n; i++) {
      cin >> A[i];
    }
    for (long long i = 1; i <= n; i++) {
      if (i == n) {
        ans += powerof10(A[i - 1]) * (k + 1);
        break;
      }
      long long space = A[i] - A[i - 1];
      ans += powerof10(A[i - 1]) * min(k, val(space));
      k -= min(k, val(space));
      if (k == 0) {
        ans += powerof10(A[i - 1]);
        break;
      }
    }
    cout << ans << '\n';
  }
}
