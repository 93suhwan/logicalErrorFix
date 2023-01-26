#include <bits/stdc++.h>
using namespace std;
const double PI = acos(-1.0);
const int maxn = 2e5 + 5;
const int mod = 998244353;
long long A(int n, int k) {
  if (n < k) return 0;
  long long ans = 1;
  for (int i = n; i >= n - k + 1; --i) {
    ans = ((ans % mod) * i) % mod;
  }
  return ans;
}
long long qmi(int m, int k) {
  long long res = 1 % mod, t = m % mod;
  while (k) {
    if (k & 1) {
      res = res * t % mod;
    }
    t = t * t % mod;
    k >>= 1;
  }
  return res;
}
struct SegmentTree {
  long long l, r;
  long long sum;
} t[maxn * 4];
long long a[maxn], b[maxn];
void build(int o, int l, int r) {
  t[o].l = l, t[o].r = r;
  if (l == r) {
    t[o].sum = a[l];
    return;
  }
  int mid = (l + r) >> 1;
  build(o * 2, l, mid), build(o * 2 + 1, mid + 1, r);
  t[o].sum = t[o * 2].sum + t[o * 2 + 1].sum;
}
void update(int o, int x, int v) {
  if (t[o].l == t[o].r) {
    t[o].sum += v;
    return;
  }
  int mid = (t[o].l + t[o].r) >> 1;
  if (x <= mid)
    update(o * 2, x, v);
  else
    update(o * 2 + 1, x, v);
  t[o].sum = t[o * 2].sum + t[o * 2 + 1].sum;
}
int query(int o, int l, int r) {
  if (l <= t[o].l && r >= t[o].r) return t[o].sum;
  int mid = (t[o].l + t[o].r) >> 1;
  int sum = 0;
  if (l <= mid) sum += query(o * 2, l, r);
  if (r > mid) sum += query(o * 2 + 1, l, r);
  return sum;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int CASE;
  cin >> CASE;
  while (CASE--) {
    int n;
    cin >> n;
    for (int i = (0); i < (n); i++) {
      cin >> b[i];
    }
    vector<int> v;
    for (int i = (0); i < (n); i++) v.push_back(b[i]);
    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());
    build(1, 1, v.size());
    for (int i = (0); i < (v.size()); i++) update(1, i + 1, 0);
    long long ans = 0;
    for (int i = 0; i < n; ++i) {
      int cur = lower_bound(v.begin(), v.end(), b[i]) - v.begin();
      int d = v.size() - cur;
      int l, r;
      if (d == 1)
        r = 0;
      else
        r = query(1, 1, d - 1);
      if (d == v.size())
        l = 0;
      else
        l = query(1, d + 1, v.size());
      ans += min(l, r);
      update(1, d, 1);
    }
    cout << ans << endl;
  };
  return 0;
}
