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
    vector<pair<long long, long long> > ans(n);
    for (auto& i : mp) {
      auto& u = i.second;
      sort(u.begin(), u.end(), [&](int x, int y) { return vs[x].a < vs[y].a; });
      if (u.size() == 1) {
        ans[u[0]].first = min(vs[u[0]].a, vs[u[0]].m);
        ans[u[0]].second = max(0ll, vs[u[0]].m - ans[u[0]].first);
        continue;
      }
      int start = u[0];
      for (auto j : u) {
        ans[j].first = min(vs[j].m, vs[j].a - vs[start].a);
        ans[j].second = vs[j].m - ans[j].first;
      }
    }
    cout << mp.size() << '\n';
    for (auto i : ans) {
      cout << i.first << ' ' << i.second << '\n';
    }
  }
  return 0;
}
