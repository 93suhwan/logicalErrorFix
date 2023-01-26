#include <bits/stdc++.h>
using namespace std;
struct st {
  long long a, b, m;
};
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    map<long long, vector<long long> > mp;
    vector<st> vs(n);
    for (int i = 0; i < n; i++) {
      cin >> vs[i].a >> vs[i].b >> vs[i].m;
      mp[vs[i].a + vs[i].b - vs[i].m].push_back(i);
    }
    vector<long long> ans(n);
    int res = 0;
    for (auto i : mp) {
      auto u = i.second;
      sort(u.begin(), u.end(), [&](int x, int y) {
        return vs[x].a - max(0ll, vs[x].m - vs[x].b) <
               vs[y].a - max(0ll, vs[y].m - vs[y].b);
      });
      long long cur = -0x3f3f3f3f3f3f3f3f;
      for (auto j : u) {
        if (vs[j].a - cur > vs[j].m) {
          res += 1;
          ans[j] = max(0ll, vs[j].m - vs[j].b);
          cur = vs[j].a - ans[j];
        } else {
          ans[j] = vs[j].a - cur;
        }
      }
    }
    cout << res << '\n';
    for (int i = 0; i < ans.size(); i++) {
      cout << ans[i] << ' ' << vs[i].m - ans[i] << '\n';
    }
  }
  return 0;
}
