#include <bits/stdc++.h>
using namespace std;
void __dbg() { cout << endl; }
template <typename Arg, typename... Args>
void __dbg(Arg A, Args... B) {
  cout << " " << A;
  __dbg(B...);
}
const int inf = INT_MAX;
const int ninf = INT_MIN;
const int mod = 1e9 + 7;
const int maxN = 1e6 + 2;
class DSU {
  vector<int> parent, sz;

 public:
  DSU(int n) : parent(n), sz(n, 1) { iota(parent.begin(), parent.end(), 0); }
  int find(int i) { return parent[i] == i ? i : parent[i] = find(parent[i]); }
  bool merge(int i, int j) {
    int x = find(i), y = find(j);
    if (x == y) return 0;
    parent[x] = y;
    sz[y] += sz[x];
    return 1;
  }
};
int main() {
  int n, m, q;
  scanf("%d", &n);
  scanf("%d", &m);
  scanf("%d", &q);
  vector<int> a(n), b(m);
  vector<pair<int, int>> allitems(n + m), gaps(n + m - 1), queries(q);
  for (int i = 0; i < n; ++i) {
    scanf("%d", &a[i]);
    allitems[i] = {a[i], 1};
  }
  for (int i = 0; i < m; ++i) {
    scanf("%d", &b[i]);
    allitems[i + n] = {b[i], 0};
  }
  sort(allitems.begin(), allitems.end());
  vector<long long> pref(n + m + 1), group_size(n + m), group_sum(n + m);
  long long curr_ans = 0;
  for (int i = 0; i < n + m; ++i) {
    pref[i + 1] = pref[i] + allitems[i].first;
    if (allitems[i].second) {
      group_size[i] = 1;
      group_sum[i] = allitems[i].first;
      curr_ans += allitems[i].first;
    }
  }
  for (int i = 0; i < n + m - 1; ++i) {
    gaps[i] = {allitems[i + 1].first - allitems[i].first, i};
  }
  sort(gaps.begin(), gaps.end());
  for (int i = 0; i < q; ++i) {
    scanf("%d", &queries[i].first);
    queries[i].second = i;
  }
  sort(queries.begin(), queries.end());
  DSU d(n + m);
  int nxt = 0;
  vector<long long> ans(q);
  for (auto &[k, i] : queries) {
    while (nxt < n + m - 1 && gaps[nxt].first <= k) {
      int i = gaps[nxt].second;
      int j = d.find(i + 1);
      curr_ans -= (group_sum[i] + group_sum[j]);
      int sz = group_size[i] + group_size[j];
      d.merge(i, j);
      group_size[j] = sz;
      group_sum[j] = pref[j + 1] - pref[j + 1 - sz];
      curr_ans += group_sum[j];
      ++nxt;
    }
    ans[i] = curr_ans;
  }
  for (int i = 0; i < q; ++i) {
    printf("%lld\n", ans[i]);
  }
  return 0;
}
