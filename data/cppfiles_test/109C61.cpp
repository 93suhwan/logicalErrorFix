#include <bits/stdc++.h>
using namespace std;
const double pi =
    3.141592653589793238462643383279502884197169399375105820974944592307816406286208998628034825342;
void fast_io() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
}
long long modPow(long long a, long long x, long long p) {
  long long res = 1;
  while (x > 0) {
    if (x & 1) res = (res * a) % p;
    a = (a * a) % p;
    x >>= 1;
  }
  return res;
}
long long modInverse(long long a, long long p) { return modPow(a, p - 2, p); }
const int MR = 2e5 + 10;
const int MOD = 998244353;
int sil[MR];
char s[10];
int main() {
  fast_io();
  sil[0] = 1;
  for (int i = (1); i < (MR); ++i) sil[i] = i * (long long)sil[i - 1] % MOD;
  int n;
  scanf("%d", &n);
  int w = 0, q = 0;
  int bad = 1;
  bool allWB = 1, allBW = 1;
  for (int i = 0; i < (n); ++i) {
    scanf("%s", s);
    for (int j = 0; j < (2); ++j)
      if (s[j] == 'W')
        w++;
      else if (s[j] == '?')
        q++;
    if (s[0] == 'B' && s[1] == 'B') {
      bad = 0;
      allWB = 0;
      allBW = 0;
    } else if (s[0] == 'W' && s[1] == 'W') {
      bad = 0;
      allWB = 0;
      allBW = 0;
    } else {
      int qs = 0;
      for (int j = 0; j < (2); ++j)
        if (s[j] == '?') qs++;
      if (qs == 2) bad = bad * 2 % MOD;
      if (s[0] == 'B' || s[1] == 'W') allWB = 0;
      if (s[0] == 'W' || s[1] == 'B') allBW = 0;
    }
  }
  int b = 2 * n - q - w;
  if (w > n || b > n) {
    printf("0\n");
    return 0;
  }
  printf("% d\n", (sil[q] * modInverse(sil[n - w], MOD) % MOD *
                       modInverse(sil[q - n + w], MOD) % MOD -
                   bad + allBW + allWB + MOD) %
                      MOD);
  return 0;
}
