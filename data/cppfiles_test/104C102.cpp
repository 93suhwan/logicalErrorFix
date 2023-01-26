#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7;
const int N = 2e5 + 5;
struct dish {
  int a, b, pos;
};
int t, n, m;
dish c[N], ans[N];
bool cmp(dish x, dish y) { return x.a < y.a; }
bool cmp2(dish x, dish y) { return x.pos < y.pos; }
void solve() {
  long long res = 0;
  for (int i = 1; i <= n; ++i) {
    int k = c[i].a - m;
    if (k >= 0)
      res += c[i].b - k;
    else
      res += c[i].b + k;
  }
  if (res <= 0) {
    cout << -res << '\n';
    for (int i = 1; i <= n; ++i) {
      int k = c[i].a - m;
      int d = c[i].b + (k >= 0 ? 0 : k);
      ans[i].a = c[i].a - max(k, 0);
      ans[i].b = c[i].b - d;
      ans[i].pos = c[i].pos;
    }
    sort(ans + 1, ans + 1 + n, cmp2);
    for (int i = 1; i <= n; ++i) cout << ans[i].a << ' ' << ans[i].b << '\n';
    return;
  }
  for (int i = 1; i <= n; ++i) {
    int k = c[i].a - m;
    int d = c[i].b + (k >= 0 ? 0 : k);
    ans[i].pos = c[i].pos;
    ans[i].a = max(0, k);
    ans[i].b = d;
    int x = min({res / 2, (long long)d, 0LL + c[i].a - ans[i].a});
    ans[i].a += x;
    ans[i].b -= x;
    ans[i].a = c[i].a - ans[i].a;
    ans[i].b = c[i].b - ans[i].b;
    res -= x * 2;
  }
  sort(ans + 1, ans + 1 + n, cmp2);
  cout << abs(res) << '\n';
  for (int i = 1; i <= n; ++i) cout << ans[i].a << ' ' << ans[i].b << '\n';
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> t;
  while (t--) {
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
      cin >> c[i].a >> c[i].b;
      c[i].pos = i;
    }
    sort(c + 1, c + 1 + n, cmp);
    solve();
  }
}
