#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1e9 + 7, MOD1 = 998244353, esp = 1e-9, inf = 8e18;
long long mod_pow(long long a, long long b, long long M = MOD) {
  if (a == 0) return 0;
  b %= (M - 1);
  long long res = 1;
  while (b > 0) {
    if (b & 1) res = (res * a) % M;
    a = (a * a) % M;
    b >>= 1;
  }
  return res;
}
void solve(long long tc) {
  long long i, j, k, n, m, l, cnt;
  string s1, s;
  cin >> s1;
  n = s1.length();
  char x;
  if (n == 1 && (s1 == "0" || s1 == "_" || s1 == "X")) {
    cout << "1" << endl;
    return;
  }
  k = 0;
  for (i = 0; i <= 9; i++) {
    x = '0' + i;
    s = s1;
    for (j = 0; j < n; j++) {
      if (s1[j] == 'X') {
        s[j] = x;
      }
    }
    if (s[n - 2] == '2' || s[n - 2] == '_') {
      if (s[n - 1] == '5' || s[n - 1] == '_') {
        if (s[0] != '0')
          cnt = 1;
        else
          cnt = 0;
        for (j = 0; j < n - 2; j++) {
          if (s[j] == '_') {
            if (j == 0) {
              cnt = cnt * 9;
            } else {
              cnt = cnt * 10;
            }
          }
        }
        k += cnt;
      }
    }
    if (s[n - 2] == '7' || s[n - 2] == '_') {
      if (s[n - 1] == '5' || s[n - 1] == '_') {
        if (s[0] != '0')
          cnt = 1;
        else
          cnt = 0;
        for (j = 0; j < n - 2; j++) {
          if (s[j] == '_') {
            if (j == 0) {
              cnt = cnt * 9;
            } else {
              cnt = cnt * 10;
            }
          }
        }
        k += cnt;
      }
    }
    if (s[n - 2] == '5' || s[n - 2] == '_') {
      if (s[n - 1] == '0' || s[n - 1] == '_') {
        if (s[0] != '0')
          cnt = 1;
        else
          cnt = 0;
        for (j = 0; j < n - 2; j++) {
          if (s[j] == '_') {
            if (j == 0) {
              cnt = cnt * 9;
            } else {
              cnt = cnt * 10;
            }
          }
        }
        k += cnt;
      }
    }
    if (s[n - 2] == '0' || s[n - 2] == '_') {
      if (s[n - 1] == '0' || s[n - 1] == '_') {
        if (s[0] != '0')
          cnt = 1;
        else
          cnt = 0;
        for (j = 0; j < n - 2; j++) {
          if (s[j] == '_') {
            if (j == 0) {
              cnt = cnt * 9;
            } else {
              cnt = cnt * 10;
            }
          }
        }
        k += cnt;
      }
    }
  }
  j = 0;
  for (i = 0; i < n; i++) {
    if (s1[i] == 'X') {
      j = 1;
    }
  }
  if (j == 0) {
    if (s1[0] == '_')
      k = k / 9;
    else
      k = k / 10;
  }
  cout << k << endl;
}
signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long t = 1;
  for (long long tc = 1; tc <= t; tc++) {
    solve(tc);
  }
}
