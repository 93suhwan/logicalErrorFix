#include <bits/stdc++.h>
using namespace std;
template <class L, class R>
ostream &operator<<(ostream &os, map<L, R> P) {
  for (auto const &vv : P) os << "(" << vv.first << "," << vv.second << ")";
  return os;
}
template <class T>
ostream &operator<<(ostream &os, set<T> V) {
  os << "[";
  for (auto const &vv : V) os << vv << ",";
  os << "]";
  return os;
}
template <class T>
ostream &operator<<(ostream &os, vector<T> V) {
  os << "[";
  for (auto const &vv : V) os << vv << ",";
  os << "]";
  return os;
}
template <class L, class R>
ostream &operator<<(ostream &os, pair<L, R> P) {
  os << "(" << P.first << "," << P.second << ")";
  return os;
}
inline int fstoi(const string &str) {
  auto it = str.begin();
  bool neg = 0;
  int num = 0;
  if (*it == '-')
    neg = 1;
  else
    num = *it - '0';
  ++it;
  while (it < str.end()) num = num * 10 + (*it++ - '0');
  if (neg) num *= -1;
  return num;
}
inline void getch(char &x) {
  while (x = getchar_unlocked(), x < 33) {
    ;
  }
}
inline void getstr(string &str) {
  str.clear();
  char cur;
  while (cur = getchar_unlocked(), cur < 33) {
    ;
  }
  while (cur > 32) {
    str += cur;
    cur = getchar_unlocked();
  }
}
template <typename T>
inline bool sc(T &num) {
  bool neg = 0;
  int c;
  num = 0;
  while (c = getchar_unlocked(), c < 33) {
    if (c == EOF) return false;
  }
  if (c == '-') {
    neg = 1;
    c = getchar_unlocked();
  }
  for (; c > 47; c = getchar_unlocked()) num = num * 10 + c - 48;
  if (neg) num *= -1;
  return true;
}
template <typename T, typename... Args>
inline void sc(T &num, Args &...args) {
  bool neg = 0;
  int c;
  num = 0;
  while (c = getchar_unlocked(), c < 33) {
    ;
  }
  if (c == '-') {
    neg = 1;
    c = getchar_unlocked();
  }
  for (; c > 47; c = getchar_unlocked()) num = num * 10 + c - 48;
  if (neg) num *= -1;
  sc(args...);
}
constexpr int64_t mod = 1e9 + 7;
int64_t fac[2000001];
int64_t facinv[2000001];
void pre() {
  fac[0] = 1;
  for (int i = (1); i < int((2000001)); ++i) fac[i] = fac[i - 1] * i % mod;
  facinv[2000001 - 1] = 407182070;
  for (int i = 2000001 - 2; i >= 0; --i)
    facinv[i] = facinv[i + 1] * (i + 1) % mod;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  pre();
  int64_t n;
  sc(n);
  int64_t a[n];
  for (auto &i : (a)) sc(i);
  int64_t res = 0;
  int64_t dp[1 << n];
  int64_t dp2[1 << n];
  int bits[32], othbits[32];
  for (int i = (1); i < int((1 << n)); ++i) {
    ;
    int crm = (i - 1) & i;
    dp[i] = 0;
    crm = (i - 1) & i;
    for (; crm;) {
      int64_t comp[14];
      memset(comp, -1, 14 << 3);
      int64_t cr = 1;
      int tcrm = crm;
      while (tcrm) {
        int x = 31 - __builtin_clz(tcrm);
        tcrm ^= 1 << x;
        if (true) {
          if (comp[x] == -1) {
            comp[x] = 1;
            int tmpoth = crm ^ i;
            while (tmpoth) {
              int j = 31 - __builtin_clz(tmpoth);
              tmpoth ^= 1 << j;
              if (true) {
                comp[x] *= (int64_t)(a[x]) * facinv[a[x] + a[j]] % mod *
                           fac[a[x] + a[j] - 1] % mod;
                comp[x] %= mod;
              }
            }
          }
          cr *= comp[x];
          cr %= mod;
        }
      };
      ;
      cr *= 1 - dp[crm];
      cr %= mod;
      dp[i] += cr;
      dp[i] %= mod;
      ;
      if (i == ((1 << n) - 1)) {
        ;
        ;
        res += (int64_t)__builtin_popcount(crm) * cr;
        res %= mod;
      }
      crm = (crm - 1) & i;
    }
  };
  ;
  ;
  res += (int64_t)n * (1 - dp[(1 << n) - 1]);
  res %= mod;
  res += mod;
  res %= mod;
  cout << res << '\n';
}
