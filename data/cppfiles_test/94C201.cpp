#include <bits/stdc++.h>
using namespace std;
long long fastpow(long long base, long long exp) {
  long long ans = 1;
  while (exp > 0) {
    if (exp & 1) ans = (ans * base);
    base = (base * base);
    exp /= 2;
  }
  return ans;
}
int main() {
  int t, i;
  cin >> t;
  while (t--) {
    long long n, k;
    cin >> n >> k;
    vector<long long> v(n);
    for (i = 0; i < n; i++) cin >> v[i];
    long long j;
    vector<long long> a(n);
    for (i = 0; i < n; i++) {
      a[i] = fastpow(10, v[i]);
    }
    k++;
    long long z, ans = 0;
    for (i = 0; i < n - 1; i++) {
      z = min(k, a[i + 1] / a[i] - 1);
      ans += z * a[i];
      k -= z;
      if (k < 0) {
        break;
      }
    }
    if (k > 0) {
      ans += a[n - 1] * k;
    }
    cout << ans << endl;
  }
}
