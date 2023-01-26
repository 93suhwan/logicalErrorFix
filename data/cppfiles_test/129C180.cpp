#include <bits/stdc++.h>
using namespace std;
void solve() {
  long long n;
  cin >> n;
  vector<long long> a(n);
  for (int i = 0; i < n; i++) cin >> a[i];
  sort(a.begin(), a.end());
  long long ans = 0;
  set<long long> s;
  for (int i = 0; i < n; i++) {
    if (a[i] > 0 && a[i] < n + 1) {
      s.insert(a[i]);
    }
  }
  auto it = s.begin();
  for (int i = 0; i < n; i++) {
    if (a[i] == *it) {
      a[i] = -1;
      it++;
    }
  }
  set<long long> left;
  for (int i = 1; i <= n; i++) {
    left.insert(i);
  }
  for (auto i : s) {
    left.erase(i);
  }
  it = left.begin();
  sort(a.begin(), a.end());
  for (int i = 0; i < n; i++) {
    if (a[i] != -1) {
      long long x = a[i] - *it;
      if (x > 0 && a[i] % x == *it) {
        ans++;
        it++;
      } else {
        cout << -1 << endl;
        return;
      }
    }
  }
  cout << ans << endl;
}
signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ;
  int t = 1;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
