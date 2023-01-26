#include <bits/stdc++.h>
using namespace std;
const long long INF = 1e18;
long long A[200005];
long long gcd(long long a, long long b) {
  a = abs(a);
  b = abs(b);
  if (a < b) swap(a, b);
  while (b) {
    a = a % b;
    swap(a, b);
  }
  return a;
}
signed main() {
  cin.sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long t;
  cin >> t;
  while (t--) {
    long long N;
    cin >> N;
    long long i;
    for (i = 0; i < N; i++) cin >> A[i];
    long long k = 1;
    long long ans = 0;
    for (k = 1; k < (1 << 30); k *= 2) {
      long long cnt = 0;
      for (i = 0; i < N; i++) {
        if (k & A[i]) cnt++;
      }
      ans = gcd(ans, cnt);
    }
    if (!ans) {
      for (i = 1; i <= N; i++) cout << i << ' ';
      cout << '\n';
      continue;
    }
    for (i = 1; i * i <= ans; i++) {
      if (ans % i == 0) {
        cout << i << ' ';
      }
    }
    i--;
    if (i * i == ans) i--;
    for (; i >= 1; i--) {
      if (ans % i == 0) {
        cout << ans / i << ' ';
      }
    }
    cout << '\n';
  }
}
