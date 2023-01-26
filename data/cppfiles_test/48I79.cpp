#include <bits/stdc++.h>
using namespace std;
template <class T>
void REV(T *a, int n) {
  reverse(a + 1, a + 1 + n);
}
template <class T>
void SRT(T *a, int n) {
  sort(a + 1, a + 1 + n);
}
template <class T>
int UNI(T *a, int n) {
  sort(a + 1, a + 1 + n);
  return unique(a + 1, a + 1 + n) - (a + 1);
}
template <class T>
int POS(T *a, int n, T v) {
  return lower_bound(a + 1, a + 1 + n, v) - a;
}
template <class T>
int fisrtGe(T *a, int n, T v) {
  return lower_bound(a + 1, a + 1 + n, v) - a;
}
template <class T>
int lastLe(T *a, int n, T v) {
  return upper_bound(a + 1, a + 1 + n, v) - a - 1;
}
template <class T>
void _RD(T &x) {
  cin >> x;
}
void _RD(int &x) { scanf("%d", &x); }
void _RD(unsigned int &x) { scanf("%u", &x); }
void _RD(long long &x) { scanf("%lld", &x); }
void _RD(unsigned long long &x) { scanf("%llu", &x); }
void _RD(double &x) { scanf("%lf", &x); }
void _RD(char &x) { scanf(" %c", &x); }
void _RD(char *x) { scanf("%s", x + 1); }
template <class T, class U>
void _RD(pair<T, U> &x) {
  _RD(x.first);
  _RD(x.second);
}
void RD() {}
template <class T, class... U>
void RD(T &head, U &...tail) {
  _RD(head);
  RD(tail...);
}
template <class T>
void RDN(T *a, int n) {
  for (int i = 1; i <= n; ++i) _RD(a[i]);
}
template <class T>
void _WT(const T &x) {
  cout << x;
}
void _WT(const int &x) { printf("%d", x); }
void _WT(const unsigned int &x) { printf("%u", x); }
void _WT(const long long &x) { printf("%lld", x); }
void _WT(const unsigned long long &x) { printf("%llu", x); }
void _WT(const double &x) { printf("%.12f", x); }
void _WT(const char &x) { putchar(x); }
void _WT(const char *x) { printf("%s", x + 1); }
template <class T, class U>
void _WT(const pair<T, U> &x) {
  _WT(x.first);
  putchar(' ');
  _WT(x.second);
}
void WT() {}
template <class T, class... U>
void WT(const T &head, const U &...tail) {
  _WT(head);
  putchar(sizeof...(tail) ? ' ' : '\n');
  WT(tail...);
}
template <class T>
void WTN(T *a, int n) {
  for (int i = 1; i <= n; ++i) {
    _WT(a[i]);
    putchar(" \n"[i == n]);
  }
}
template <class T>
void WTV(const vector<T> &x, bool ln = false) {
  WT(x.size());
  for (auto i = x.begin(); i != x.end(); ++i) {
    _WT(*i);
    putchar(ln ? '\n' : ' ');
  }
  if (!ln) putchar('\n');
}
template <typename T>
void cmin(T &x, T y) {
  if (y < x) x = y;
}
template <typename T>
void cmax(T &x, T y) {
  if (y > x) x = y;
}
unsigned int rnd_seed = chrono::duration_cast<chrono::nanoseconds>(
                            chrono::steady_clock::now().time_since_epoch())
                            .count();
