#include <bits/stdc++.h>
using namespace std;
void solve() {
  long long int n;
  cin >> n;
  set<long long int> s;
  for (long long int i = 1; i * i <= n; i++) {
    if (i * i * i <= n) {
      s.insert(i * i * i);
    }
    s.insert(i * i);
  }
  cout << s.size() << "\n";
}
int32_t main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long int t;
  cin >> t;
  while (t--) solve();
  return 0;
}
