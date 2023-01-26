#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
using namespace std;
void _debug() { cerr << '\n'; }
template <typename A, typename... B>
void _debbug(A a, B... b) {
  cerr << a << ' ', _debug(b...);
}
const int oo = 2000000000;
void solve() {
  int n;
  cin >> n;
  vector<string> s(n);
  for (int i = 0; i < n; i++) cin >> s[i];
  int ans = 0;
  for (int i = 0; i < 5; i++) {
    vector<int> f(n);
    for (int j = 0; j < n; j++) {
      for (auto x : s[j]) {
        if (x == 'a' + i) {
          f[i]++;
        } else {
          f[i]--;
        }
      }
    }
    sort((f).begin(), (f).end());
    int sum = 0;
    for (int i = 0; i < n; i++) {
      sum += f[i];
      if (sum <= 0) break;
      ans = max(ans, i + 1);
    }
  }
  cout << ans << '\n';
}
int main() {
  ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  int t;
  cin >> t;
  while (t--) solve();
}
