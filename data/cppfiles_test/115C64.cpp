#include <bits/stdc++.h>
using namespace std;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
const long long maxn = 2e6 + 5, mod = 998244353, inf = 1e9;
const long double pi = 4 * atan(1.0), eps = 1e-9;
void solve();
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  ;
  long long tc = 1;
  for (long long test = (long long)(1); test <= (long long)(tc); ++test) {
    solve();
  }
  return 0;
}
long long pw[maxn];
map<pair<long long, long long>, long long> g;
long long n, m, q;
long long cntr;
long long cntc;
long long fixr2[maxn][2];
long long fixc2[maxn][2];
long long sfixr, sfixc;
long long bfixr, bfixc;
long long fix[2];
long long di[] = {-1, 0, 1, 0};
long long dj[] = {0, 1, 0, -1};
void solve() {
  pw[0] = 1;
  for (long long i = (long long)(1); i <= (long long)(maxn - 1); ++i)
    pw[i] = pw[i - 1] * 2 % mod;
  cin >> n >> m >> q;
  for (long long i = (long long)(1); i <= (long long)(q); ++i) {
    long long a, b, s;
    cin >> a >> b >> s;
    if (g.count({a, b})) {
      sfixr -= (fixr2[a][0] or fixr2[a][1]);
      sfixc -= (fixc2[b][0] or fixc2[b][1]);
      bfixr -= (fixr2[a][0] and fixr2[a][1]);
      bfixc -= (fixc2[b][0] and fixc2[b][1]);
      fixr2[a][(b & 1) ^ g[{a, b}]]--;
      fixc2[b][(a & 1) ^ g[{a, b}]]--;
      sfixr += (fixr2[a][0] or fixr2[a][1]);
      sfixc += (fixc2[b][0] or fixc2[b][1]);
      bfixr += (fixr2[a][0] and fixr2[a][1]);
      bfixc += (fixc2[b][0] and fixc2[b][1]);
      for (long long dir = (long long)(0); dir <= (long long)(3); ++dir) {
        long long ti = a + di[dir];
        long long tj = b + dj[dir];
        if (ti == a)
          cntr -= (g.count({ti, tj}) and g[{ti, tj}] == g[{a, b}]);
        else
          cntc -= (g.count({ti, tj}) and g[{ti, tj}] == g[{a, b}]);
      }
      fix[(a + b & 1) ^ g[{a, b}]]--;
      g.erase({a, b});
    }
    if (s >= 0) {
      g[{a, b}] = s;
      fix[(a + b & 1) ^ g[{a, b}]]++;
      for (long long dir = (long long)(0); dir <= (long long)(3); ++dir) {
        long long ti = a + di[dir];
        long long tj = b + dj[dir];
        if (ti == a)
          cntr += (g.count({ti, tj}) and g[{ti, tj}] == g[{a, b}]);
        else
          cntc += (g.count({ti, tj}) and g[{ti, tj}] == g[{a, b}]);
      }
      sfixr -= (fixr2[a][0] or fixr2[a][1]);
      sfixc -= (fixc2[b][0] or fixc2[b][1]);
      bfixr -= (fixr2[a][0] and fixr2[a][1]);
      bfixc -= (fixc2[b][0] and fixc2[b][1]);
      fixr2[a][(b & 1) ^ g[{a, b}]]++;
      fixc2[b][(a & 1) ^ g[{a, b}]]++;
      sfixr += (fixr2[a][0] or fixr2[a][1]);
      sfixc += (fixc2[b][0] or fixc2[b][1]);
      bfixr += (fixr2[a][0] and fixr2[a][1]);
      bfixc += (fixc2[b][0] and fixc2[b][1]);
    }
    long long ans = 0;
    if (!cntr and !bfixr) {
      ans += pw[n - sfixr];
    }
    if (!cntc and !bfixc) {
      ans += pw[m - sfixc];
    }
    ans -= (!fix[0]) + (!fix[1]);
    cout << (ans % mod + mod) % mod << '\n';
  }
}
