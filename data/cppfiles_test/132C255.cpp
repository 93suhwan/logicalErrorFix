#include <bits/stdc++.h>
using namespace std;
void solve() {
  vector<long long> v(7);
  multiset<long long> s;
  for (long long i = 0; i < 7; i++) {
    cin >> v[i];
    s.insert(v[i]);
  }
  for (long long i = 0; i < 7; i++) {
    for (long long j = i + 1; j < 7; j++) {
      for (long long h = j + 1; h < 7; h++) {
        multiset<long long> r = s;
        vector<bool> ok(7);
        if (r.count(v[i]) >= 1) {
          r.erase(r.find(v[i]));
          ok[0] = true;
        }
        if (r.count(v[j]) >= 1) {
          r.erase(r.find(v[j]));
          ok[1] = true;
        }
        if (r.count(v[h]) >= 1) {
          r.erase(r.find(v[h]));
          ok[2] = true;
        }
        if (r.count(v[h] + v[i] + v[j]) >= 1) {
          r.erase(r.find(v[h] + v[i] + v[j]));
          ok[3] = true;
        }
        if (r.count(v[i] + v[j]) >= 1) {
          r.erase(r.find(v[j] + v[i]));
          ok[4] = true;
        }
        if (r.count(v[i] + v[h]) >= 1) {
          r.erase(r.find(v[i] + v[h]));
          ok[5] = true;
        }
        if (r.count(v[j] + v[h]) >= 1) {
          r.erase(r.find(v[j] + v[h]));
          ok[6] = true;
        }
        sort(ok.begin(), ok.end());
        if (ok[6] && r.empty()) {
          cout << v[i] << ' ' << v[j] << ' ' << v[h] << endl;
          return;
        }
      }
    }
  }
}
signed main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  long long t;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
