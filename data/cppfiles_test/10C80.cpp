#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, k;
    cin >> n >> k;
    vector<int> v(n);
    for (int i = 0; i < n; i++) cin >> v[i];
    vector<int> f(n, 0);
    unordered_map<int, vector<int>> mp;
    for (int i = 0; i < n; i++) mp[v[i]].push_back(i);
    auto it = mp.begin();
    int fg = 0;
    bool flg = 0;
    int ts = 0;
    for (it; it != mp.end(); it++) {
      auto vv = it->second;
      if (vv.size() < k) continue;
      ts += vv.size();
      if (vv.size() >= k) {
        int tt = 0;
        while (tt < k) {
          f[vv[tt]] = tt + 1;
          tt++;
        }
      }
    }
    it = mp.begin();
    for (it; it != mp.end(); it++) {
      auto vv = it->second;
      if (vv.size() >= k)
        continue;
      else {
        int ii = 0;
        while (ii < vv.size()) {
          if (fg == 0 && (n - ts < k)) {
            flg = 1;
            break;
          }
          ts++;
          f[vv[ii]] = fg + 1;
          fg = (fg + 1) % k;
          ii++;
        }
        if (flg) break;
      }
    }
    for (int i = 0; i < n; i++) cout << f[i] << " ";
    cout << endl;
  }
  return 0;
}
