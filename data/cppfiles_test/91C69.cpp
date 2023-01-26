#include <bits/stdc++.h>
using namespace std;
const int mod = 998244353, N = 1e5 + 5;
int t, n, a[N], tem, num;
pair<int, int> q[800], py[800];
void add(int& a, int b) {
  a += b;
  if (a > mod) a -= mod;
}
int Ceil(int a, int b) { return (a - 1) / b + 1; }
void slv() {
  int ans = 0, cnt1 = 0, cnt2 = 0;
  cin >> n;
  for (int i = 1; i <= n; ++i) cin >> a[i];
  q[++cnt1] = {a[n], 1};
  for (int i = n - 1; i >= 1; --i) {
    int cnt = 0;
    for (int j = 1; j <= cnt1; ++j) {
      num = Ceil(a[i], q[j].first);
      tem = a[i] / num;
      add(cnt, 1ll * q[j].second * (num - 1) % mod);
      if (tem == py[cnt2].first) {
        py[cnt2].second += q[j].second;
      } else
        py[++cnt2] = {tem, q[j].second};
    }
    py[++cnt2] = {a[i], 1};
    for (int i = 1; i <= cnt2; ++i) q[i] = py[i];
    cnt1 = cnt2;
    cnt2 = 0;
    add(ans, 1ll * i * cnt % mod);
  }
  cout << ans << '\n';
}
int main() {
  {
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(0);
  }
  cin >> t;
  while (t--) slv();
}
