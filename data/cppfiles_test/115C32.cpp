#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
unsigned seed = chrono::system_clock::now().time_since_epoch().count();
mt19937 eng(seed);
long long random2() { return (1ll << 31ll) * eng() + eng(); }
long long n, m, k, q, T;
const long long big = 1000000007;
const long long big2 = 1000000009;
const long long mod = 998244353;
const long long MAXN = 1000004;
long long rowpar[MAXN][2] = {0};
long long broken_rows = 0;
long long empty_rows = 0;
long long colpar[MAXN][2] = {0};
long long broken_cols = 0;
long long empty_cols = 0;
long long occupied = 0;
long long sumpar[2] = {0};
long long two[MAXN] = {0};
bool brokenr(long long i) { return (rowpar[i][0] != 0 && rowpar[i][1] != 0); }
bool brokenc(long long i) { return (colpar[i][0] != 0 && colpar[i][1] != 0); }
unordered_map<long long, long long> M;
long long geta(long long i, long long j) {
  long long h = i * MAXN + j;
  if (M.find(h) == M.end()) return -1;
  return M[h];
}
void seta(long long i, long long j, long long c) {
  long long h = i * MAXN + j;
  M[h] = c;
}
long long cross() { return (sumpar[0] == 0) + (sumpar[1] == 0); }
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  long long a, b, c, d, e;
  cin >> n >> m >> k;
  long long t = 1;
  for (int c1 = 0; c1 < (MAXN); ++c1) {
    two[c1] = t;
    t *= 2;
    t %= mod;
  }
  empty_cols = m;
  empty_rows = n;
  for (int c1 = 0; c1 < (k); ++c1) {
    cin >> a >> b >> c;
    a--;
    b--;
    long long br1 = brokenr(a);
    long long bc1 = brokenc(b);
    long long er1 = (rowpar[a][0] == 0 && rowpar[a][1] == 0);
    long long ec1 = (colpar[b][0] == 0 && colpar[b][1] == 0);
    long long ab = geta(a, b);
    if (ab != -1) {
      rowpar[a][(ab ^ (b % 2))]--;
      colpar[b][(ab ^ (a % 2))]--;
      sumpar[(a + b + ab) % 2]--;
      occupied--;
    }
    seta(a, b, c);
    if (c != -1) {
      rowpar[a][(c ^ (b % 2))]++;
      colpar[b][(c ^ (a % 2))]++;
      sumpar[(a + b + c) % 2]++;
      occupied++;
    }
    long long br2 = brokenr(a);
    long long bc2 = brokenc(b);
    long long er2 = (rowpar[a][0] == 0 && rowpar[a][1] == 0);
    long long ec2 = (colpar[b][0] == 0 && colpar[b][1] == 0);
    broken_rows += br2 - br1;
    broken_cols += bc2 - bc1;
    empty_rows += er2 - er1;
    empty_cols += ec2 - ec1;
    long long ans = 0;
    if (broken_rows == 0) {
      ans += two[empty_rows];
    }
    if (broken_cols == 0) {
      ans += two[empty_cols];
    }
    ans %= mod;
    long long overlap = cross();
    ans -= overlap;
    ans += mod;
    ans %= mod;
    cout << ans << "\n";
  }
  return 0;
}
