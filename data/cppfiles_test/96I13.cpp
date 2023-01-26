#include <bits/stdc++.h>
using namespace std;
constexpr long long N = 200015;
constexpr long long D = 200;
constexpr long double EPS = 1e-8;
ofstream fout;
ifstream fin;
long long n, m, k;
int flag = -1;
long long st(long long a, long long b) {
  if (b == 0) return 1ll;
  long long o = st(a, b / 2ll);
  o *= o;
  o %= ((long long)998244353);
  if (b & 1) o *= a;
  o %= ((long long)998244353);
  return o;
}
long long dp[505][505];
void solve() {
  cin >> n >> k;
  vector<long long> f(506), of(506);
  f[0] = f[1] = of[0] = of[1] = 1;
  for (long long i = (2); i < (504); i++) {
    f[i] = (i * f[i - 1]) % ((long long)998244353);
    of[i] = st(f[i], ((long long)998244353) - 2ll);
  }
  vector<vector<long long> > prev(506, vector<long long>(506));
  for (long long i = 0; i < (505); i++)
    for (long long j = 0; j < (505); j++) prev[i][j] = st(i, j);
  for (long long size = (2); size < (504); size++) {
    for (long long h = 0; h < (504); h++) {
      dp[size][h] = prev[min(h, size - 1)][size];
      if (h >= size) {
        for (long long i = (2); i < (size + 1); i++) {
          dp[size][h] +=
              ((((f[size] * of[i]) % ((long long)998244353) * of[size - i]) %
                ((long long)998244353) * dp[i][h - size + 1]) *
               prev[size - 1][size - i]) %
              ((long long)998244353);
        }
        dp[size][h] %= ((long long)998244353);
      }
    }
  }
  cout << dp[n][k];
}
signed main(signed argc, char *argv[]) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cout.precision(14);
  cout.fixed;
  int t = 1;
  srand(time(0));
  fout.precision(14);
  fout.fixed;
  int y = 0;
  while (t--) {
    solve();
  }
  fout.close();
  fin.close();
}
