#include <bits/stdc++.h>
using namespace std;
template <class A>
void rd(vector<A> &v);
template <class T>
void rd(T &x) {
  cin >> x;
}
template <class H, class... T>
void rd(H &h, T &...t) {
  rd(h);
  rd(t...);
}
template <class A>
void rd(vector<A> &x) {
  for (auto &a : x) rd(a);
}
template <class T, class H>
bool ckmin(T &a, const T b) {
  return b < a ? a = b, 1 : 0;
}
template <class T, class H>
bool ckmax(T &a, const T b) {
  return a < b ? a = b, 1 : 0;
}
template <typename T>
void __p(T a) {
  cout << a;
}
template <typename T, typename F>
void __p(pair<T, F> a) {
  cout << "{";
  __p(a.first);
  cout << ",";
  __p(a.second);
  cout << "}\n";
}
template <typename T>
void __p(std::vector<T> a) {
  cout << "{";
  for (auto it = a.begin(); it < a.end(); it++)
    __p(*it), cout << ",}\n"[it + 1 == a.end()];
}
template <typename T, typename... Arg>
void __p(T a1, Arg... a) {
  __p(a1);
  __p(a...);
}
template <typename Arg1>
void __f(const char *name, Arg1 &&arg1) {
  cout << name << " : ";
  __p(arg1);
  cout << "\n";
}
template <typename Arg1, typename... Args>
void __f(const char *names, Arg1 &&arg1, Args &&...args) {
  int bracket = 0, i = 0;
  for (;; i++)
    if (names[i] == ',' && bracket == 0)
      break;
    else if (names[i] == '(')
      bracket++;
    else if (names[i] == ')')
      bracket--;
  const char *comma = names + i;
  cout.write(names, comma - names) << " : ";
  __p(arg1);
  cout << " | ";
  __f(comma + 1, args...);
}
void setIO(string s = "") {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin.exceptions(cin.failbit);
  cout.precision(15);
  cout << fixed;
  if (((int)(s).size())) {
    freopen((s + ".in").c_str(), "r", stdin);
    freopen((s + ".out").c_str(), "w", stdout);
  }
}
template <const int &MOD>
struct _m_int {
  int val;
  _m_int(int64_t v = 0) {
    if (v < 0) v = v % MOD + MOD;
    if (v >= MOD) v %= MOD;
    val = v;
  }
  static int inv_mod(int a, int m = MOD) {
    int g = m, r = a, x = 0, y = 1;
    while (r != 0) {
      int q = g / r;
      g %= r;
      swap(g, r);
      x -= q * y;
      swap(x, y);
    }
    return x < 0 ? x + m : x;
  }
  explicit operator int() const { return val; }
  explicit operator int64_t() const { return val; }
  _m_int &operator+=(const _m_int &other) {
    val -= MOD - other.val;
    if (val < 0) val += MOD;
    return *this;
  }
  _m_int &operator-=(const _m_int &other) {
    val -= other.val;
    if (val < 0) val += MOD;
    return *this;
  }
  static unsigned fast_mod(uint64_t x, unsigned m = MOD) {
    return x % m;
    unsigned x_high = x >> 32, x_low = (unsigned)x;
    unsigned quot, rem;
    asm("divl %4\n" : "=a"(quot), "=d"(rem) : "d"(x_high), "a"(x_low), "r"(m));
    return rem;
  }
  _m_int &operator*=(const _m_int &other) {
    val = fast_mod((uint64_t)val * other.val);
    return *this;
  }
  _m_int &operator/=(const _m_int &other) { return *this *= other.inv(); }
  friend _m_int operator+(const _m_int &a, const _m_int &b) {
    return _m_int(a) += b;
  }
  friend _m_int operator-(const _m_int &a, const _m_int &b) {
    return _m_int(a) -= b;
  }
  friend _m_int operator*(const _m_int &a, const _m_int &b) {
    return _m_int(a) *= b;
  }
  friend _m_int operator/(const _m_int &a, const _m_int &b) {
    return _m_int(a) /= b;
  }
  _m_int &operator++() {
    val = val == MOD - 1 ? 0 : val + 1;
    return *this;
  }
  _m_int &operator--() {
    val = val == 0 ? MOD - 1 : val - 1;
    return *this;
  }
  _m_int operator++(int) {
    _m_int before = *this;
    ++*this;
    return before;
  }
  _m_int operator--(int) {
    _m_int before = *this;
    --*this;
    return before;
  }
  _m_int operator-() const { return val == 0 ? 0 : MOD - val; }
  bool operator==(const _m_int &other) const { return val == other.val; }
  bool operator!=(const _m_int &other) const { return val != other.val; }
  _m_int inv() const { return inv_mod(val); }
  _m_int pow(int64_t p) const {
    if (p < 0) return inv().pow(-p);
    _m_int a = *this, result = 1;
    while (p > 0) {
      if (p & 1) result *= a;
      a *= a;
      p >>= 1;
    }
    return result;
  }
  friend ostream &operator<<(ostream &os, const _m_int &m) {
    return os << m.val;
  }
};
const int MOD = 998244353;
using mint = _m_int<MOD>;
signed main() {
  setIO();
  int n;
  rd(n);
  vector<int> a(n);
  rd(a);
  stack<tuple<int, mint, int, mint>> st;
  st.push(tuple<int, mint, int, mint>{0, 1, a[0], 0});
  mint total = a[0];
  for (int i = 1; i < n; ++i) {
    mint to_delete = 0, help = total;
    while (!st.empty() && a[get<0>(st.top())] >= a[i]) {
      auto [j, sum, cnt, delta] = st.top();
      st.pop();
      help -= sum * cnt;
      to_delete = sum;
      if (!st.empty()) {
        get<1>(st.top()) =
            sum + (i % 2 == j % 2 ? get<1>(st.top()) : -get<1>(st.top())) +
            (i % 2 == j % 2 ? -delta : delta);
      }
    }
    int _cnt = (st.empty() ? int(0) : a[get<0>(st.top())]);
    mint sum = total - to_delete, cnt = a[i] - _cnt;
    st.push(tuple<int, mint, int, mint>{i, sum, cnt, to_delete});
    total = _cnt * total - help + cnt * sum;
  }
  cout << total;
}
