#include <bits/stdc++.h>
using namespace std;
void update(long long node, long long start, long long end, long long pos,
            long long value, vector<long long>& tree) {
  if (start == end) {
    tree[node] += value;
  } else {
    long long mid = (start + end) / 2;
    if (start <= pos && pos <= mid) {
      update(2 * node, start, mid, pos, value, tree);
    } else {
      update(2 * node + 1, mid + 1, end, pos, value, tree);
    }
    tree[node] = tree[2 * node] + tree[2 * node + 1];
  }
}
long long query(long long node, long long start, long long end, long long l,
                long long r, vector<long long>& tree) {
  if (l > r)
    return 0;
  else if (start > r || end < l) {
    return 0;
  } else if (l <= start && end <= r) {
    return tree[node];
  } else {
    long long mid = (start + end) / 2;
    long long left = query(2 * node, start, mid, l, r, tree);
    long long right = query(2 * node + 1, mid + 1, end, l, r, tree);
    return left + right;
  }
}
void solve() {
  long long n;
  cin >> n;
  vector<long long> a(n, 0);
  vector<pair<long long, long long>> vv;
  for (long long i = 0; i < n; i++) {
    cin >> a[i];
    vv.push_back({a[i], i});
  }
  sort(vv.begin(), vv.end());
  long long curr = 1;
  for (long long i = 0; i < n; i++) {
    if (i == 0) {
      a[vv[i].second] = curr;
    } else {
      if (vv[i].first == vv[i - 1].first) {
        a[vv[i].second] = curr;
      } else {
        curr++;
        a[vv[i].second] = curr;
      }
    }
  }
  vector<long long> tree(4 * n, 0);
  long long ans = 0;
  for (long long i = 0; i < n; i++) {
    ans += min(query(1, 0, n - 1, 0, a[i] - 2, tree),
               query(1, 0, n - 1, a[i], n - 1, tree));
    update(1, 0, n - 1, a[i] - 1, 1, tree);
  }
  cout << ans << endl;
}
signed main() {
  long long t;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
