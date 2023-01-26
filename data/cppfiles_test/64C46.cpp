#include <bits/stdc++.h>
using namespace std;
mt19937_64 rng(
    (unsigned int)chrono::steady_clock::now().time_since_epoch().count());
long long randomPrime() {
  while (true) {
    long long t = rng() % (int)9e8 + (int)1e8;
    bool ok = true;
    for (int i = 2; 1ll * i * i <= t; ++i)
      if (t % i == 0) {
        ok = false;
        break;
      }
    if (ok) {
      return t;
    }
  }
}
void Z_function(int* z, string& s) {
  int l = 0, r = 0;
  z[0] = s.size();
  for (int i = 1; i < s.size(); ++i) {
    z[i] = (i > r ? 0 : min(z[i - l], r - i + 1));
    while (i + z[i] < s.size() && s[z[i]] == s[i + z[i]]) {
      z[i]++;
    }
    if (i + z[i] - 1 > r) {
      l = i;
      r = i + z[i] - 1;
    }
  }
}
string s, x, ss;
long long mod[5], bas[5];
long long h[700005][5];
long long fac[700005][5];
int z[700005];
long long getHash(int l, int r, int op) {
  long long t =
      (h[r][op] - h[l - 1][op] * fac[r - l + 1][op] % mod[op] + mod[op]) %
      mod[op];
  return t;
}
void check(int l1, int r1, int l2, int r2) {
  bool ok = true;
  for (int i = 0; i < (int)(5); ++i) {
    long long p1 = getHash(l1, r1, i);
    long long p2 = getHash(l2, r2, i);
    long long t = h[x.size() - 1][i];
    if ((p1 + p2) % mod[i] != t) {
      ok = false;
      break;
    }
  }
  if (ok) {
    printf("%d %d\n%d %d\n", l1 - x.size(), r1 - x.size(), l2 - x.size(),
           r2 - x.size());
    exit(0);
  }
}
int main() {
  for (int i = 0; i < (int)(5); ++i) mod[i] = randomPrime();
  for (int i = 0; i < (int)(5); ++i) bas[i] = 10;
  cin >> s >> x;
  ss = x + ":" + s;
  Z_function(z, ss);
  for (int j = 0; j < (int)(5); ++j) {
    h[0][j] = (ss[0] - '0');
    fac[0][j] = 1;
  }
  for (int i = 1; i < ss.size(); ++i)
    for (int j = 0; j < (int)(5); ++j) {
      h[i][j] = (h[i - 1][j] * bas[j] + (ss[i] - '0')) % mod[j];
      fac[i][j] = fac[i - 1][j] * bas[j] % mod[j];
    }
  for (int i = x.size() + 1; i < ss.size(); ++i) {
    if (x.size() > 1 && i - x.size() + 1 > x.size() &&
        i + x.size() - 2 < ss.size()) {
      check(i - x.size() + 1, i - 1, i, i + (x.size() - 1) - 1);
    }
    if (x.size() > 1 && i + (x.size() - 1) * 2 - 1 < ss.size()) {
      check(i, i + (x.size() - 1) - 1, i + (x.size() - 1),
            i + (x.size() - 1) * 2 - 1);
    }
    int lcp = min((int)x.size(), z[i]);
    int need = x.size() - lcp;
    if (need > 1 && i - (need - 1) > x.size() && i + x.size() - 1 < ss.size()) {
      check(i - (need - 1), i - 1, i, i + x.size() - 1);
    }
    if (need > 1 && i + (need - 1) + x.size() - 1 < ss.size()) {
      check(i, i + x.size() - 1, i + x.size(), i + x.size() + (need - 1) - 1);
    }
    if (need > 0 && i - need > x.size() && i + x.size() - 1 < ss.size()) {
      check(i - need, i - 1, i, i + x.size() - 1);
    }
    if (need > 0 && i + need + x.size() - 1 < ss.size()) {
      check(i, i + x.size() - 1, i + x.size(), i + x.size() + need - 1);
    }
  }
  return 0;
}
