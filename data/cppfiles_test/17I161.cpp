#include <bits/stdc++.h>
using namespace std;
const int N = 5e5 + 7;
const int M = 1e6 + 7;
const int mod = 1e9 + 7;
const int INF = 0x3f3f3f3f;
const double eps = 1e-6;
long long t, n, tot = 0;
long long arr[N], lsh[N], tree[N];
inline void pushup(int node) {
  tree[node] = tree[node << 1] + tree[node << 1 | 1];
}
void build(int node, int l, int r) {
  if (l == r) {
    tree[node] = 0;
    return;
  }
  int mid = l + r >> 1;
  build(node << 1, l, mid), build(node << 1 | 1, mid + 1, r);
  pushup(node);
}
void Updata(int node, int l, int r, int pos, int val) {
  if (l == r) {
    tree[node] += val;
    return;
  }
  int mid = l + r >> 1;
  if (pos <= mid)
    Updata(node << 1, l, mid, pos, val);
  else
    Updata(node << 1 | 1, mid + 1, r, pos, val);
  pushup(node);
}
long long quary(int node, int l, int r, int ql, int qr) {
  if (!ql || ql > qr) return 0;
  if (ql <= l && r <= qr) return tree[node];
  int mid = l + r >> 1;
  long long ans = 0;
  if (ql <= mid) ans += quary(node << 1, l, mid, ql, qr);
  if (qr > mid) ans += quary(node << 1 | 1, mid + 1, r, ql, qr);
  return ans;
}
int getid(long long val) {
  return lower_bound(lsh + 1, lsh + 1 + tot, val) - lsh;
}
void solve() {
  cin >> n;
  tot = 0;
  for (int i = 1; i <= n; ++i) {
    cin >> arr[i];
    lsh[++tot] = arr[i];
  }
  sort(lsh + 1, lsh + 1 + tot);
  tot = unique(lsh + 1, lsh + 1 + tot) - (lsh + 1);
  build(1, 1, tot);
  long long ans = 0;
  for (int i = 1; i <= n; ++i) {
    int id = getid(arr[i]);
    ans += min(quary(1, 1, tot, 1, id - 1), quary(1, 1, tot, id + 1, tot));
    Updata(1, 1, tot, id, 1);
  }
  cout << ans << '\n';
}
signed main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> t;
  while (t--) solve();
  return 0;
}
