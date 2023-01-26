#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 7;
const int MOD = 1e9 + 7;
const long long INF = (long long)1e18 + 7;
long long a[N];
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    long long n, h;
    cin >> n >> h;
    for (int i = 1; i <= n; i++) cin >> a[i];
    a[n + 1] = a[n] + h;
    long long l = 1, r = h, ans = h;
    while (r >= l) {
      long long m = (l + r) >> 1;
      long long hp = 0;
      for (int i = 1; i <= n; i++) hp += min(m, a[i + 1] - a[i]);
      if (hp >= h) {
        ans = m;
        r = m - 1;
      } else
        l = m + 1;
    }
    cout << ans << "\n";
  }
}
