#include <bits/stdc++.h>
using namespace std;
void solve() {
  long long n;
  cin >> n;
  vector<pair<int, int>> vp(n);
  for (long long i = 0; i < n; i++) {
    long long k;
    cin >> k;
    long long a = 0;
    for (long long j = 0; j < k; j++) {
      int h;
      cin >> h;
      a = max(a, h + 1 - j);
    }
    vp[i] = {a, k};
  }
  sort(begin(vp), end(vp));
  long long ans = 0;
  long long h = 0;
  for (auto i : vp) {
    ans = max(ans, i.first - h);
    h += i.second;
  }
  cout << ans << endl;
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  long long t = 1;
  cin >> t;
  while (t--) solve();
  return 0;
}
