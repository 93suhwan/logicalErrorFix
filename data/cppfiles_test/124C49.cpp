#include <bits/stdc++.h>
using namespace std;
constexpr int MaxN = 2000 + 5, Mod = 1000000007;
inline void SimpleMod(int &wei) { (wei >= Mod) && (wei -= Mod); }
int F[2][MaxN << 1], G[2][MaxN << 1];
char a[MaxN], b[MaxN];
int main() {
  ios::sync_with_stdio(false), cin.tie(nullptr);
  int T;
  cin >> T;
  int n;
  while (T--) {
    cin >> n >> (a + 1) >> (b + 1);
    for (register int i = (1); i <= (n); ++i) {
      if ((i & 1) || (a[i] == '?')) continue;
      a[i] = ((a[i] == '0') ? '1' : '0');
    }
    for (register int i = (1); i <= (n); ++i) {
      if ((i & 1) || (b[i] == '?')) continue;
      b[i] = ((b[i] == '0') ? '1' : '0');
    }
    bool Cur = false, Last = true;
    for (register int i = (0); i <= (n << 1); ++i) F[Cur][i] = G[Cur][i] = 0;
    G[Cur][n] = 1;
    for (register int i = (1); i <= (n); ++i) {
      swap(Cur, Last);
      for (register int j = (0); j <= (n << 1); ++j) F[Cur][j] = G[Cur][j] = 0;
      for (register int j = (0); j <= (n << 1); ++j) {
        if (!(F[Last][j] || G[Last][j])) continue;
        for (register char A = '0'; A <= '1'; ++A) {
          if (!((a[i] == '?') || (a[i] == A))) continue;
          for (register char B = '0'; B <= '1'; ++B) {
            if (!((b[i] == '?') || (b[i] == B))) continue;
            const int Delta = ((A == '1') - (B == '1'));
            SimpleMod(G[Cur][j + Delta] += G[Last][j]);
            F[Cur][j + Delta] =
                (F[Cur][j + Delta] + (F[Last][j] + ((long long)G[Last][j] *
                                                    abs((j + Delta) - n)))) %
                Mod;
          }
        }
      }
    }
    cout << F[Cur][n] << '\n';
  }
  return 0;
}
