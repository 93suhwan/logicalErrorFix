#include <bits/stdc++.h>
using namespace std;
long long int m = 998244353;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long int t, n, f, c, n1 = 200000, d, s, ans;
  long long int b[n1 + 1];
  b[0] = 1;
  for (int i = 1; i <= n1; i++) {
    b[i] = (i * b[i - 1]) % m;
  }
  cin >> t;
  while (t--) {
    c = 0, f = 0;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }
    sort(a, a + n, greater<long long int>());
    for (int i = 0; i < n; i++) {
      if (a[i] == a[0]) {
        c++;
      } else if (a[i] == (a[0] - 1))
        f++;
    }
    if (f == 0 && count(a, a + n, a[0]) != n) {
      cout << "0\n";
    } else if (n == c) {
      cout << (b[n] % m) << "\n";
    } else {
      s = 0;
      d = b[n] % m;
      for (int i = 0; i <= (n - c - f); i++) {
        long long int x = b[n - c - f] % m;
        long long int x1 = b[f + (n - c - f - i)] % m;
        long long int y = b[n - c - f - i] % m;
        long long int y1 = b[c] % m;
        s = (s + (((y1 * x * x1) % m) / ((y) % m))) % m;
      }
      ans = (d - s) % m;
      cout << ans << "\n";
    }
  }
  return 0;
}
