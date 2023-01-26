#include <bits/stdc++.h>
using std::make_pair;
using std::map;
using std::pair;
using std::priority_queue;
using std::reverse;
using std::set;
using std::sort;
using std::string;
using std::swap;
using std::vector;
const int32_t oo = 1e9;
const int64_t ooo = 1e18;
const int io_len = 60000;
char bufforI[io_len + 1];
char* posI = bufforI + io_len - 1;
char* endI = bufforI + io_len - 1;
inline void inci() {
  if (posI == endI) {
    [&] { return fread(bufforI, 1, io_len, stdin); }();
    ;
    posI = bufforI;
  } else
    posI++;
}
inline void skipws() {
  while (*posI <= ' ') inci();
}
template <class INT>
inline void read(INT& a) {
  skipws();
  if (*posI == '-') {
    inci();
    a = -((*posI) - '0');
    inci();
    while (*posI >= '0') {
      a *= 10;
      a -= (*posI) - '0';
      inci();
    }
  } else {
    a = (*posI) - '0';
    inci();
    while (*posI >= '0') {
      a *= 10;
      a += (*posI) - '0';
      inci();
    }
  }
}
inline void read(string& s) {
  s.clear();
  skipws();
  while (*posI > ' ') {
    s.push_back(*posI);
    inci();
  }
}
inline void read(double& d) {
  bool negative = false;
  skipws();
  if (*posI == '-') {
    negative = true;
    inci();
  }
  d = *posI - '0';
  inci();
  while (*posI >= '0') {
    d *= 10;
    d += *posI - '0';
    inci();
  }
  if (*posI == '.') {
    double m = 0.1;
    inci();
    while (*posI >= '0') {
      d += (*posI - '0') * m;
      m *= 0.1;
      inci();
    }
  }
  if (negative) d = -d;
}
template <class S, class T>
inline void read(S& a, T& b) {
  read(a);
  read(b);
}
template <class T>
inline void read(vector<T>& v, int n) {
  v.resize(n);
  for (int i = 0; i < n; i++) read(v[i]);
}
template <class S, class T, class U>
inline void read(S& a, T& b, U& c) {
  read(a);
  read(b);
  read(c);
}
template <class S, class T, class U, class V>
inline void read(S& a, T& b, U& c, V& d) {
  read(a);
  read(b);
  read(c);
  read(d);
}
template <class S, class T, class U, class V, class W>
inline void read(S& a, T& b, U& c, V& d, W& e) {
  read(a);
  read(b);
  read(c);
  read(d);
  read(e);
}
template <class T>
T maximum(T a, T b) {
  if (a > b) return a;
  return b;
}
template <class T>
T minimum(T a, T b) {
  if (a < b) return a;
  return b;
}
template <class T>
T sum(T a, T b) {
  return a + b;
}
template <class T>
T mult(T a, T b) {
  return a * b;
}
template <class T>
T exclusive_or(T a, T b) {
  return a ^ b;
}
template <class INT>
inline bool is_power_of_2(INT num) {
  return num && !(num & (num - 1));
}
template <class INT>
inline int power_of_2_no_less_then(INT num) {
  int n = 0;
  while (num > (INT(1) << n)) n++;
  return n;
}
template <class INT>
inline bool is_set(INT mask, int pos) {
  return (mask & (INT(1) << pos));
}
template <class INT>
inline INT mask_set(INT mask, int pos) {
  return mask | (INT(1) << pos);
}
template <class INT>
inline INT mask_unset(INT mask, int pos) {
  return mask & (~(INT(1) << pos));
}
template <class T>
void sos_dp(vector<T>& S, T f(T, T)) {
  ;
  int n = power_of_2_no_less_then(S.size());
  for (int j = 1; j < n + 1; j++)
    for (int mask = (1 << n) - 1; mask >= 0; mask--)
      if (is_set(mask, j - 1)) S[mask] = f(S[mask], S[mask_unset(mask, j - 1)]);
}
template <class T>
void rev_sos_dp(vector<T>& S, T f(T, T)) {
  ;
  int n = power_of_2_no_less_then(S.size());
  for (int j = n; j > 0; j--)
    for (int mask = 0; mask < (1 << n); mask++)
      if (is_set(mask, j - 1)) S[mask] = f(S[mask], S[mask_unset(mask, j - 1)]);
}
template <class T>
struct int_mod {
  T val;
  static T modulo;
  int_mod() : val(0) {}
  int_mod(int n) : val(n % modulo) {}
  operator T() const { return val; }
  int_mod<T>& operator+=(const int_mod<T> a) {
    val += a.val;
    if (val >= modulo) val -= modulo;
    return *this;
  }
  int_mod<T>& operator-=(const int_mod<T> a) {
    val += modulo - a.val;
    if (val >= modulo) val -= modulo;
    return *this;
  }
  int_mod<T>& operator*=(const int_mod<T> a) {
    val = (val * a.val) % modulo;
    return *this;
  }
};
template <class T>
T int_mod<T>::modulo = 0;
template <class T>
inline int_mod<T> operator+(const int_mod<T>& a, const int_mod<T>& b) {
  int_mod<T> res;
  res.val = a.val + b.val;
  if (res.val >= int_mod<T>::modulo) res.val -= int_mod<T>::modulo;
  return res;
}
template <class T>
inline int_mod<T> operator-(const int_mod<T>& a, const int_mod<T>& b) {
  int_mod<T> res;
  res.val = a.val - b.val + int_mod<T>::modulo;
  if (res.val >= int_mod<T>::modulo) res.val -= int_mod<T>::modulo;
  return res;
}
template <class T>
inline int_mod<T> operator*(const int_mod<T>& a, const int_mod<T>& b) {
  int_mod<T> res;
  res.val = (a.val * b.val) % int_mod<T>::modulo;
  return res;
}
template <typename T>
T min(std::initializer_list<T> l) {
  const T* it = l.begin();
  const T* end = l.end();
  ;
  T answer = *it;
  it++;
  while (it != end) {
    if (*it < answer) answer = *it;
    it++;
  }
  return answer;
}
template <typename T>
T max(std::initializer_list<T> l) {
  const T* it = l.begin();
  const T* end = l.end();
  ;
  T answer = *it;
  it++;
  while (it != end) {
    if (*it > answer) answer = *it;
    it++;
  }
  return answer;
}
int n;
vector<string> vs;
int lcount[23][26];
int lminimum[1 << 23][26];
vector<int_mod<int>> H;
int_mod<int> sub(int_mod<int> a, int_mod<int> b) { return a - b; }
void rev_bits(vector<int_mod<int>>& H) {
  for (int i = 0; i < (1 << (n - 1)); i++) swap(H[i], H[i ^ ((1 << n) - 1)]);
}
int main() {
  int_mod<int>::modulo = 998244353;
  read(n);
  read(vs, n);
  for (int i = 0; i < n; i++)
    for (char c : vs[i]) lcount[i][c - 'a']++;
  for (int i = 1; i < (1 << n); i++) {
    if (is_power_of_2(i))
      for (int j = 0; j < 26; j++)
        lminimum[i][j] = lcount[power_of_2_no_less_then(i)][j];
    else {
      int without_last_bit = i & (i - 1);
      int last_bit = i - without_last_bit;
      for (int j = 0; j < 26; j++)
        lminimum[i][j] =
            min({lminimum[without_last_bit][j], lminimum[last_bit][j]});
    }
  }
  H.resize(1 << n);
  for (int i = 0; i < (1 << n); i++) {
    H[i] = 1;
    for (int j = 0; j < 26; j++) H[i] *= (1 + lminimum[i][j]);
  }
  rev_bits(H);
  rev_sos_dp(H, sub);
  rev_bits(H);
  H[0] = 0;
  ;
  sos_dp(H, sum);
  ;
  int result = 0;
  for (int i = 0; i < (1 << n); i++) {
    int k = 0;
    int sumind = 0;
    int ci = i;
    while (ci > 0) {
      int last_bit = ci - (ci & (ci - 1));
      k++;
      sumind += power_of_2_no_less_then(last_bit) + 1;
      ci = (ci & (ci - 1));
    };
    ;
    ;
    ;
    result =
        result ^ (int(H[(1 << n) - 1] - H[((1 << n) - 1) ^ i]) * k * sumind);
  }
  printf("%d\n", result);
  return 0;
}
