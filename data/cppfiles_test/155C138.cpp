#include <bits/stdc++.h>
using namespace std;
const long long _ = 3e5 + 7;
const double PI = acos(-1);
const long long inf = 0x3f3f3f3f;
const long long INF = (1 << 31) - 1;
const long long MOD = 998244353;
template <typename T>
T rd(T& res) {
  res = 0;
  long long f = 1;
  char ch;
  while ((ch = cin.get()) && (ch < '0' || ch > '9')) {
    f = ch == '-';
  }
  res = ch - 48;
  while ((ch = cin.get()) && ch >= '0' && ch <= '9') {
    res = res * 10 + ch - 48;
  }
  return res * f;
}
long long gcd(long long a, long long b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}
long long ksm(long long a, long long p) {
  long long res = 1;
  while (p) {
    if (p & 1) {
      res *= a;
      res %= MOD;
    }
    p >>= 1;
    a *= a;
    a %= MOD;
  }
  return res;
}
long long Ans[_];
pair<long long, long long> A[_], B[_];
long long cnta, cntb;
char s[_];
void work() {
  long long n;
  cin >> n;
  cnta = cntb = 0;
  for (long long i = 1; i <= n; ++i) cin >> Ans[i];
  cin >> s + 1;
  for (long long i = 1; i <= n; ++i) {
    if (s[i] == '0')
      A[++cnta] = make_pair(Ans[i], i);
    else
      B[++cntb] = make_pair(Ans[i], i);
  }
  sort(A + 1, A + 1 + cnta);
  sort(B + 1, B + 1 + cntb);
  for (long long i = 1; i <= cnta; ++i) {
    Ans[A[i].second] = i;
  }
  for (long long i = 1; i <= cntb; ++i) {
    Ans[B[i].second] = i + cnta;
  }
  for (long long i = 1; i <= n; ++i) cout << Ans[i] << " \n"[i == n];
}
signed main() {
  long long T;
  rd(T);
  for (long long i = 1; i <= T; ++i) {
    work();
  }
}
