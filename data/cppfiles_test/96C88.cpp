#include <bits/stdc++.h>
using namespace std;
const long long INF = 1e18;
const long long maxn = 200005;
long long n, q;
long long tree[4 * maxn];
long long a[maxn];
long long treel[4 * maxn], treer[4 * maxn];
void update(int id, int l, int r, int vt, int value) {
  if (vt < l || vt > r) return;
  if (l == r) {
    tree[id] = treel[id] = treer[id] = 1;
    a[vt] = value;
    return;
  }
  int mid = (l + r) / 2;
  if (vt <= mid)
    update(id * 2, l, mid, vt, value);
  else
    update(id * 2 + 1, mid + 1, r, vt, value);
  tree[id] = tree[id * 2] + tree[id * 2 + 1];
  treel[id] = treel[id * 2];
  treer[id] = treer[id * 2 + 1];
  if (treel[id * 2] == mid - l + 1 && a[mid] <= a[mid + 1])
    treel[id] += treel[id * 2 + 1];
  if (treer[id * 2 + 1] == r - (mid + 1) + 1 && a[mid] <= a[mid + 1])
    treer[id] += treer[id * 2];
  if (a[mid] <= a[mid + 1]) tree[id] += treer[id * 2] * treel[id * 2 + 1];
}
long long ans = 0;
long long streak = 0;
void query(int id, int l, int r, int L, int R) {
  if (r < L || l > R) return;
  if (L <= l && r <= R) {
    ans += tree[id];
    if (streak != 0) {
      if (a[l - 1] <= a[l]) {
        ans += streak * treel[id];
        if (treel[id] == r - l + 1)
          streak += r - l + 1;
        else
          streak = treer[id];
      } else
        streak = treer[id];
    } else
      streak = treer[id];
    return;
  }
  int mid = (l + r) / 2;
  query(id * 2, l, mid, L, R);
  query(id * 2 + 1, mid + 1, r, L, R);
}
int main() {
  cin >> n >> q;
  a[0] = 1e10;
  a[n + 1] = -1;
  for (long long i = 1; i <= 4 * n; i++) {
    tree[i] = 0;
    treel[i] = 0;
    treer[i] = 0;
  }
  for (long long i = 1; i <= n; i++) {
    cin >> a[i];
    update(1, 1, n, i, a[i]);
  }
  for (long long i = 1; i <= q; i++) {
    int type;
    cin >> type;
    if (type == 1) {
      int vt, val;
      cin >> vt >> val;
      update(1, 1, n, vt, val);
    } else {
      int l, r;
      cin >> l >> r;
      ans = 0;
      streak = 0;
      query(1, 1, n, l, r);
      cout << ans << "\n";
    }
  }
}
