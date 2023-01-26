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
long long ans = 0;
vector<long long> v;
inline void GO_DIV(string s, long long index) {
  if (index == v.size()) {
    long long x = to_num(s);
    ans += (x % 25 == 0);
    return;
  }
  if (v[index] == 0) {
    for (long long i = 1; i <= 9; ++i) {
      s[v[index]] = (i + '0');
      GO_DIV(s, index + 1);
    }
    return;
  }
  for (long long i = 0; i <= 9; ++i) {
    s[v[index]] = (i + '0');
    GO_DIV(s, index + 1);
  }
}
int main() {
  string s;
  cin >> s;
  long long n = s.size();
  long long num_ = 0, numX = 0;
  for (long long i = 0; i < n; ++i) {
    num_ += (s[i] == '_');
    numX += (s[i] == 'X');
  }
  if (num_ == n) {
    if (num_ == 1) {
      cout << num_;
      return 0;
    } else if (num_ == 2) {
      cout << num_ + 1;
      return 0;
    } else if (num_ == 3) {
      cout << num_ * 12;
      return 0;
    }
    num_ -= 3;
    long long out = fast_ow(10, num_, MOD);
    cout << 36 * out;
    return 0;
  }
  if (n > 1 && s[0] == '0') {
    cout << '0';
    return 0;
  }
  if (s == "X" || s == "_") {
    cout << '1';
    return 0;
  }
  string s1 = s;
  long long is = -1;
  for (long long i = 0; i < n; ++i) {
    if (s[i] == '_') v.push_back(i);
  }
  for (long long i = 0; i < n; ++i) {
    if (s[i] == 'X') {
      is = i;
      break;
    }
  }
  if (is == -1) {
    GO_DIV(s, 0);
    cout << ans;
    return 0;
  }
  if (is == 0) {
    for (long long i = 1; i <= 9; ++i) {
      for (long long j = 0; j < n; ++j) {
        if (s1[j] == 'X') s1[j] = (i + '0');
      }
      GO_DIV(s1, 0);
      s1 = s;
    }
    cout << ans;
    return 0;
  }
  for (long long i = 0; i <= 9; ++i) {
    for (long long j = 0; j < n; ++j) {
      if (s1[j] == 'X') s1[j] = (i + '0');
    }
    GO_DIV(s1, 0);
    s1 = s;
  }
  cout << ans;
}
