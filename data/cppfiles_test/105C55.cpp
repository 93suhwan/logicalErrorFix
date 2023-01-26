#include <bits/stdc++.h>
using namespace std;
using ll = long long;
struct seg {
  int l, r, id;
};
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<int> a(n), b(n), m(n), aa(n), bb(n);
    map<int, vector<seg>> mv;
    for (int i = 0; i < (int)n; i++) {
      cin >> a[i] >> b[i] >> m[i];
      aa[i] += max(m[i] - b[i], 0);
      bb[i] += max(m[i] - a[i], 0);
      a[i] -= aa[i];
      b[i] -= bb[i];
      m[i] -= aa[i] + bb[i];
      mv[a[i] + b[i] - m[i]].push_back(seg{a[i] - m[i], a[i], i});
    }
    int ans = 0;
    for (auto x : mv) {
      sort(x.second.begin(), x.second.end(),
           [&](seg u, seg v) { return u.r < v.r; });
      int cur = -1, last = -1;
      for (auto s : x.second) {
        if (s.l > cur) {
          ans++;
          cur = s.r;
          last = s.id;
          bb[s.id] += m[s.id];
        } else {
          aa[s.id] += s.r - cur;
          bb[s.id] += m[s.id] - s.r + cur;
        }
      }
    }
    cout << ans << endl;
    for (int i = 0; i < (int)n; i++) cout << aa[i] << " " << bb[i] << endl;
  }
  return 0;
}
