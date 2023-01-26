#include <bits/stdc++.h>
using namespace std;
long long get(const vector<int>& pcnt, const vector<long long>& psum,
              pair<int, int> seg) {
  int L = seg.first;
  int R = seg.second;
  int cnt = pcnt[R] - pcnt[L];
  return psum[R] - psum[R - cnt];
}
int main() {
  int n, m, q;
  scanf("%d %d %d", &n, &m, &q);
  vector<int> a(n), b(m);
  for (int i = 0; i < n; i++) {
    scanf("%d", &a[i]);
  }
  for (int i = 0; i < m; i++) {
    scanf("%d", &b[i]);
  }
  vector<int> pcnt = {0};
  vector<long long> psum = {0ll};
  vector<pair<int, int>> order;
  for (int i = 0; i < n; i++) order.push_back(make_pair(a[i], 1));
  for (int i = 0; i < m; i++) order.push_back(make_pair(b[i], 0));
  sort(order.begin(), order.end());
  int z = n + m;
  for (int i = 0; i < z; i++) {
    pcnt.push_back(pcnt.back() + order[i].second);
    psum.push_back(psum.back() + order[i].first);
  }
  long long cur = 0;
  for (int i = 0; i < n; i++) cur += a[i];
  set<pair<int, int>> segs;
  for (int i = 0; i < z; i++) segs.insert(make_pair(i, i + 1));
  map<int, vector<int>> events;
  for (int i = 0; i < z - 1; i++)
    events[order[i + 1].first - order[i].first].push_back(i);
  vector<pair<int, long long>> ans = {{0, cur}};
  for (auto x : events) {
    int cost = x.first;
    vector<int> changes = x.second;
    for (auto i : changes) {
      auto itr = segs.upper_bound(make_pair(i, int(1e9)));
      auto itl = prev(itr);
      pair<int, int> pl = *itl;
      pair<int, int> pr = *itr;
      cur -= get(pcnt, psum, pl);
      cur -= get(pcnt, psum, pr);
      pair<int, int> p = make_pair(pl.first, pr.second);
      cur += get(pcnt, psum, p);
      segs.erase(pl);
      segs.erase(pr);
      segs.insert(p);
    }
    ans.push_back(make_pair(cost, cur));
  }
  for (int i = 0; i < q; i++) {
    int k;
    scanf("%d", &k);
    int pos = upper_bound(ans.begin(), ans.end(), make_pair(k + 1, -1ll)) -
              ans.begin() - 1;
    printf("%lld\n", ans[pos].second);
  }
}
