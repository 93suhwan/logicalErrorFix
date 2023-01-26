#include <bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr int INF = 0x3f3f3f3f;
constexpr long long LINF = 0x3f3f3f3f3f3f3f3fLL;
constexpr double EPS = 1e-8;
constexpr int MOD = 1000000007;
constexpr int DY[]{1, 0, -1, 0}, DX[]{0, -1, 0, 1};
constexpr int DY8[]{1, 1, 0, -1, -1, -1, 0, 1},
    DX8[]{0, -1, -1, -1, 0, 1, 1, 1};
template <typename T, typename U>
inline bool chmax(T& a, U b) {
  return a < b ? (a = b, true) : false;
}
template <typename T, typename U>
inline bool chmin(T& a, U b) {
  return a > b ? (a = b, true) : false;
}
struct IOSetup {
  IOSetup() {
    std::cin.tie(nullptr);
    std::ios_base::sync_with_stdio(false);
    std::cout << fixed << setprecision(20);
  }
} iosetup;
void solve() {
  int n, m;
  cin >> n >> m;
  vector<int> x(n);
  for (int i = (0); i < (n); ++i) cin >> x[i];
  vector<string> s(n);
  for (int i = (0); i < (n); ++i) cin >> s[i];
  ll surprise = -LINF;
  vector<int> ans;
  for (int bit = (0); bit < (1 << n); ++bit) {
    ll value = 0;
    for (int i = (0); i < (n); ++i) {
      if (bit >> i & 1) {
        value += x[i];
      } else {
        value -= x[i];
      }
    }
    vector<int> coef(m, 0);
    for (int j = (0); j < (m); ++j) {
      for (int i = (0); i < (n); ++i) {
        if (s[i][j] == '1') {
          if (bit >> i & 1) {
            --coef[j];
          } else {
            ++coef[j];
          }
        }
      }
    }
    vector<int> ord(m);
    iota((ord).begin(), (ord).end(), 0);
    sort((ord).begin(), (ord).end(),
         [&](int l, int r) -> bool { return coef[l] < coef[r]; });
    vector<int> p(m);
    for (int i = (0); i < (m); ++i) {
      p[ord[i]] = i + 1;
      value += coef[ord[i]] * (i + 1);
    }
    if (chmax(surprise, value)) ans = p;
  }
  for (int i = (0); i < (m); ++i) cout << ans[i] << " \n"[i + 1 == m];
}
int main() {
  int t;
  cin >> t;
  while (t--) solve();
  return 0;
}
