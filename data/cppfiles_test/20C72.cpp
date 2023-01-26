#include <bits/stdc++.h>
using namespace std;
template <typename T>
using vc = vector<T>;
using ll = int64_t;
using vi = vc<int>;
using vs = vc<string>;
using vvi = vc<vc<int>>;
using pii = pair<int, int>;
using vpii = vc<pii>;
using vll = vc<ll>;
using pll = pair<ll, ll>;
using vpll = vc<pll>;
constexpr int N = 411;
int n, m;
string a[N];
void work(int tc) {
  cin >> n >> m;
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
    a[i] = "0" + a[i];
  }
  vvi s;
  s.resize(n + 1, vi(m + 1, 0));
  int ans = n * m;
  for (int i = 1; i + 4 <= n; ++i) {
    s[i][0] = 0;
    vi p(m + 1, 0);
    for (int j = 1; j < m; ++j) {
      s[i][j] = s[i][j - 1] + (a[i][j] == '0');
    }
    for (int k = i + 1; k <= n; ++k) {
      s[k][0] = 0;
      for (int j = 1; j <= m; ++j) {
        s[k][j] =
            s[k - 1][j] + s[k][j - 1] - s[k - 1][j - 1] + (a[k][j] == '0');
      }
      vi q(m + 1, 1e9);
      for (int j = 1; j <= m; ++j) {
        q[j] = min(q[j - 1], -s[k][j] + p[j]);
        if (j >= 4 && k - i + 1 >= 5) {
          ans = min(ans, s[k][j - 1] + p[j] + q[j - 3]);
        }
      }
      for (int j = 1; j <= m; ++j) {
        s[k][j] =
            s[k - 1][j] + s[k][j - 1] - s[k - 1][j - 1] + (a[k][j] == '1');
        p[j] += (a[k][j] == '0');
      }
    }
  }
  cout << ans << endl;
}
int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0),
      cout << fixed << setprecision(12);
  int tc = 1;
  cin >> tc;
  for (int i = 1; i <= tc; ++i) work(i);
}
