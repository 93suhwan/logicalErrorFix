#include <bits/stdc++.h>
using namespace std;
const long long mod = 1e9 + 7;
const long long inf = 1e18;
int main(void) {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    long long n, k;
    cin >> n >> k;
    k++;
    long long A[n];
    for (long long i = 0; i < n; i++) {
      cin >> A[i];
      long long t = 1;
      while (A[i]--) {
        t *= 10;
      }
      A[i] = t;
    }
    long long ans = 0;
    for (long long i = 0; i < n; i++) {
      long long cnt = k;
      if (i != n - 1) {
        cnt = min(cnt, A[i + 1] / A[i] - 1);
      }
      ans += A[i] * 1LL * cnt;
      k -= cnt;
      if (k == 0) break;
    }
    cout << ans << '\n';
  }
}
