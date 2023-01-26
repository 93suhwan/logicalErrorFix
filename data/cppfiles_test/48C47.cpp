#include <bits/stdc++.h>
using namespace std;
const long long int N = 5e5 + 5;
long long int pre[N];
pair<long long int, long long int> tree[4 * N];
long long int inf = 1e18 + 5;
void build(long long int node, long long int start, long long int end) {
  if (start == end) {
    tree[node] = {pre[start], pre[start]};
    return;
  }
  long long int mid = (start + end) / 2;
  build(node * 2, start, mid);
  build(node * 2 + 1, mid + 1, end);
  tree[node].first = max(tree[node * 2].first, tree[node * 2 + 1].first);
  tree[node].second = min(tree[node * 2].second, tree[node * 2 + 1].second);
}
pair<long long int, long long int> get(long long int node, long long int start,
                                       long long int end, long long int l,
                                       long long int r) {
  if (start > end || start > r || end < l) return {-inf, inf};
  if (start >= l && end <= r) return tree[node];
  long long int mid = (start + end) / 2;
  auto a = get(node * 2, start, mid, l, r);
  auto b = get(node * 2 + 1, mid + 1, end, l, r);
  pair<long long int, long long int> res;
  res.first = max(a.first, b.first);
  res.second = min(a.second, b.second);
  return res;
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long int n, q;
  cin >> n >> q;
  long long int a[n + 1];
  long long int b[n + 1];
  for (long long int i = 1; i <= n; i++) cin >> a[i];
  for (long long int i = 1; i <= n; i++) {
    cin >> b[i];
    pre[i] = pre[i - 1] + b[i] - a[i];
  }
  build(1, 1, n);
  while (q--) {
    long long int l, r;
    cin >> l >> r;
    if (pre[l - 1] != pre[r]) {
      cout << "-1\n";
      continue;
    }
    auto g = get(1, 1, n, l, r);
    if (g.second < pre[l - 1]) {
      cout << "-1\n";
      continue;
    }
    cout << g.first - pre[l - 1] << "\n";
  }
}
