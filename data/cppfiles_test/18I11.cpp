#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
const long long int INFLL = 0x3f3f3f3f3f3f3f3f;
const int MOD = 1e9 + 7;
const double EPS = 1e-9;
const double PI = acos(-1);
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int rand(int x, int y) { return uniform_int_distribution<int>(x, y)(rng); }
int mul(int a, int b) {
  int ret = (1ll * (a % MOD) * (b % MOD)) % MOD;
  return (ret + MOD) % MOD;
}
int add(int a, int b) {
  int ret = (1ll * (a % MOD) + (b % MOD)) % MOD;
  return (ret + MOD) % MOD;
}
int pow_exp(int n, int p) {
  if (!p) return 1;
  if (p & 1) return mul(n, pow_exp(n, p - 1));
  int tmp = pow_exp(n, p / 2);
  return mul(tmp, tmp);
}
const int MAX = 2e5 + 10;
const int NMAX = 2e5 + 10;
const int MMAX = 2e5 + 10;
const int LOG_MAX = ceil(log2(double(NMAX)));
const int BLOCK = ceil(sqrt(double(NMAX)));
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ;
  int t;
  cin >> t;
  while (t--) {
    int n, d;
    cin >> n >> d;
    vector<int> vec(n);
    for (auto &i : vec) cin >> i;
    int log_2 = ceil(log2(double(2 * n)));
    vector<vector<int> > par(n, vector<int>(log_2));
    vector<vector<int> > par_and(n, vector<int>(log_2));
    for (int i = 0; i < n; i++) {
      par[i][0] = (i - d + n) % n;
      par_and[i][0] = vec[par[i][0]];
    }
    for (int i = 0; i < n; i++)
      for (int j = 1; j < log_2; j++) {
        par[i][j] = par[par[i][j - 1]][j - 1];
        par_and[i][j] = par_and[i][j - 1] & par_and[par[i][j - 1]][j - 1];
      }
    auto test = [&](int m) {
      for (int i = 0; i < n; i++) {
        int ai = vec[i];
        int cur = i;
        for (int j = log_2 - 1; j >= 0; j--)
          if (m & (1 << j)) {
            ai &= par_and[cur][j];
            cur = par[cur][j];
          }
        if (ai) return false;
      }
      return true;
    };
    int l = 0;
    int r = 2 * n;
    int ans = -1;
    while (l <= r) {
      int mid = (l + r) / 2;
      if (test(mid)) {
        ans = mid;
        r = mid - 1;
      } else {
        l = mid + 1;
      }
    }
    cout << ans << '\n';
  }
}
