#include <bits/stdc++.h>
template <class T>
bool chmax(T &a, const T &b) {
  if (a < b) {
    a = b;
    return 1;
  }
  return 0;
}
template <class T>
bool chmin(T &a, const T &b) {
  if (b < a) {
    a = b;
    return 1;
  }
  return 0;
}
using namespace std;
string to_string(const string &s) { return '"' + s + '"'; }
string to_string(const char *s) { return to_string((string)s); }
template <typename A, typename B>
string to_string(pair<A, B> p) {
  return "(" + to_string(p.first) + ", " + to_string(p.second) + ")";
}
void debug_out() { cerr << endl; }
template <typename Head, typename... Tail>
void debug_out(Head H, Tail... T) {
  cerr << " " << to_string(H);
  debug_out(T...);
}
using ll = long long;
using LL = __int128;
using pii = pair<int, int>;
using vi = vector<int>;
using db = double;
using ldb = long double;
const int maxn = 100;
int mod;
const int inf = 0x3f3f3f3f;
inline void chadd(int &x, int y) {
  x += y;
  if (x >= mod) x -= mod;
}
inline int Madd(int x, int y) { return x + y < mod ? x + y : x + y - mod; }
int dp[maxn + 5][maxn + 5][maxn + 5];
int binom[maxn + 5][maxn + 5];
int fac[maxn + 5];
int main() {
  int n, m, k;
  scanf("%d%d%d%d", &n, &m, &k, &mod);
  for (auto i = 0; i <= n; i++) binom[i][0] = 1 % mod;
  for (auto i = 1; i <= n; i++)
    for (auto j = 1; j <= i; j++)
      binom[i][j] = Madd(binom[i - 1][j], binom[i - 1][j - 1]);
  fac[0] = 1;
  for (auto i = 1; i <= n; i++) fac[i] = 1ll * fac[i - 1] * i % mod;
  for (auto M = 1; M <= m; M++) dp[M][0][0] = 1;
  for (auto L = 1; L <= n; L++) dp[1][L][1] = fac[L] % mod;
  for (auto M = 1; M <= m - 1; M++)
    for (auto L = 0; L <= n; L++)
      for (auto K = 0; K <= L; K++)
        if (dp[M][L][K]) {
          for (auto L2 = 0; L2 <= n - L - 1; L2++)
            for (auto K2 = 0; K2 <= L2; K2++)
              if (dp[M][L2][K2]) {
                chadd(dp[M + 1][L + L2 + 1][K + K2], 1ll * binom[L + L2][L] *
                                                         dp[M][L][K] % mod *
                                                         dp[M][L2][K2] % mod);
              }
        }
  printf("%d\n", dp[m][n][k]);
  return 0;
}
