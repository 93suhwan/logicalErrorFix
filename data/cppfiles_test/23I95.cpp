#include <bits/stdc++.h>
using namespace std;
const int inf = (int)1.01e9;
const long long infll = (long long)1.01e18;
const long double eps = 1e-9;
const long double pi = acos((long double)-1);
mt19937 mrand(chrono::steady_clock::now().time_since_epoch().count());
int rnd(int x) { return mrand() % x; }
const int mod = 998244353;
int mul(int a, int b) { return (long long)a * b % mod; }
void add(int &a, int b) {
  a += b;
  if (a >= mod) {
    a -= mod;
  }
}
const int maxn = 105;
int f[maxn];
void precalc() {
  f[0] = 1;
  for (int i = 1; i < maxn; ++i) {
    f[i] = mul(f[i - 1], i);
  }
}
int n, m;
bitset<maxn> s[maxn];
bool read() {
  if (scanf("%d%d", &n, &m) < 2) {
    return false;
  }
  for (int i = 0; i < m; ++i) {
    int k;
    scanf("%d", &k);
    s[i].reset();
    for (int j = 0; j < k; ++j) {
      int x;
      scanf("%d", &x);
      --x;
      s[i][x] = true;
    }
  }
  return true;
}
int used[maxn];
int curu;
int rec(bitset<maxn> a) {
  int res = 1;
  int cs = 0;
  for (int i = 0; i < m; ++i) {
    if ((s[i] & a) != s[i] || s[i] == a) {
      continue;
    }
    bool ok = true;
    for (int j = 0; j < m; ++j) {
      if (j == i || (s[j] & a) != s[j] || s[j] == a) {
        continue;
      }
      if ((s[i] & s[j]) == s[i]) {
        ok = false;
        break;
      }
    }
    if (!ok) {
      continue;
    }
    vector<bitset<maxn>> b;
    b.push_back(s[i]);
    bitset<maxn> all = s[i];
    ++curu;
    used[i] = curu;
    while (true) {
      bool found = false;
      for (int j = 0; j < m; ++j) {
        if (used[j] == curu || (s[j] & a) != s[j] || s[j] == a) {
          continue;
        }
        if (!(s[j] & all).any()) {
          continue;
        }
        bool bad = false;
        int l = -1;
        for (int k = 0; k < ((int)(b).size()); ++k) {
          if ((s[j] & b[k]) == s[j]) {
            bad = true;
            break;
          }
          if ((s[j] & b[k]).any()) {
            l = k;
            break;
          }
        }
        if (bad) {
          continue;
        }
        int r = l + 1;
        while (r < ((int)(b).size()) && (s[j] & b[r]).any()) {
          ++r;
        }
        for (int k = r + 1; k < ((int)(b).size()); ++k) {
          if ((s[j] & b[r]).any()) {
            return 0;
          }
        }
        if ((all & s[j]) != s[j]) {
          bitset<maxn> add = (s[j] & ~all);
          if (l == 0) {
            b.insert(b.begin(), add);
            ++r;
          } else if (r == ((int)(b).size())) {
            b.push_back(add);
            ++r;
          } else {
            return 0;
          }
          all |= s[j];
        }
        if ((b[l] & s[j]) != b[l]) {
          bitset<maxn> add = (b[l] & s[j]);
          b[l] ^= add;
          b.insert(b.begin() + l + 1, add);
          ++l;
          ++r;
        }
        --r;
        if ((b[r] & s[j]) != b[r]) {
          bitset<maxn> add = (b[r] & s[j]);
          b[r] ^= add;
          b.insert(b.begin() + r, add);
        }
        ++r;
        bitset<maxn> x;
        x.reset();
        for (int k = l; k < r; ++k) {
          if ((b[k] & s[j]) != b[k]) {
            return 0;
          }
          x |= b[k];
        }
        if (x != s[j]) {
          return 0;
        }
        used[j] = curu;
        found = true;
      }
      if (!found) {
        break;
      }
    }
    if (((int)(b).size()) > 1) {
      res = mul(res, 2);
    }
    for (int i = 0; i < ((int)(b).size()); ++i) {
      res = mul(res, rec(b[i]));
    }
    ++cs;
    a ^= all;
  }
  res = mul(res, f[cs + a.count()]);
  return res;
}
void solve() {
  {
    int mm = 0;
    for (int i = 0; i < m; ++i) {
      bool ok = true;
      for (int j = 0; j < mm; ++j) {
        if (s[i] == s[j]) {
          ok = false;
          break;
        }
      }
      if (ok) {
        s[mm++] = s[i];
      }
    }
    m = mm;
  }
  bitset<maxn> all;
  all.reset();
  for (int i = 0; i < n; ++i) {
    all[i] = true;
  }
  printf("%d\n", rec(all));
}
int main() {
  precalc();
  while (read()) {
    solve();
  }
  return 0;
}
