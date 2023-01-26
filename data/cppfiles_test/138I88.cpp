#include <bits/stdc++.h>
using namespace std;
int a[200000], b[200000], pc[400001];
long long ps[400001];
pair<int, int> mp[400000], ans[200000];
inline long long cal(int l, int r) { return ps[r] - ps[r - pc[r] + pc[l]]; }
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);
  int n, m, q;
  cin >> n >> m >> q;
  for (int i = 0; i != n; ++i) cin >> a[i];
  for (int i = 0; i != m; ++i) cin >> b[i];
  int sz = n + m;
  for (int i = 0; i != n; ++i) mp[i].first = a[i], mp[i].second = 1;
  for (int i = 0; i != m; ++i) mp[i + n].first = b[i], mp[i + n].second = 0;
  sort(mp, mp + sz);
  for (int i = 0; i != sz; ++i) {
    pc[i + 1] = pc[i] + mp[i].second;
    ps[i + 1] = ps[i] + mp[i].first;
  }
  map<int, vector<int>> eve;
  for (int i = 0; i != sz - 1; ++i)
    eve[mp[i + 1].first - mp[i].first].push_back(i);
  long long cur = 0;
  for (int i = 0; i != n; ++i) cur += a[i];
  set<pair<int, int>> s;
  for (int i = 0; i != sz; ++i) s.emplace(i, i + 1);
  int idx = 0;
  for (const auto& i : eve) {
    for (const auto& j : i.second) {
      auto f = s.upper_bound({j, 0});
      pair<int, int> l = *f, r = *(--f);
      cur -= cal(l.first, l.second) + cal(r.first, r.second) -
             cal(l.first, r.second);
      s.erase(l), s.erase(r);
      s.emplace(l.first, r.second);
    }
    ans[idx].first = i.first, ans[idx].second = cur;
    ++idx;
  }
  for (int i = 0; i != q; ++i) {
    int k;
    cin >> k;
    cout << upper_bound(ans, ans + idx, make_pair(k + 1, -1))->second << '\n';
  }
}
