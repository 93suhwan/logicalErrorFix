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
    for (long long i = 0; i < k; i++) {
      cin >> v[i];
      if (p.first < v[i]) {
        p = {v[i], i};
      }
    }
    long long temp = p.first - (p.second - 1);
    p.first = temp;
    p.second = temp + k;
    vp[i] = p;
  }
  sort(begin(vp), end(vp));
  long long ans = 0;
  for (long long i = 0; i < n; i++) {
    ans = vp[i].first;
    long long k = vp[i].second;
    bool f = true;
    for (long long j = 0; j < n; j++) {
      if (k < vp[j].first) {
        f = false;
        break;
      }
    }
    if (f) {
      break;
    }
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
