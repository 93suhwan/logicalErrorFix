#include <bits/stdc++.h>
using namespace std;
template <typename T>
istream &operator>>(istream &is, vector<T> &vec) {
  for (auto &v : vec) is >> v;
  return is;
}
template <typename T>
ostream &operator<<(ostream &os, const vector<T> &vec) {
  os << "[";
  for (auto v : vec) os << v << ",";
  os << "]";
  return os;
}
template <typename T>
ostream &operator<<(ostream &os, const deque<T> &vec) {
  os << "deq[";
  for (auto v : vec) os << v << ",";
  os << "]";
  return os;
}
template <typename T>
ostream &operator<<(ostream &os, const set<T> &vec) {
  os << "{";
  for (auto v : vec) os << v << ",";
  os << "}";
  return os;
}
template <typename T>
ostream &operator<<(ostream &os, const multiset<T> &vec) {
  os << "{";
  for (auto v : vec) os << v << ",";
  os << "}";
  return os;
}
template <typename T>
ostream &operator<<(ostream &os, const unordered_set<T> &vec) {
  os << "{";
  for (auto v : vec) os << v << ",";
  os << "}";
  return os;
}
template <typename T>
ostream &operator<<(ostream &os, const unordered_multiset<T> &vec) {
  os << "{";
  for (auto v : vec) os << v << ",";
  os << "}";
  return os;
}
template <typename TK, typename TV>
ostream &operator<<(ostream &os, const unordered_map<TK, TV> &mp) {
  os << "{";
  for (auto v : mp) os << v.first << "=>" << v.second << ",";
  os << "}";
  return os;
}
template <typename T1, typename T2>
ostream &operator<<(ostream &os, const pair<T1, T2> &pa) {
  os << "(" << pa.first << "," << pa.second << ")";
  return os;
}
template <typename TK, typename TV>
ostream &operator<<(ostream &os, const map<TK, TV> &mp) {
  os << "{";
  for (auto v : mp) os << v.first << "=>" << v.second << ",";
  os << "}";
  return os;
}
template <typename T>
void resize_array(vector<T> &vec, int len) {
  vec.resize(len);
}
template <typename T, typename... Args>
void resize_array(vector<T> &vec, int len, Args... args) {
  vec.resize(len);
  for (auto &v : vec) resize_array(v, args...);
}
template <typename T1, typename T2>
pair<T1, T2> operator+(const pair<T1, T2> &l, const pair<T1, T2> &r) {
  return make_pair(l.first + r.first, l.second + r.second);
}
template <typename T1, typename T2>
pair<T1, T2> operator-(const pair<T1, T2> &l, const pair<T1, T2> &r) {
  return make_pair(l.first - r.first, l.second - r.second);
}
long long gcd(long long a, long long b) { return b ? gcd(b, a % b) : a; }
mt19937 mrand(random_device{}());
int rnd(int x) { return mrand() % x; }
template <unsigned int MOD>
class ModInt {
 public:
  ModInt(unsigned long long _v = 0) { set_v((_v % MOD + MOD)); }
  explicit operator bool() const { return val != 0; }
  ModInt operator-() const { return ModInt() - *this; }
  ModInt operator+(const ModInt &r) const {
    return ModInt().set_v(val + r.val);
  }
  ModInt operator-(const ModInt &r) const {
    return ModInt().set_v(val + MOD - r.val);
  }
  ModInt operator*(const ModInt &r) const {
    return ModInt().set_v(
        (unsigned int)((unsigned long long)(val)*r.val % MOD));
  }
  ModInt operator/(const ModInt &r) const { return *this * r.inv(); }
  ModInt &operator+=(const ModInt &r) { return *this = *this + r; }
  ModInt &operator-=(const ModInt &r) { return *this = *this - r; }
  ModInt &operator*=(const ModInt &r) { return *this = *this * r; }
  ModInt &operator/=(const ModInt &r) { return *this = *this / r; }
  unsigned int operator=(unsigned long long _v) {
    set_v((_v % MOD + MOD));
    return val;
  }
  bool operator==(const ModInt &r) const { return val == r.val; }
  bool operator!=(const ModInt &r) const { return val != r.val; }
  ModInt pow(long long n) const {
    ModInt x = *this, r = 1;
    while (n) {
      if (n & 1) r *= x;
      x *= x;
      n >>= 1;
    }
    return r;
  }
  ModInt inv() const { return pow(MOD - 2); }
  friend ostream &operator<<(ostream &os, const ModInt &r) {
    return os << r.val;
  }
  friend istream &operator>>(istream &is, ModInt &r) { return is >> r.val; }