mt19937 rnd(rnd_seed);
const int INF = 0x3F3F3F3F;
const long long LINF = 0x3F3F3F3F3F3F3F3FLL;
int MOD = 998244353;
struct ModularIntegers {
  int num;
  ModularIntegers() { num = 0; }
  template <typename T>
  ModularIntegers(const T &x) {
    long long tmp = x;
    if (tmp >= MOD) {
      if (tmp < (MOD << 1))
        tmp -= MOD;
      else
        tmp %= MOD;
    } else if (tmp < 0) {
      if (tmp >= -MOD)
        tmp += MOD;
      else if (tmp %= MOD)
        tmp += MOD;
    }
    num = tmp;
  }
  friend ModularIntegers operator+(const ModularIntegers &x,
                                   const ModularIntegers &y) {
    return x.num + y.num;
  }
  friend ModularIntegers operator-(const ModularIntegers &x,
                                   const ModularIntegers &y) {
    return x.num - y.num;
  }
  friend ModularIntegers operator*(const ModularIntegers &x,
                                   const ModularIntegers &y) {
    return x.num * y.num;
  }
  friend ModularIntegers operator/(const ModularIntegers &x,
                                   const ModularIntegers &y) {
    return x * y.inv();
  }
  friend bool operator==(const ModularIntegers &x, const ModularIntegers &y) {
    return x.num == y.num;
  }
  friend bool operator!=(const ModularIntegers &x, const ModularIntegers &y) {
    return x.num != y.num;
  }
  ModularIntegers operator+() { return +this->num; }
  ModularIntegers operator-() { return -this->num; }
  ModularIntegers &operator+=(const ModularIntegers &x) {
    if ((this->num += x.num) >= MOD) this->num -= MOD;
    return *this;
  }
  ModularIntegers &operator-=(const ModularIntegers &x) {
    if ((this->num -= x.num) < 0) this->num += MOD;
    return *this;
  }
  ModularIntegers &operator*=(const ModularIntegers &x) {
    this->num = 1LL * this->num * x.num % MOD;
    return *this;
  }
  ModularIntegers &operator/=(const ModularIntegers &x) {
    this->num = ((*this) * x.inv()).num;
    return *this;
  }
  ModularIntegers pow(long long x) const {
    ModularIntegers res(1), cur(this->num);
    for (; x; cur *= cur, x >>= 1)
      if (x & 1) res *= cur;
    return res;
  }
  ModularIntegers inv() const { return pow(MOD - 2); }
  operator int() { return num; }
  operator unsigned int() { return num; }
  operator long long() { return num; }
  operator unsigned long long() { return num; }
};
void _RD(ModularIntegers &x) { scanf("%d", &x.num); }
void _WT(const ModularIntegers &x) { printf("%d", x.num); }
int n, q;
static const int MAXN = 2e5 + 10;
long long a[MAXN];
long long b[MAXN];
struct Block {
  static const int MAXB = MAXN;
  int rt[MAXN];
  long long va[MAXN];
  int lb[MAXB];
  int rb[MAXB];
  long long sm[MAXB];
  long long ZXZ[MAXB];
  long long ZDZ[MAXB];
  long long Sum(int l, int r) {
    long long sum = 0;
    long long zxz = 0;
    long long zdz = 0;
    if (rt[l] == rt[r]) {
      for (int i = l; i <= r; ++i) {
        sum += va[i];
        cmin(zxz, sum);
        cmax(zdz, sum);
        if (zdz > 0) return INF;
      }
    } else {
      for (int i = l; i <= rb[rt[l]]; ++i) {
        sum += va[i];
        cmin(zxz, sum);
        cmax(zdz, sum);
        if (zdz > 0) return INF;
      }
      for (int b = rt[l] + 1; b <= rt[r] - 1; ++b) {
        cmin(zxz, sum + ZXZ[b]);
        cmax(zdz, sum + ZDZ[b]);
        sum += sm[b];
        if (zdz > 0) return INF;
      }
      for (int i = lb[rt[r]]; i <= r; ++i) {
        sum += va[i];
        cmin(zxz, sum);
        cmax(zdz, sum);
        if (zdz > 0) return INF;
      }
    }
    if (zdz > 0) return INF;
    return zxz;
  }
  void Init(int n) {
    int blk = (int)sqrt(n) + 1;
    int cntblk = (n + blk - 1) / blk;
    memset(va, 0LL, sizeof(va[0]) * (n + 1));
    memset(lb, INF, sizeof(lb[0]) * (cntblk + 1));
    memset(rb, -INF, sizeof(rb[0]) * (cntblk + 1));
    memset(sm, 0LL, sizeof(sm[0]) * (cntblk + 1));
    for (int i = 1; i <= n; ++i) {
      rt[i] = (i + blk - 1) / blk;
      lb[rt[i]] = min(lb[rt[i]], i);
      rb[rt[i]] = max(rb[rt[i]], i);
    }
    for (int i = 1; i <= n; ++i) {
      va[i] = a[i] - b[i];
    }
    for (int i = 1; i <= cntblk; ++i) {
      sm[i] = 0;
      ZXZ[i] = LINF;
      ZDZ[i] = -LINF;
      for (int j = lb[i]; j <= rb[i]; ++j) {
        sm[i] += va[j];
        cmin(ZXZ[i], sm[i]);
        cmax(ZDZ[i], sm[i]);
      }
    }
  }
} blk;
void purin_solve() {
  RD(n, q);
  RDN(a, n);
  RDN(b, n);
  blk.Init(n);
  while (q--) {
    int l, r;
    RD(l, r);
    long long ans = -blk.Sum(l, r);
    if (ans < 0) ans = -1LL;
    WT(ans);
  }
}
int main() {
  cout << fixed << setprecision(12);
  cerr << fixed << setprecision(12);
  int t = 1;
  while (t--) purin_solve();
  return 0;
}
