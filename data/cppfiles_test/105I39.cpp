#include <bits/stdc++.h>
using namespace std;
mt19937 rnd(51);
signed main() {
  long long t;
  cin >> t;
  while (t--) {
    long long n, bal = 0, ans = 0;
    cin >> n;
    vector<long long> a(n), b(n), m(n), cola(n), colb(n);
    map<long long, vector<long long>> all;
    for (long long i = 0; i < n; i++) {
      cin >> a[i] >> b[i] >> m[i];
      all[a[i] + b[i] - m[i]].emplace_back(i);
    }
    for (auto to : all) {
      sort(to.second.begin(), to.second.end(), [&](long long i, long long j) {
        return a[i] - max(0ll, m[i] - b[i]) < a[j] - max(0ll, m[j] - b[j]);
      });
      long long last = 1e18;
      for (auto t : to.second) {
        if (a[t] - last + b[t] < m[t]) {
          last = a[t] - max(0ll, m[t] - b[t]);
          ans++;
        }
        cola[t] = a[t] - last, colb[t] = m[t] - cola[t];
      }
    }
    cout << ans << endl;
    for (long long i = 0; i < n; i++) {
      cout << cola[i] << ' ' << colb[i] << endl;
    }
  }
  return 0;
}
