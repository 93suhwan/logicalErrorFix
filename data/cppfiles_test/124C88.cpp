#include <bits/stdc++.h>
using namespace std;
inline long long read() {
  char c = getchar();
  long long first = 0;
  bool f = 0;
  for (; !isdigit(c); c = getchar()) f ^= !(c ^ 45);
  for (; isdigit(c); c = getchar())
    first = (first << 1) + (first << 3) + (c ^ 48);
  if (f) first = -first;
  return first;
}
void ckmax(long long &a, long long b) { a = (a > b ? a : b); }
void ckmin(long long &a, long long b) { a = (a < b ? a : b); }
const long long Mod = 1e9 + 7;
const long long M = 2010;
const long long N = 2000;
long long n, a1[M], a2[M], C[M][M], s1[M], s2[M], s3[M], s4[M];
string S1, S2;
long long calc(long long i, long long a, long long j, long long b) {
  if (a + i - j >= 0 && a + i - j <= a + b)
    return C[a + b][a + i - j];
  else
    return 0;
}
void solve() {
  n = read();
  cin >> S1 >> S2;
  long long res = 0;
  for (long long i = 1; i <= n; i++) {
    a1[i] = S1[i - 1] == '?' ? -1 : S1[i - 1] - '0',
    a2[i] = S2[i - 1] == '?' ? -1 : S2[i - 1] - '0';
    if (a1[i] != -1) a1[i] ^= i & 1;
    if (a2[i] != -1) a2[i] ^= i & 1;
    s1[i] = s1[i - 1] + (a1[i] == -1), s2[i] = s2[i - 1] + (a1[i] == 0),
    s3[i] = s3[i - 1] + (a2[i] == -1), s4[i] = s4[i - 1] + (a2[i] == 0);
  }
  for (long long i = 1; i <= n; i++)
    for (long long j = 1; j <= n; j++) {
      if (a1[i] == 1 || a2[j] == 1) continue;
      res = (res + abs(i - j) *
                       calc(s2[i - 1], s1[i - 1], s4[j - 1], s3[j - 1]) % Mod *
                       calc(s2[n] - s2[i], s1[n] - s1[i], s4[n] - s4[j],
                            s3[n] - s3[j])) %
            Mod;
    }
  printf("%lld\n", res);
}
void init(long long n) {
  for (long long i = 0; i <= n; i++) {
    C[i][0] = 1;
    for (long long j = 1; j <= i; j++)
      C[i][j] = (C[i - 1][j - 1] + C[i - 1][j]) % Mod;
  }
}
signed main() {
  init(2000);
  long long TT = read();
  while (TT--) solve();
  return 0;
}
