#include <bits/stdc++.h>
using namespace std;
void solve() {
  long long n, m, k;
  cin >> n >> m >> k;
  long long l = n / m;
  long long e = (n % m);
  long long lst = 0;
  while (k--) {
    long long cnt = lst;
    for (long long i = 1; i <= e; i++) {
      cout << l + 1 << " ";
      for (long long j = 1; j <= l + 1; j++) {
        cnt = (cnt % n) + 1;
        cout << cnt << " ";
      }
      cout << "\n";
    }
    lst = cnt;
    for (long long i = e + 1; i <= m; i++) {
      cout << l << " ";
      for (long long j = 1; j <= l; j++) {
        cnt = (cnt % n) + 1;
        cout << cnt << " ";
      }
      cout << "\n";
    }
    cout << "\n";
  }
  cout << "\n";
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long t;
  cin >> t;
  while (t--) solve();
  return 0;
}
