#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pil = pair<int, ll>;
using pli = pair<ll, int>;
using pll = pair<ll, ll>;
using vint = vector<int>;
using vll = vector<ll>;
using vld = vector<ld>;
using vpii = vector<pii>;
using vpil = vector<pil>;
using vpli = vector<pli>;
using vpll = vector<pll>;
template <typename... Args>
void readln(Args&... args) {
  ((cin >> args), ...);
}
template <typename... Args>
void writeln(Args... args) {
  ((cout << args << " "), ...);
  cout << '\n';
}
void solve() {
  int n, m;
  readln(n, m);
  ;
  vector<vint> a(n + 1, vint(m + 1));
  for (int i = 1; i <= n; i++) {
    string s;
    readln(s);
    ;
    for (int j = 1; j <= m; j++) a[i][j] = (s[j - 1] == '1');
  }
  auto cs = a;
  for (int i = 1; i <= m; i++) {
    for (int j = 1; j <= n; j++) cs[j][i] += cs[j - 1][i];
  }
  const auto F = [&](int s, int e, int j) {
    return (e - s - 1) - (cs[e - 1][j] - cs[s][j]);
  };
  const auto G = [&](int s, int e, int j) {
    return !a[s][j] + !a[e][j] + (cs[e - 1][j] - cs[s][j]);
  };
  int ans = n * m;
  vint b(m + 1), s(m + 1);
  for (int i = 1; i <= n; i++) {
    for (int j = i + 4; j <= n; j++) {
      for (int k = 1; k <= m; k++) s[k] = s[k - 1] + G(i, j, k);
      for (int k = m; k >= 1; k--)
        b[k] = min(k == m ? int(1e9) : b[k + 1], s[k - 1] + F(i, j, k));
      for (int k = 1; k + 3 <= m; k++)
        ans = min(ans, b[k + 3] + F(i, j, k) - s[k]);
    }
  }
  cout << ans << '\n';
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t;
  readln(t);
  ;
  while (t--) solve();
  return 0;
}
