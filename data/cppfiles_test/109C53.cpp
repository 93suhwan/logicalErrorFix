#include <bits/stdc++.h>
#pragma GCC target("avx2")
#pragma GCC optimization("O3")
#pragma GCC optimization("unroll-loops")
using namespace std;
template <class T1, class T2>
ostream &operator<<(ostream &os, const pair<T1, T2> &p) {
  os << "{" << p.first << "," << p.second << "}";
  return os;
}
const int N = 1e6 + 5;
const long long oo = 998244353;
long long fact[N];
long long fact_inv[N];
long long extended_euclidean(long long a, long long b, long long &x,
                             long long &y) {
  if (a == 0) {
    x = 0;
    y = 1;
    return b;
  }
  long long x1, y1;
  long long d = extended_euclidean(b % a, a, x1, y1);
  x = y1 - (b / a) * x1;
  y = x1;
  return d;
}
long long mod_inverse(long long a, long long m) {
  long long x, y;
  long long g = extended_euclidean(a, m, x, y);
  if (g != 1) {
    cout << "No solution!";
    return -1;
  } else {
    x = (x % m + m) % m;
    return x;
  }
}
long long ncr(int n, int r) {
  return n < r ? 0
               : ((1LL * fact[n] % oo * fact_inv[r] % oo) % oo *
                  fact_inv[n - r]) %
                     oo;
}
void pre(int N) {
  fact[0] = 1;
  for (long long i = 1; i < N; i++) {
    fact[i] = (i * fact[i - 1]) % oo;
  }
  fact_inv[N - 1] = mod_inverse(fact[N - 1], oo);
  for (long long i = N - 2; i >= 0; i--) {
    fact_inv[i] = (i + 1LL) * fact_inv[i + 1] % oo;
  }
}
long long bigmod(long long a, long long p, long long m) {
  long long res = 1;
  long long x = a;
  while (p) {
    if (p & 1) {
      res = (res * x) % m;
    }
    x = (x * x) % m;
    p = p >> 1;
  }
  return res;
}
int32_t main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  pre(N);
  int n;
  cin >> n;
  int a = 0, b = 0;
  int totww = 0, totwb = 0;
  int totbb = 0, totbw = 0;
  int tot__ = 0;
  while (n--) {
    string s;
    cin >> s;
    if (s == "WW")
      a++;
    else if (s == "W?" or s == "?W")
      b++;
    else if (s == "B?" or s == "?B")
      a--, b++;
    else if (s == "BB")
      a--;
    else if (s == "??")
      b += 2, a--;
    totww += s == "WW";
    totwb += s == "W?";
    totwb += s == "WB";
    totwb += s == "?B";
    totbb += s == "BB";
    totbw += s == "B?";
    totbw += s == "BW";
    totbw += s == "?W";
    tot__ += s == "??";
  }
  a = -a;
  long long ans = 0;
  if (a <= b and a >= 0) {
    ans = ncr(b, a);
    if (totww == 0 and totbb == 0) {
      long long x = bigmod(2, tot__, oo);
      ans = (ans - x + oo) % oo;
      ans += totbw == 0;
      ans += totwb == 0;
    }
  }
  ans = (ans + oo) % oo;
  cout << ans << endl;
  return 0;
}
