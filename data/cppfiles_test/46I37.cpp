#include <bits/stdc++.h>
using namespace std;
const long long int INF{(false ? (INT_MAX - 1) / 2 : (long long int)1e18 + 5)};
long long int MOD = 1e9 + 7;
void solve() {
  long long int n;
  cin >> n;
  vector<long long int> a(n);
  for (long long int i = 0; i < n; i++) cin >> a[i];
  long long int ans = 0;
  for (long long int i = 0; i < n; i++) {
    long long int l = 0, r = 0;
    if (i % 2)
      r += a[i];
    else
      l += a[i];
    if (l > r) {
      long long int p = 0, q = 0;
      for (long long int j = i + 1; j < n; j++) {
        if (j % 2) {
          if (j != i + 1) {
            q = a[j];
            long long int k = min(p, q);
            if (k == a[j - 1] && k == p) {
              ans += 1;
            }
            p -= k;
            q -= k;
            if (q > 0) {
              long long int m = min(l, q);
              ans += m;
              l -= m;
              q -= m;
              if (q > 0) break;
            } else {
              if (q == 0 && p == 0 && k != a[j - 1] && k != p) ans += 1;
            }
          } else {
            q = a[j];
            long long int r = min(l, q);
            ans += r;
            l -= r;
            q -= r;
            if (q > 0) break;
          }
        } else {
          p += a[j];
        }
      }
    }
  }
  cout << ans;
}
int main() {
  cout << setprecision(15);
  long long int t(1);
  while (t--) {
    solve();
    cout << endl;
  }
  return 0;
}
