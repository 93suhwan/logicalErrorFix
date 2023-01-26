#include <bits/stdc++.h>
using namespace std;
const double PI = acos(-1);
#pragma GCC optimize("Ofast")
#pragma GCC optimize("O2")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx")
const int MAXN = 2e5;
const int MOD = (int)1e9 + 7;
void clear() {}
void precalc() {}
struct SegmentTree {
  int values[4 * MAXN];
  void Add(int l, int r, int s, int value, int i) {
    values[i] = max(values[i], value);
    if (l == r) return;
    int med = (l + r) >> 1;
    if (s <= med)
      Add(l, med, s, value, i * 2 + 1);
    else
      Add(med + 1, r, s, value, i * 2 + 2);
  }
  int Get(int l, int r, int l1, int r1, int i) {
    if (l == l1 && r == r1) return values[i];
    int med = (l + r) >> 1;
    int rst = 0;
    if (l1 <= med) rst = max(rst, Get(l, med, l1, min(r1, med), i * 2 + 1));
    if (r1 > med)
      rst = max(rst, Get(med + 1, r, max(l1, med + 1), r1, i * 2 + 2));
    return rst;
  }
};
SegmentTree tree;
void solve() {
  int n;
  cin >> n;
  vector<int> result(n);
  vector<pair<int, int> > pairs;
  for (int i = 0; i < n; ++i) {
    cin >> result[i];
    result[i]--;
    pairs.push_back({result[i], -i});
  }
  sort(pairs.begin(), pairs.end());
  for (auto pair : pairs) {
    int c = -pair.second;
    int should_remove = c - pair.first;
    if (should_remove < 0) continue;
    int v = tree.Get(0, n, 0, should_remove, 0) + 1;
    tree.Add(0, n, should_remove, v, 0);
  }
  cout << tree.Get(0, n, 0, n, 0) << '\n';
}
void multisolve() {
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  precalc();
  solve();
  return 0;
}
