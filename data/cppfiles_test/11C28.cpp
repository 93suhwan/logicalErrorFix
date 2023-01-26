#include <bits/stdc++.h>
using namespace std;
const int maxn = 2 * 1e5 + 10, maxm = 2 * 8 * maxn, mod = 998244353;
const int inf = 0x3f3f3f3f;
const double pi = acos(-1), eps = 1e-7;
int n;
int a[maxn];
int f[maxn];
int tr[maxn];
int lowbit(int x) { return x & (-x); }
void modify(int x, int k) {
  while (x <= n) {
    tr[x] = max(tr[x], k);
    x += lowbit(x);
  }
}
int query(int x) {
  int res = 0;
  while (x) {
    res = max(res, tr[x]);
    x -= lowbit(x);
  }
  return res;
}
pair<int, int> b[maxn];
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  for (int i = 1; i <= n; i++) {
    b[i] = {i - a[i], a[i]};
  }
  sort(b + 1, b + 1 + n);
  int ans = 0;
  for (int i = 1; i <= n; i++) {
    if (b[i].first >= 0) {
      f[i] = query(b[i].second) + 1;
      modify(b[i].second + 1, f[i]);
      ans = max(ans, f[i]);
    }
  }
  cout << ans << "\n";
  return 0;
}
