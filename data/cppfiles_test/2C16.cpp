#include <bits/stdc++.h>
using namespace std;
long long get_time() {
  return chrono::duration_cast<chrono::nanoseconds>(
             chrono::steady_clock::now().time_since_epoch())
      .count();
}
template <typename T1, typename T2>
string print_iterable(T1 begin_iter, T2 end_iter, int counter) {
  bool done_something = false;
  stringstream res;
  res << "[";
  for (; begin_iter != end_iter and counter; ++begin_iter) {
    done_something = true;
    counter--;
    res << *begin_iter << ", ";
  }
  string str = res.str();
  if (done_something) {
    str.pop_back();
    str.pop_back();
  }
  str += "]";
  return str;
}
template <typename S, typename T>
ostream& operator<<(ostream& out, const pair<S, T>& p) {
  out << "{" << p.first << ", " << p.second << "}";
  return out;
}
template <typename T>
ostream& operator<<(ostream& out, const vector<T>& v) {
  out << "[";
  for (int i = 0; i < (int)v.size(); i++) {
    out << v[i];
    if (i != (int)v.size() - 1) out << ", ";
  }
  out << "]";
  return out;
}
template <class TH>
void _dbg(const char* name, TH val) {
  clog << name << ": " << val << endl;
}
template <class TH, class... TA>
void _dbg(const char* names, TH curr_val, TA... vals) {
  while (*names != ',') clog << *names++;
  clog << ": " << curr_val << ", ";
  _dbg(names + 1, vals...);
}
long long Inverse(long long n, long long m) {
  n %= m;
  if (n <= 1) return n;
  return m - ((m * Inverse(m, n) - 1) / n);
}
long long pow(long long x, long long e, long long mod) {
  long long res = 1;
  for (; e >= 1; e >>= 1) {
    if (e & 1) res = res * x % mod;
    x = x * x % mod;
  }
  return res;
}
struct FastMod {
  unsigned long long mod;
  unsigned long long inv;
  FastMod(unsigned long long mod) : mod(mod), inv(-1ULL / mod) {}
  unsigned long long operator()(unsigned long long x) {
    unsigned long long q = (unsigned long long)((__uint128_t(inv) * x) >> 64);
    unsigned long long r = x - q * mod;
    return r - mod * (r >= mod);
  }
};
struct ModularInteger {
  static int mod;
  static __uint128_t inv_mod;
  int n;
  static void set_mod(int _mod) {
    mod = _mod;
    inv_mod = -1ULL / mod;
  }
  ModularInteger() : n(0) {}
  ModularInteger(long long _n) : n(_n % mod) { n += (n < 0) * mod; }
  long long get() const { return n; }
  static int fast_mod(unsigned long long x) {
    unsigned long long q = (inv_mod * x) >> 64;
    int m = x - q * mod;
    m -= mod * (m >= mod);
    return m;
  }
  ModularInteger operator-() const { return n ? mod - n : 0; }
};
int ModularInteger::mod;
__uint128_t ModularInteger::inv_mod;
ModularInteger operator+(const ModularInteger& A, const ModularInteger& B) {
  ModularInteger C;
  C.n = A.n + B.n;
  C.n -= (C.n >= ModularInteger::mod) * ModularInteger::mod;
  return C;
}
void operator+=(ModularInteger& A, const ModularInteger& B) {
  A.n += B.n;
  A.n -= (A.n >= ModularInteger::mod) * ModularInteger::mod;
}
ModularInteger operator-(const ModularInteger& A, const ModularInteger& B) {
  ModularInteger C;
  C.n = A.n - B.n;
  C.n += (C.n < 0) * ModularInteger::mod;
  return C;
}
void operator-=(ModularInteger& A, const ModularInteger& B) {
  A.n -= B.n;
  A.n += (A.n < 0) * ModularInteger::mod;
}
ModularInteger operator*(const ModularInteger& A, const ModularInteger& B) {
  ModularInteger C;
  C.n = ModularInteger::fast_mod(((unsigned long long)A.n) * B.n);
  return C;
}
void operator*=(ModularInteger& A, const ModularInteger& B) {
  A.n = ModularInteger::fast_mod(((unsigned long long)A.n) * B.n);
}
ModularInteger operator/(const ModularInteger& A, const ModularInteger& B) {
  return A * Inverse(B.n, ModularInteger::mod);
}
void operator/=(ModularInteger& A, const ModularInteger& B) {
  A *= Inverse(B.n, ModularInteger::mod);
}
ModularInteger power(ModularInteger A, unsigned long long e) {
  ModularInteger res = 1;
  for (; e >= 1; e >>= 1) {
    if (e & 1) res *= A;
    A *= A;
  }
  return res;
}
bool operator==(const ModularInteger& A, const ModularInteger& B) {
  return A.n == B.n;
}
bool operator!=(const ModularInteger& A, const ModularInteger& B) {
  return A.n != B.n;
}
bool operator<(const ModularInteger& A, const ModularInteger& B) {
  return A.n < B.n;
}
bool operator>(const ModularInteger& A, const ModularInteger& B) {
  return A.n > B.n;
}
bool operator<=(const ModularInteger& A, const ModularInteger& B) {
  return A.n <= B.n;
}
bool operator>=(const ModularInteger& A, const ModularInteger& B) {
  return A.n >= B.n;
}
ostream& operator<<(ostream& out, const ModularInteger& A) {
  out << A.n;
  return out;
}
istream& operator>>(istream& in, ModularInteger& A) {
  long long a;
  in >> a;
  A = ModularInteger(a);
  return in;
}
int k;
long long f(long long x) {
  x %= k;
  if (x < 0) x += k;
  return x;
}
const int MAXK = 2e5 + 10;
long long cnt[MAXK];
const int MAXL = 20;
long long cnt_sum[MAXK][MAXL];
long long cnt_clever[MAXK];
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  ModularInteger::set_mod(1e9 + 7);
  int n, m;
  cin >> n >> m >> k;
  vector<int> a(n + 1);
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    a[i] = f(a[i] + a[i - 1]);
  }
  long long s = a[n];
  vector<int> se(MAXL);
  se[0] = f(-s);
  for (int e = 1; e < MAXL; e++) se[e] = f(se[e - 1] * 2);
  for (int i = 0; i < n; i++) cnt[a[i]]++;
  for (int i = 0; i < k; i++) cnt_sum[i][0] = cnt[i];
  for (int e = 1; e < MAXL; e++) {
    for (int i = 0; i < k; i++) {
      int j = i + se[e - 1];
      if (j >= k) j -= k;
      cnt_sum[i][e] = cnt_sum[i][e - 1] + cnt_sum[j][e - 1];
    }
  }
  for (int i = 0; i < k; i++) {
    int j = i;
    for (int e = 0; e < MAXL; e++) {
      if ((1 << e) & m) {
        cnt_clever[i] += cnt_sum[j][e];
        j += se[e];
        if (j >= k) j -= k;
      }
    }
    cnt_clever[i] -= cnt[i];
  }
  vector<int> bef(k, 0), aft(k, 0);
  for (int i = 0; i < n; i++) aft[a[i]]++;
  ModularInteger res = 0;
  for (int i = 0; i < n; i++) {
    aft[a[i]]--;
    res += aft[a[i]];
    res += bef[f(a[i] - m * s)];
    res += cnt_clever[a[i]];
    bef[a[i]]++;
  }
  res *= m;
  if (m * s % k == 0) res += 1;
  cout << res << "\n";
}
