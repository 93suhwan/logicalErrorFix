#include <bits/stdc++.h>
using namespace std;
long long gcd(long long a, long long b) { return b ? gcd(b, a % b) : a; };
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<long long> a(n);
    for (auto &ai : a) cin >> ai;
    int ans = 1;
    int logn = 0;
    for (; (1 << logn) < n - 1; logn++)
      ;
    vector<vector<long long>> f(n, vector<long long>(logn + 1));
    for (int j = 1; j < n; j++) {
      f[j][0] = abs(a[j] - a[j - 1]);
    }
    for (int i = 1; i <= logn; i++) {
      for (int j = 1; j < n; j++) {
        int d = 1 << (i - 1), _j = j - d;
        if (f[j][i - 1] == 1) {
          f[j][i] = 1;
          continue;
        } else if (_j < 1) {
          f[j][i] = f[j][i - 1];
        } else {
          f[j][i] = gcd(f[j][i - 1], f[_j][i - 1]);
          if (f[j][i] > 1) {
            ans = max(ans, j - (1 << i) >= 0 ? 1 << i : j);
          } else {
            int l = max(_j - d + 1, 0), r = _j + 1, mid;
            while (l + 1 < r) {
              mid = ceil((l + r) / 2.);
              long long g = gcd(f[j][i - 1], f[mid + d - 1][i - 1]);
              if (g > 1) {
                r = mid;
              } else {
                l = mid;
              }
            }
            ans = max(ans, j - r + 1);
          }
        }
      }
    }
    cout << ans + (n > 1 ? 1 : 0) << endl;
  }
  return 0;
}
