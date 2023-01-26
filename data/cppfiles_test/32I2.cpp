#include <bits/stdc++.h>
using namespace std;
mt19937 mrand(random_device{}());
int rnd(int x) { return mrand() % x; }
const long long mod = 1000000007;
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
ostream &operator<<(ostream &os, const unordered_map<TK, TV> &make_pair) {
  os << "{";
  for (auto v : make_pair) os << v.first << "=>" << v.second << ",";
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
ostream &operator<<(ostream &os, const pair<T1, T2> &pa) {
  os << "(" << pa.first << "," << pa.second << ")";
  return os;
}
template <typename TK, typename TV>
ostream &operator<<(ostream &os, const map<TK, TV> &make_pair) {
  os << "{";
  for (auto v : make_pair) os << v.first << "=>" << v.second << ",";
  os << "}";
  return os;
}
template <typename T>
bool mmax(T &m, const T q) {
  if (m < q) {
    m = q;
    return true;
  } else
    return false;
}
template <typename T>
bool mmin(T &m, const T q) {
  if (q < m) {
    m = q;
    return true;
  } else
    return false;
}
template <typename T1, typename T2>
pair<T1, T2> operator+(const pair<T1, T2> &l, const pair<T1, T2> &r) {
  return make_pair(l.first + r.first, l.second + r.second);
}
template <typename T1, typename T2>
pair<T1, T2> operator-(const pair<T1, T2> &l, const pair<T1, T2> &r) {
  return make_pair(l.first - r.first, l.second - r.second);
}
long long powmod(long long a, long long b) {
  long long res = 1;
  a %= mod;
  assert(b >= 0);
  for (; b; b >>= 1) {
    if (b & 1) res = res * a % mod;
    a = a * a % mod;
  }
  return res;
}
long long gcd(long long a, long long b) { return b ? gcd(b, a % b) : a; }
template <unsigned int MD>
struct ModInt {
  using M = ModInt;
  unsigned int v;
  ModInt(long long _v = 0) { set_v(unsigned int(_v % MD + MD)); }
  M &set_v(unsigned int _v) {
    v = (_v < MD) ? _v : _v - MD;
    return *this;
  }
  explicit operator bool() const { return v != 0; }
  M operator-() const { return M() - *this; }
  M operator+(const M &r) const { return M().set_v(v + r.v); }
  M operator-(const M &r) const { return M().set_v(v + MD - r.v); }
  M operator*(const M &r) const {
    return M().set_v(unsigned int(unsigned long long(v) * r.v % MD));
  }
  M operator/(const M &r) const { return *this * r.inv(); }
  M &operator+=(const M &r) { return *this = *this + r; }
  M &operator-=(const M &r) { return *this = *this - r; }
  M &operator*=(const M &r) { return *this = *this * r; }
  M &operator/=(const M &r) { return *this = *this / r; }
  bool operator==(const M &r) const { return v == r.v; }
  M pow(long long n) const {
    M x = *this, r = 1;
    while (n) {
      if (n & 1) r *= x;
      x *= x;
      n >>= 1;
    }
    return r;
  }
  M inv() const { return pow(MD - 2); }
  friend ostream &operator<<(ostream &os, const M &r) { return os << r.v; }
};
using Mint = ModInt<998244353>;
class Solution {
 public:
  void Solve() {
    int n;
    while (cin >> n) {
      vector<int> tmp(n);
      for (int i = 0; i < n; i++) cin >> tmp[i];
      vector<int> a;
      for (int i = 0; i < n; i += tmp[i]) {
        for (int j = i; j < i + tmp[i]; j++) {
          if (tmp[j] != tmp[i]) {
            a.push_back(-1);
            break;
          }
        }
        if (a.size() > 0 && a.back() == -1) break;
        a.push_back(tmp[i]);
      }
      if (a.back() == -1) {
        cout << 0 << endl;
      } else {
        vector<vector<vector<Mint>>> dp(
            a.size() + 1, vector<vector<Mint>>(a.size(), vector<Mint>(3, 0)));
        if (a[0] > 1) {
          dp[1][0][0] = dp[1][0][1] = 1;
        } else {
          dp[1][0][2] = 1;
        }
        for (int stair_id = 2; stair_id < a.size() + 1; stair_id++) {
          for (int violate = 0; violate < stair_id - 1; violate++) {
            dp[stair_id][violate + 1][0] += dp[stair_id - 1][violate][0];
            dp[stair_id][violate + 1][1] += dp[stair_id - 1][violate][1];
            dp[stair_id][violate + 1][0] += dp[stair_id - 1][violate][2];
            dp[stair_id][violate + 1][1] += dp[stair_id - 1][violate][2];
            if (a[stair_id - 1] == 1) {
              dp[stair_id][violate][2] +=
                  dp[stair_id - 1][violate][0] * (stair_id - violate);
              dp[stair_id][violate][2] +=
                  dp[stair_id - 1][violate][1] * (stair_id - violate);
              dp[stair_id][violate][2] +=
                  dp[stair_id - 1][violate][2] * (stair_id - violate);
            } else {
              dp[stair_id][violate][0] +=
                  dp[stair_id - 1][violate][0] * (stair_id - violate);
              dp[stair_id][violate][0] +=
                  dp[stair_id - 1][violate][1] * (stair_id - violate);
              dp[stair_id][violate][0] +=
                  dp[stair_id - 1][violate][2] * (stair_id - violate);
              dp[stair_id][violate][1] +=
                  dp[stair_id - 1][violate][0] * (stair_id - violate);
              dp[stair_id][violate][1] +=
                  dp[stair_id - 1][violate][1] * (stair_id - violate);
              dp[stair_id][violate][1] +=
                  dp[stair_id - 1][violate][2] * (stair_id - violate);
            }
          }
        }
        long long ans =
            (dp[a.size()][0][0] + dp[a.size()][0][1] + dp[a.size()][0][2]).v;
        for (int i = 1; i < a.size(); ++i) {
          if (i & 1) {
            ans -=
                (dp[a.size()][i][0] + dp[a.size()][i][1] + dp[a.size()][i][2])
                    .v;
          } else {
            ans +=
                (dp[a.size()][i][0] + dp[a.size()][i][1] + dp[a.size()][i][2])
                    .v;
          }
        }
        cout << ans << endl;
      }
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
