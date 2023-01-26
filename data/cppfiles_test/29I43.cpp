#include <bits/stdc++.h>
using namespace std;
int main() {
  long long t;
  cin >> t;
  while (t--) {
    long long n;
    cin >> n;
    long long ans = 0;
    long long a[n], sum = 0, cnt = 0, c = 0;
    for (long long i = 0; i < n; i++) {
      cin >> a[i];
      sum += a[i];
      if (a[i] == 0) cnt++;
    }
    long long k = cnt;
    long long x = sum - 1;
    sort(a, a + n);
    for (long long i = k; i < n; i++) {
      long long temp = sum;
      if (temp - a[i] == x) c++;
    }
    if (cnt > 0) {
      long long f = 1;
      for (long long i = 1; i <= cnt; i++) {
        f = f * i;
      }
      ans += c * f;
      if (cnt >= 2) ans++;
    }
    ans += c;
    cout << ans << "\n";
  }
}
