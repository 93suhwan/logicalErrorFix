#include <bits/stdc++.h>
using namespace std;
void DBG() { cerr << "]\n"; }
template <typename T, typename... Args>
void DBG(T first, Args... args) {
  cerr << first;
  if (sizeof...(args)) cerr << ", ";
  DBG(args...);
}
void solve() {
  long long n;
  cin >> n;
  vector<long long> a(n);
  for (long long i = 0; i < n; i++) {
    cin >> a[i];
  }
  long long ans = 1;
  for (long long i = 0; i < n; i++) {
    if (i - 1 >= 0 && a[i] == 0 && a[i - 1] == 0) {
      cout << -1 << "\n";
      return;
    } else if (i - 1 >= 0 && a[i] == 1 && a[i - 1] == 1) {
      ans += 5;
    } else if (a[i] == 1) {
      ans++;
    }
  }
  cout << ans << "\n";
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  long long t = 1;
  cin >> t;
  for (long long tt = 1; tt <= t; tt++) {
    solve();
  }
}
