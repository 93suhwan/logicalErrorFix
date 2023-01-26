#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
long long b[N];
long long ans[N];
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i) cin >> b[i];
    long long sum = 0;
    for (int i = 1; i <= n; ++i) sum += b[i];
    long long x = (long long)n * (n + 1) / 2;
    if (sum % x != 0) {
      cout << "NO" << '\n';
    } else {
      sum /= x;
      for (int i = 1; i <= n; ++i) {
        int p = (i + n - 2) % n + 1;
        ans[i] = (sum - b[i] + b[p]) / n;
      }
      bool cek = true;
      for (int i = 1; i <= n; ++i) {
        if (ans[i] <= 0 || ans[i] > 1e9) cek = false;
      }
      if (cek) {
        cout << "YES" << '\n';
        for (int i = 1; i <= n; ++i) {
          cout << ans[i];
          if (i < n) cout << ' ';
        }
        cout << '\n';
      } else {
        cout << "NO" << '\n';
      }
    }
  }
  return 0;
}
