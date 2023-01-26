#include <bits/stdc++.h>
using namespace std;
using ld = long double;
using pi = pair<int, int>;
using pl = pair<long long, long long>;
using pd = pair<ld, ld>;
long long NEG_INF = -1e12;
long long POS_INF = 1e12;
long long MAX = 1e14;
using long long = long long;
using ld = long double;
int mod = 1e9 + 7;
int fast_pow(int a, int p) {
  int res = 1;
  while (p) {
    if (p % 2 == 0) {
      a = a * 1ll * a % mod;
      p /= 2;
    } else {
      res = res * 1ll * a % mod;
      p--;
    }
  }
  return res;
}
int fact(int n) {
  int res = 1;
  for (int i = 1; i <= n; i++) {
    res = res * 1ll * i % mod;
  }
  return res;
}
int C(int n, int k) {
  return fact(n) * 1ll * fast_pow(fact(k), mod - 2) % mod * 1ll *
         fast_pow(fact(n - k), mod - 2) % mod;
}
vector<long long> primeFactors(long long n) {
  vector<long long> facts;
  while (n % 2 == 0) {
    n = n / 2;
    facts.push_back(2);
  }
  for (int i = 3; i <= sqrt(n); i = i + 2) {
    while (n % i == 0) {
      facts.push_back(i);
      n = n / i;
    }
  }
  if (n > 2) facts.push_back(n);
  return facts;
}
long long inv(long long a, long long m) {
  if (a == 1) return 1;
  return inv(m % a, m) * (m - m / a) % m;
}
vector<int> bin(long long n) {
  vector<int> ban;
  long long i;
  ban.push_back(0);
  for (i = 1 << 30; i > 0; i = i / 2) {
    if ((n & i) != 0) {
      ban.push_back(1);
    } else {
      ban.push_back(0);
    }
  }
  return ban;
}
int factorial(long long n) {
  if (n > 1)
    return n * factorial(n - 1);
  else
    return 1;
}
int main() {
  ios_base::sync_with_stdio(0);
  long long n, m, a, h, w, b, x, y, temp, p, out, in, d, k, ans, q;
  long long up, lo, r;
  long long u, v;
  string s, t, left, right;
  cin >> q;
  while (q--) {
    cin >> s >> t;
    long long nr, rem, idx, nl;
    bool flag = false;
    for (int i = 0; i < s.length(); i++) {
      if (flag) break;
      for (int j = 0; j <= s.length(); j++) {
        nl = j;
        nr = t.length() - nl;
        left = "";
        right = "";
        idx = i;
        bool poss = true;
        while (nl) {
          if (idx >= s.length()) {
            poss = false;
            break;
          }
          left += s[idx];
          idx++;
          nl--;
        }
        idx--;
        idx--;
        while (nr) {
          if (idx < 0) {
            poss = false;
            break;
          }
          right += s[idx];
          idx--;
          nr--;
        }
        if (!poss) continue;
        if (left + right == t) {
          flag = true;
          break;
        }
      }
    }
    if (flag)
      cout << "YES" << endl;
    else
      cout << "NO" << endl;
  }
}
