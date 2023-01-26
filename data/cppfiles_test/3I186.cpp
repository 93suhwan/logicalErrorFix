#include <bits/stdc++.h>
using namespace std;
const long long N = 1e7 + 1;
const long long OO = 2e18;
const int MOD = 1e9 + 7;
vector<long long> fac(1000001);
inline void CV(vector<long long> v) {
  long long n = v.size();
  for (long long i = 0; i < n; ++i) {
    cout << v[i] << ' ';
  }
}
inline void RV(vector<long long> &v) {
  for (long long i = 0; i < v.size(); ++i) cin >> v[i];
}
inline long long l_ch(long long n) { return n * 2; }
inline long long r_ch(long long n) { return n * 2 + 1; }
inline bool com(long long a, long long b) { return (a > b); }
inline long long fast_ow(long long a, long long b, long long mo) {
  long long ret = 1;
  a %= mo;
  while (b > 0) {
    if (b % 2 == 0) {
      a = (a * a) % mo;
      b /= 2;
      continue;
    }
    ret = (ret * a) % mo;
    --b;
  }
  return ret % mo;
}
inline void fact(vector<long long> &v) {
  v[0] = 1;
  for (long long i = 1; i <= 1000000; ++i) {
    v[i] = (v[i - 1] * i) % MOD;
  }
}
inline long long bas(long long n, long long k) {
  return fac[n] * fast_ow(fac[k], MOD - 2, MOD) % MOD *
         fast_ow(fac[n - k], MOD - 2, MOD) % MOD;
}
inline void add_c(string &s, char x, long long n) {
  while (n--) s += x;
}
inline long long to_num(string s) {
  long long ret = 0, o = fast_ow(10, s.size() - 1, MOD);
  for (long long i = 0; i < s.size(); ++i) {
    ret += (s[i] - '0') * o;
    o /= 10;
  }
  return ret;
}
inline long long max_in_string(string s) {
  long long ret = -OO;
  for (long long i = 0; i < s.size(); ++i)
    ret = max(ret, (long long)(s[i] - '0'));
  return ret;
}
inline string to_string(long long x) {
  string ret;
  while (x > 0) {
    ret += (x % 10) + '0';
    x /= 10;
  }
  reverse(ret.begin(), ret.end());
  return ret;
}
inline void insert_string(string &s, string x, long long ind) {
  string res;
  long long n = s.size();
  for (long long i = 0; i < ind; ++i) res += s[i];
  res += x;
  for (long long i = ind; i < n; ++i) res += s[i];
  s = res;
}
inline bool COO(pair<string, int> a, pair<string, int> b) {
  long long n = a.first.size();
  for (long long i = 0; i < n; ++i) {
    if (a.first[i] != b.first[i]) {
      if (i & 1) return a.first[i] > b.first[i];
      return a.first[i] < b.first[i];
    }
  }
}
int main() {
  string s;
  cin >> s;
  long long n = s.size();
  if (n == 1) {
    if (s[0] == '0')
      cout << '1';
    else
      cout << '0';
    return 0;
  }
  string en;
  for (long long i = n - 1; i >= n - 2; --i) en += s[i];
  reverse(en.begin(), en.end());
  long long numX = 0, num_ = 0;
  for (long long i = 0; i < n; ++i) {
    numX += (s[i] == 'X');
    num_ += (s[i] == '_');
  }
  if (en == "00" || en == "25" || en == "50" || en == "75") {
    if (num_ && numX)
      cout << (num_ * 9) * 9;
    else if (num_)
      cout << (num_ * 9);
    else if (numX)
      cout << '9';
    else
      cout << '1';
    return 0;
  }
  if (en[0] == '_') {
    if (en[1] == '_') {
      num_ -= 2;
      if (num_ == 0) {
        if (numX)
          cout << 4 * 9;
        else
          cout << '4';
        return 0;
      }
      if (numX)
        cout << 4 * (num_ * 9) * 9;
      else
        cout << 4 * (num_ * 9);
      return 0;
    }
    if (en[1] == 'X') {
      --num_;
      if (num_ == 0)
        cout << 4;
      else
        cout << 4 * (num_ * 9);
      return 0;
    }
    if (en[1] != '5' && en[1] != '0') {
      cout << '0';
      return 0;
    }
    --num_;
    if (num_ == 0) {
      if (numX)
        cout << 2 * 9;
      else
        cout << '2';
      return 0;
    } else if (numX)
      cout << 2 * (num_ * 9) * 9;
    else
      cout << 2 * (num_ * 9);
    return 0;
  }
  if (en[0] == 'X') {
    if (en[1] == 'X') {
      if (num_ == 0)
        cout << '1';
      else
        cout << num_ * 9;
      return 0;
    }
    if (en[1] == '_') {
      --num_;
      if (num_ == 0)
        cout << 4;
      else
        cout << 4 * (num_ * 9);
      return 0;
    }
    if (en[1] == '5' || en[1] == '0') {
      if (num_ == 0)
        cout << '2';
      else
        cout << 2 * (num_ * 9);
      return 0;
    }
    cout << '0';
    return 0;
  }
  if (en[0] != '2' && en[0] != '7' && en[0] != '0') {
    cout << '0';
    return 0;
  }
  if (en[1] == '_') {
    --num_;
    if (num_)
      cout << num_ * 9;
    else
      cout << '1';
    return 0;
  }
  if (en[1] == 'X') {
    if (num_)
      cout << num_ * 9;
    else
      cout << '1';
    return 0;
  } else
    cout << '0';
}
