#include <bits/stdc++.h>
using namespace std;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int rnd(int l, int r) { return l + rng() % (r - l + 1); }
const int N = 21, TT = 1 << 20;
int n;
int f[TT], num[TT], l[N];
string a[N];
vector<int> s[N], m[N], c[N];
int main() {
  if (fopen("TASK"
            ".inp",
            "r")) {
    freopen(
        "TASK"
        ".inp",
        "r", stdin);
  }
  cin.tie(0)->sync_with_stdio(0);
  cin >> n;
  for (int i = 1, _c = n; i <= _c; ++i) {
    cin >> a[i];
    l[i] = a[i].size();
    a[i] = ' ' + a[i];
    s[i].resize(l[i] + 1);
    m[i].resize(l[i] + 1);
    c[i].resize(l[i] + 1);
    m[i][0] = 1e9;
    for (int j = 1, _c = l[i]; j <= _c; ++j) {
      s[i][j] = s[i][j - 1] + ((a[i][j] == '(') ? 1 : -1);
      m[i][j] = m[i][j - 1];
      c[i][j] = c[i][j - 1];
      if (s[i][j] < m[i][j - 1]) {
        m[i][j] = s[i][j];
        c[i][j] = 0;
      }
      if (s[i][j] == m[i][j]) c[i][j]++;
    }
  }
  memset(f, -1, sizeof f);
  f[0] = 0;
  int oo = (1 << n) - 1, ans = 0;
  for (int t = 0, _c = oo - 1; t <= _c; ++t)
    if (f[t] != -1) {
      for (int i = 1, _c = n; i <= _c; ++i)
        if (!((t >> (i - 1)) & 1)) {
          int t2 = (t | (1ll << (i - 1)));
          num[t2] = num[t] + s[i][l[i]];
          if (num[t] + m[i][l[i]] >= 0) {
            int sl = 0;
            if (num[t] + m[i][l[i]] == 0) sl += c[i][l[i]];
            f[t2] = max(f[t2], f[t] + sl);
            ans = max(ans, f[t2]);
          } else {
            int lo = 1, hi = l[i], ret = 0;
            while (lo <= hi) {
              int mid = (lo + hi) / 2;
              if (num[t] + m[i][mid] >= 0)
                ret = mid, lo = mid + 1;
              else
                hi = mid - 1;
            }
            ans = max(ans, f[t] + c[i][ret]);
          }
        }
    }
  cout << ans << "\n";
  return 0;
}
