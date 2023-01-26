#include <bits/stdc++.h>
using namespace std;
void solve() {
  int Y, X;
  cin >> X >> Y;
  long long ans = 0;
  for (int i = 0; i < 4; i++) {
    int k;
    cin >> k;
    vector<int> v(k);
    for (int j = 0; j < k; j++) {
      cin >> v[j];
    }
    sort((v).begin(), (v).end());
    long long cur = v.back() - v.front();
    if (i < 2) {
      ans = max(ans, cur * Y);
    } else {
      ans = max(ans, cur * X);
    }
  }
  cout << ans << '\n';
}
int main() {
  ios::sync_with_stdio(false);
  int t;
  cin >> t;
  while (t--) solve();
  return 0;
}
