#include <bits/stdc++.h>
using namespace std;
void solve() {
  long long n;
  long double s = 0, s1, ans = 0;
  cin >> n;
  long long a[n];
  map<long long, long long> m;
  for (long long i = 0; i < n; ++i) {
    cin >> a[i];
    s += a[i];
    m[a[i]]++;
  }
  s1 = (2 * s) / n;
  if (s1 - floor(s1) != 0) {
    cout << 0;
    return;
  }
  for (long long i = 0; i < n; ++i) {
    if (m[s1 - a[i]] != 0) {
      if (s1 - a[i] != a[i])
        ans += m[s1 - a[i]];
      else {
        if (m[s1 - a[i]] > 1) ans += m[s1 - a[i]] - 1;
      }
    }
  }
  cout << ans / 2;
}
signed main() {
  ios::sync_with_stdio(NULL), cin.tie(NULL), cout.tie(NULL);
  auto start = chrono::high_resolution_clock::now();
  long long t = 1;
  cin >> t;
  for (long long i = 1; i < t + 1; ++i) {
    solve();
    cout << "\n";
  }
  auto stop = chrono::high_resolution_clock::now();
  auto duration = chrono::duration_cast<chrono::microseconds>(stop - start);
  return 0;
}
