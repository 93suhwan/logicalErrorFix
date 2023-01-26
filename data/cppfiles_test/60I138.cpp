#include <bits/stdc++.h>
using namespace std;
void solve() {
  long long n, s = 0, s1, ans = 0;
  cin >> n;
  long long a[n];
  for (long long i = 0; i < n; ++i) {
    cin >> a[i];
    s += a[i];
  }
  s1 = s - (s / n) * (n - 2);
  for (long long i = 0; i < n; ++i) {
    for (long long j = i + 1; j < n; ++j) {
      if (a[i] + a[j] == s1) ans++;
    }
  }
  cout << ans;
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
