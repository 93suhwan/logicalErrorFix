#include <bits/stdc++.h>
using namespace std;
pair<long long int, long long int> tree[4 * 100005];
void build(int n, int st, int en, vector<long long int> &diff) {
  if (st == en) {
    tree[n] = {diff[st], diff[st]};
    return;
  }
  int mid = (st + en) / 2, lc = 2 * n, rc = lc + 1;
  build(lc, st, mid, diff);
  build(rc, mid + 1, en, diff);
  tree[n].first = min(tree[lc].first, tree[rc].first);
  tree[n].second = max(tree[lc].second, tree[rc].second);
}
pair<long long int, long long int> query(int n, int st, int en, int l, int r) {
  if (r < st || en < l) return {LLONG_MAX / 3, -LLONG_MAX / 3};
  if (l <= st && en <= r) return tree[n];
  int mid = (st + en) / 2, lc = 2 * n, rc = lc + 1;
  pair<long long int, long long int> q1 = query(lc, st, mid, l, r);
  pair<long long int, long long int> q2 = query(rc, mid + 1, en, l, r);
  return {min(q1.first, q2.first), max(q1.second, q2.second)};
}
int main() {
  int n, q, inp, l, r;
  scanf("%d %d", &n, &q);
  vector<long long int> a, b;
  for (int i = 0; i < n; i++) {
    scanf("%d", &inp);
    a.push_back(inp);
  }
  for (int i = 0; i < n; i++) {
    scanf("%d", &inp);
    b.push_back(inp);
  }
  vector<long long int> diff = {0};
  for (int i = 0; i < n; i++) diff.push_back(diff.back() + (b[i] - a[i]));
  build(1, 1, n, diff);
  while (q--) {
    scanf("%d %d", &l, &r);
    if (diff[r] != diff[l - 1]) {
      printf("%d\n", -1);
      continue;
    }
    auto minMax = query(1, 1, n, l, r);
    if (minMax.first < diff[l - 1]) {
      printf("%d\n", -1);
      continue;
    }
    cout << minMax.second - minMax.first << '\n';
  }
  return 0;
}
