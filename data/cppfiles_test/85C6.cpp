#include <bits/stdc++.h>
using namespace std;
constexpr int MaxN = 200 + 5, MaxSqrt = 20 + 5;
constexpr long long Infinity = (1LL << 62);
inline int QuickPow(const int val, const int lev, const int Mod) {
  if (!lev) return 1;
  if (lev & 1) return ((long long)QuickPow(val, lev ^ 1, Mod) * val) % Mod;
  const int Half = QuickPow(val, lev >> 1, Mod);
  return ((long long)Half * Half) % Mod;
}
inline int Inverse(const int val, const int Mod) {
  return QuickPow(val, Mod - 2, Mod);
}
int Fac[MaxN], Inv[MaxN], dp[MaxN][MaxSqrt][MaxN];
bitset<MaxN> Bitset[MaxN][MaxSqrt];
inline int Dynamic_Programming(const int n, const int a, const int i,
                               const int x, const int Sum, const int Mod) {
  if (Bitset[i][x][Sum]) return dp[i][x][Sum];
  Bitset[i][x][Sum] = true;
  long long Record = 0;
  if (!x)
    Record = (((i <= a) && (!Sum)) ? ((long long)Fac[n] * Inv[i]) : 0);
  else {
    const int Lef = ((i <= a) ? 0 : ((i + 1) - a)), Rig = ((n + 1) - a);
    if ((Lef <= x) && (x <= Rig))
      for (register int j = (i); j >= (1); --j) {
        if (Sum < ((i - j) * x)) break;
        if ((Record +=
             ((long long)Inv[i - j] *
              Dynamic_Programming(n, a, j, x - 1, Sum - ((i - j) * x), Mod))) &
            Infinity)
          Record %= Mod;
      }
  }
  return (dp[i][x][Sum] = (Record % Mod));
}
int main() {
  ios::sync_with_stdio(false), cin.tie(nullptr);
  int n, Mod;
  cin >> n >> Mod, Fac[0] = 1;
  for (register int i = (1); i <= (n); ++i)
    Fac[i] = ((long long)Fac[i - 1] * i) % Mod;
  Inv[n] = Inverse(Fac[n], Mod);
  for (register int i = (n); i >= (1); --i)
    Inv[i - 1] = ((long long)Inv[i] * i) % Mod;
  const int Limit = max(1, (int)((n - sqrt(n << 1)) - 2));
  long long Answer = 0;
  for (register int a = (Limit); a <= (n + 1); ++a) {
    memset(dp, 0, sizeof(dp));
    memset(Bitset, 0, sizeof(Bitset));
    for (register int i = (0); i <= (a); ++i)
      Answer += Dynamic_Programming(n, a, n, ((n + 1) - a), i, Mod);
  }
  cout << (Answer %= Mod) << endl;
  return 0;
}