 private:
  unsigned int val;
  ModInt &set_v(unsigned int _v) {
    val = (_v < MOD) ? _v : _v - MOD;
    return *this;
  }
};
constexpr unsigned int mod = 998244353;
using Mint = ModInt<mod>;
class PrimeUtil {
 public:
  PrimeUtil(int n) {
    _is_prime.resize(n + 1, 0);
    vector<vector<int>> temp(n + 1);
    _prime_factors.swap(temp);
    _prime.clear();
    int p = 0;
    for (int i = 0; i <= n; ++i) _is_prime[i] = 1;
    _is_prime[0] = _is_prime[1] = 0;
    for (int i = 2; i <= n; ++i) {
      if (_is_prime[i]) {
        _prime.push_back(i);
        _is_prime[i] = ++p;
        for (int j = 2 * i; j <= n; j += i) _is_prime[j] = 0;
        for (int j = i; j <= n; j += i) _prime_factors[j].push_back(i);
      }
    }
  }
  const vector<vector<int>> &get_prime_factors() { return _prime_factors; }
  const vector<int> &get_is_prime() { return _is_prime; }
  const vector<int> &get_prime() { return _prime; }

 private:
  vector<int> _prime;
  vector<int> _is_prime;
  vector<vector<int>> _prime_factors;
};
constexpr int MAXN = (int)1e6 + 5;
struct Solution {
  struct Factor {
    Factor() {}
    Factor(int v) {
      static PrimeUtil prime_util(MAXN);
      static vector<vector<int>> prime_factors = prime_util.get_prime_factors();
      int tmp = v;
      for (auto fac : prime_factors[v]) {
        while (tmp % fac == 0) {
          tmp /= fac;
          factor_cnt[fac]++;
        }
      }
    }
    Factor operator/(const Factor &b) {
      Factor c = *this;
      for (auto iter : b.factor_cnt) {
        c.factor_cnt[iter.first] -= iter.second;
        if (c.factor_cnt[iter.first] < 0) c.neg_factor.insert(iter.first);
      }
      return c;
    }
    Factor &operator*=(const Factor &b) {
      for (auto iter : b.factor_cnt) {
        factor_cnt[iter.first] += iter.second;
        if (factor_cnt[iter.first] >= 0) neg_factor.erase(iter.first);
      }
      return *this;
    }
    bool is_int() { return neg_factor.size() <= 0; }
    map<int, int> factor_cnt;
    set<int> neg_factor;
  };

 public:
  void Solve() {
    vector<Factor> factors(MAXN);
    for (int i = 0; i < (MAXN); i++) {
      factors[i] = Factor(i);
    }
    int n;
    while (cin >> n) {
      vector<int> a(n);
      for (int i = 0; i < (n); i++) cin >> a[i];
      string b;
      cin >> b;
      int cur = 0;
      long long ans = 0;
      stack<Factor> st;
      while (cur < n) {
        while (cur < n && (b[cur] == '*' || a[cur] == 1)) {
          st.push(factors[a[cur]]);
          cur++;
        }
        ans += (1ll + st.size()) * st.size() / 2;
        if (cur >= n) break;
        Factor tar = factors[1] / factors[a[cur]];
        while (!st.empty()) {
          tar *= st.top();
          st.pop();
          if (tar.is_int()) {
            st.push(tar);
            ans += (1ll + st.size()) * st.size() / 2;
            break;
          }
        }
        cur++;
      }
      cout << ans << endl;
    }
  }

 private:
};
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  Solution().Solve();
  return 0;
}
