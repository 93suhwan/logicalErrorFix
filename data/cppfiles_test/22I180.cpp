#include <bits/stdc++.h>
using namespace std;
char _c;
bool _f;
template <class T>
inline void IN(T& x) {
  x = 0, _f = 0;
  while (_c = getchar(), !isdigit(_c))
    if (_c == '-') _f = 1;
  while (isdigit(_c)) x = x * 10 + _c - '0', _c = getchar();
  if (_f) x = -x;
}
template <class T>
inline void chkmin(T& x, T y) {
  if (x > y) x = y;
}
template <class T>
inline void chkmax(T& x, T y) {
  if (x < y) x = y;
}
const int N = 45;
const int K = 15;
int n, k, siz[K];
long long pres[K], oper[K], dan[K][N];
bool solve(int step, long long S) {
  if (step == k + 1) {
    int cnt1 = __builtin_popcount(S), cnt0 = n - cnt1;
    return S == (((1ll << cnt1) - 1ll) << cnt0);
  }
  long long T = S ^ (S & oper[step]);
  int cnt1 = __builtin_popcount(S & oper[step]);
  int cnt0 = __builtin_popcount(pres[step - 1] & oper[step]) - cnt1;
  for (int i = cnt0; i <= siz[step] - cnt1; ++i)
    if (!solve(step + 1, T | (oper[step] ^ dan[step][i]))) return false;
  return true;
}
int main() {
  IN(n), IN(k);
  int p;
  for (int i = 1; i <= k; ++i) {
    IN(siz[i]);
    for (int j = 1; j <= siz[i]; ++j)
      IN(p), oper[i] |= 1ll << (p - 1), dan[i][j] = oper[i];
    pres[i] = pres[i - 1] | oper[i];
  }
  if (pres[k] != ((1ll << n) - 1ll)) return puts("REJECTED"), 0;
  puts(solve(1, 0) ? "ACCEPTED" : "REJECTED");
  return 0;
}
