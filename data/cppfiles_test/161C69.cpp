#include <bits/stdc++.h>
using namespace std;
bool sortbysec(const pair<long long, long long> &a,
               const pair<long long, long long> &b) {
  if (a.second - a.first < b.second - b.first) return true;
  return false;
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long t;
  cin >> t;
  while (t--) {
    long long n, i, j, ans;
    cin >> n;
    map<long long, long long> mp1, mp2;
    vector<vector<long long>> vv;
    vector<pair<long long, long long>> vp;
    set<long long> s;
    for (i = 1; i <= n; i++) {
      s.insert(i);
    }
    for (i = 0; i < n; i++) {
      long long l, r;
      cin >> l >> r;
      if (l != r) {
        vp.push_back({l, r});
      } else {
        vv.push_back({l, r, l});
        s.erase(l);
      }
    }
    sort(vp.begin(), vp.end(), sortbysec);
    for (i = 0; i < vp.size(); i++) {
      auto it = s.lower_bound(vp[i].first);
      vv.push_back({vp[i].first, vp[i].second, *it});
      s.erase(it);
    }
    for (i = 0; i < vv.size(); i++) {
      for (j = 0; j < 3; j++) {
        cout << vv[i][j] << " ";
      }
      cout << "\n";
    }
  }
}
