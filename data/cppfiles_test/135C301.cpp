#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    int n, k;
    cin >> n >> k;
    vector<int> v(n);
    for (auto &it : v) cin >> it;
    sort(v.begin(), v.end());
    int ans = 0;
    for (int i = 0; i < n - k - k; i++) {
      ans += v[i];
    }
    map<int, int> mp;
    for (int i = n - k - k; i < n; i++) {
      mp[v[i]]++;
    }
    multiset<int> s;
    for (auto it : mp) {
      s.insert(it.second);
    }
    while ((int)s.size() > 1) {
      auto it = s.begin();
      auto iit = s.end();
      iit--;
      s.erase(it);
      s.erase(iit);
      int a = *it;
      int b = *iit;
      a--, b--;
      if (a) s.insert(a);
      if (b) s.insert(b);
    }
    for (auto it : s) ans += it / 2;
    cout << ans << '\n';
  }
  return 0;
}
