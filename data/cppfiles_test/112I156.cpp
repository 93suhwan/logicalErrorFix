#include <bits/stdc++.h>
using namespace std;
const long long inf = INT_MAX;
void solve() {
  long long a, b, c, m;
  cin >> a >> b >> c >> m;
  vector<long long> v = {a, b, c};
  sort(v.begin(), v.end());
  vector<pair<long long, long long>> vp;
  for (long long i = 0; i < 3; i++) {
    if ((v[i] % 2) == 1) {
      vp.push_back({v[i] / 2, 1});
    } else {
      vp.push_back({v[i] / 2, 0});
    }
  }
  long long ex_a = vp[0].second, ex_b = vp[1].second, ex_c = vp[2].second;
  long long paris = 0;
  for (long long i = 0; i < 3; i++) {
    if (vp[i].first == 0) {
      continue;
    } else {
      while (m != 0 and i <= 2) {
        long long temp = vp[i].first;
        vp[i].first = vp[i].first - min((vp[i].first), m);
        m = m - min(temp, m);
        i++;
      }
      ex_a += vp[0].first * 2;
      ex_b += vp[1].first * 2;
      ex_c += vp[2].first * 2;
      vector<long long> v1 = {ex_a, ex_b, ex_c};
      bool ok = false;
      sort(v1.begin(), v1.end());
      for (long long i = 0; i < 2; i++) {
        if (v[i + 1] - v[i] > 1) {
          ok = true;
          break;
        }
      }
      if (ok or m != 0) {
        cout << "NO" << endl;
      } else {
        cout << "YES " << endl;
      }
      return;
    }
  }
  if (m != 0)
    cout << "NO" << endl;
  else {
    cout << "YES" << endl;
  }
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long t;
  cin >> t;
  while (t--) solve();
  return 0;
}
