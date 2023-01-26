#include <bits/stdc++.h>
using namespace std;
long long power(long long b, long long exp) {
  if (exp == 0) return 1;
  long long temp = power(b, exp / 2);
  temp = (temp * temp) % 1000000009;
  if (exp & 1) temp = (temp * b) % 1000000009;
  return temp % 1000000009;
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, k;
    cin >> n >> k;
    k++;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i], a[i] = (int)power(10, a[i]);
    long long res = 0;
    for (int i = 0; i < n; i++) {
      int cnt = k;
      if (i + 1 < n) cnt = min(cnt, a[i + 1] / a[i] - 1);
      res += a[i] * 1LL * cnt;
      k -= cnt;
    }
    cout << res << '\n';
  }
}
