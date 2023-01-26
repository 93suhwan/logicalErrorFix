#include <bits/stdc++.h>
using namespace std;
const long long INF = (long long)1e9 + 1;
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long T = 1;
  cin >> T;
  while (T--) {
    long long w, h;
    cin >> w >> h;
    vector<long long> a, b, c, d;
    for (long long cnt = 4; cnt >= 1; cnt--) {
      long long k;
      cin >> k;
      for (long long i = 0; i < k; i++) {
        long long val;
        cin >> val;
        if (cnt == 4) {
          a.push_back(val);
        }
        if (cnt == 3) {
          b.push_back(val);
        }
        if (cnt == 2) {
          c.push_back(val);
        }
        if (cnt == 1) {
          d.push_back(val);
        }
      }
    }
    long long ans = 0;
    set<long long> s;
    s.insert((a.back() - a[0]) * (h));
    s.insert((b.back() - b[0]) * (h));
    s.insert((c.back() - c[0]) * (w));
    s.insert((d.back() - d[0]) * (w));
    ans = *s.rbegin();
    cout << ans << "\n";
  }
  return 0;
}
