#include <bits/stdc++.h>
using namespace std;
void solve() {
  long long n;
  cin >> n;
  vector<pair<int, int>> vp(n);
  for (long long i = 0; i < n; i++) {
    long long k;
    cin >> k;
    vector<int> v(k);
    pair<int, int> p;
    p.first = INT_MIN;
    for (long long j = 0; j < k; j++) {
      cin >> v[j];
      if (p.first < v[j]) {
        p = {v[j], j};
      }
    }
    long long temp = p.first - (p.second - 1);
    p.first = temp;
    p.second = k;
    vp[i] = p;
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
