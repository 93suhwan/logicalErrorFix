#include <bits/stdc++.h>
using namespace std;
long long int fac[200005];
signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  fac[0] = 1;
  for (long long int i = 1; i < 200005; i++)
    fac[i] = (fac[i - 1] * i) % 998244353;
  long long int t;
  cin >> t;
  while (t--) {
    long long int n;
    cin >> n;
    long long int a[n], b[n];
    for (long long int i = 0; i < n; i++) {
      cin >> a[i];
      b[i] = a[i];
    }
    sort(b, b + n);
    long long int flag = 1;
    if (b[n - 1] - b[n - 2] > 1) flag = 0;
    if (flag == 0)
      cout << 0;
    else {
      if (b[n - 1] - b[n - 2] == 0)
        cout << fac[n];
      else {
        long long int count = 0;
        for (long long int i = n - 2; i >= 0; i--) {
          if (b[i] != b[n - 2]) break;
          count++;
        }
        long long int ans = 0;
        ans = (count * fac[n - 1]) % 998244353;
        long long int x = n - 2, y = count, z = count;
        for (long long int i = count + 1; i < n; i++) {
          count--;
          ans = (ans + (count * (y * fac[x]) % 998244353) % 998244353) %
                998244353;
          x--;
          z--;
          y = (y * z) % 998244353;
        }
        cout << ans;
      }
    }
    cout << "\n";
  }
  cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
}
