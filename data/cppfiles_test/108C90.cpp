#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
using namespace std;
struct fraction {
  long long p, q;
  fraction(long long P = 0, long long Q = 1) : p(P), q(Q) {}
  bool operator<(const fraction &other) const {
    return p * other.q < other.p * q;
  }
  bool operator<=(const fraction &other) const {
    return p * other.q <= other.p * q;
  }
};
template <long long D, typename T>
struct Vec : public vector<Vec<D - 1, T>> {
  static_assert(D >= 1, "Vector dimension must be greater than zero!");
  template <typename... Args>
  Vec(long long n = 0, Args... args)
      : vector<Vec<D - 1, T>>(n, Vec<D - 1, T>(args...)) {}
};
template <typename T>
struct Vec<1, T> : public vector<T> {
  Vec(long long n = 0, const T &val = T()) : vector<T>(n, val) {}
};
template <typename T>
void printv(vector<T> v) {
  for (auto e : v) {
    cout << e << " ";
  }
  cout << "\n";
}
template <typename T>
void printvv(vector<T> vv) {
  for (long long i = 0; i < vv.size(); i++) {
    cout << i << ": ";
    for (auto e : vv[i]) {
      cout << e << " ";
    }
    cout << "\n";
  }
}
template <typename T>
void ri(T &x) {
  cin >> x;
}
template <typename T, typename... Args>
void ri(T &x, Args &...args) {
  ri(x);
  ri(args...);
}
template <typename T>
void ri(vector<T> &v) {
  for (auto &x : v) {
    cin >> x;
  }
}
template <typename T, typename... Args>
void ri(vector<T> &v, Args &...args) {
  ri(v);
  ri(args...);
}
template <typename T>
void po(T x) {
  cout << x << "\n";
}
template <typename T, typename... Args>
void po(T x, Args... args) {
  cout << x << " ";
  po(args...);
}
template <typename T>
void po(vector<T> a) {
  for (long long i = 0; i < a.size(); i++) {
    if (i < a.size() - 1) {
      cout << a[i] << " ";
    } else
      cout << a[i] << "\n";
  }
}
void __print(long long x) { cerr << x; }
void __print(long x) { cerr << x; }
void __print(unsigned x) { cerr << x; }
void __print(unsigned long x) { cerr << x; }
void __print(unsigned long long x) { cerr << x; }
void __print(float x) { cerr << x; }
void __print(double x) { cerr << x; }
void __print(long double x) { cerr << x; }
void __print(char x) { cerr << '\'' << x << '\''; }
void __print(const char *x) { cerr << '\"' << x << '\"'; }
void __print(const string &x) { cerr << '\"' << x << '\"'; }
void __print(bool x) { cerr << (x ? "true" : "false"); }
void __print(fraction x) { cerr << x.p << '/' << x.q; }
template <typename T, typename V>
void __print(const pair<T, V> &x) {
  cerr << '{';
  __print(x.first);
  cerr << ',';
  __print(x.second);
  cerr << '}';
}
template <typename T1, typename T2, typename T3>
void __print(const tuple<T1, T2, T3> &x) {
  cerr << '{';
  __print(get<0>(x));
  cerr << ',';
  __print(get<1>(x));
  cerr << ',';
  __print(get<2>(x));
  cerr << '}';
}
template <typename T1, typename T2, typename T3, typename T4>
void __print(const tuple<T1, T2, T3, T4> &x) {
  cerr << '{';
  __print(get<0>(x));
  cerr << ',';
  __print(get<1>(x));
  cerr << ',';
  __print(get<2>(x));
  cerr << ',';
  __print(get<3>(x));
  cerr << '}';
}
template <typename T>
void __print(const T &x) {
  long long f = 0;
  cerr << '{';
  for (auto &i : x) cerr << (f++ ? "," : ""), __print(i);
  cerr << "}";
}
void _print() { cerr << "]\n"; }
template <typename T, typename... V>
void _print(T t, V... v) {
  __print(t);
  if (sizeof...(v)) cerr << ", ";
  _print(v...);
}
long long cnt_leq_x(vector<long long> &a, long long x) {
  long long ret = upper_bound(a.begin(), a.end(), x) - a.begin();
  return ret;
}
long long cnt_leq_x(vector<long long> &a, long long x, long long lo,
                    long long hi) {
  long long ret =
      upper_bound(a.begin() + lo, a.begin() + hi, x) - a.begin() + lo;
  return ret;
}
long long cnt_lt_x(vector<long long> &a, long long x) {
  long long ret = lower_bound(a.begin(), a.end(), x) - a.begin();
  return ret;
}
long long cnt_lt_x(vector<long long> &a, long long x, long long lo,
                   long long hi) {
  long long ret =
      lower_bound(a.begin() + lo, a.begin() + hi, x) - a.begin() + lo;
  return ret;
}
long long cnt_geq_x(vector<long long> &a, long long x) {
  long long ret = a.end() - lower_bound(a.begin(), a.end(), x);
  return ret;
}
long long cnt_geq_x(vector<long long> &a, long long x, long long lo,
                    long long hi) {
  long long ret =
      a.begin() + hi - lower_bound(a.begin() + lo, a.begin() + hi, x);
  return ret;
}
long long cnt_gt_x(vector<long long> &a, long long x) {
  long long ret = a.end() - upper_bound(a.begin(), a.end(), x);
  return ret;
}
long long cnt_gt_x(vector<long long> &a, long long x, long long lo,
                   long long hi) {
  long long ret =
      a.begin() + hi - upper_bound(a.begin() + lo, a.begin() + hi, x);
  return ret;
}
bool mul_overflow(long long a, long long b) {
  long long c;
  return __builtin_mul_overflow(a, b, &c);
}
template <typename T>
T sum(vector<T> &a) {
  T ret = 0;
  for (auto v : a) ret += v;
  return ret;
}
template <typename T>
T max(vector<T> &a) {
  T ret = *max_element(a.begin(), a.end());
  return ret;
}
template <typename T>
T min(vector<T> &a) {
  T ret = *min_element(a.begin(), a.end());
  return ret;
}
long long int_pow(long long base, long long exp) {
  long long res = 1;
  while (exp) {
    if (exp & 1) res *= base;
    exp >>= 1;
    base *= base;
  }
  return res;
}
long long highest_power_of_2(long long n) {
  while ((n & (n - 1)) != 0) {
    n = n & (n - 1);
  }
  return n;
}
long long char2int(char x) {
  long long y = x - '0';
  if (0 <= y && y <= 9)
    return y;
  else
    return x - 'a' + 10;
}
template <size_t rows, size_t cols>
void fill_2d(long long (&arr)[rows][cols], long long v) {
  fill(&arr[0][0], &arr[0][0] + sizeof(arr) / sizeof(arr[0][0]), -1);
}
long long ccw(pair<long long, long long> p1, pair<long long, long long> p2,
              pair<long long, long long> p3) {
  auto [x1, y1] = p1;
  auto [x2, y2] = p2;
  auto [x3, y3] = p3;
  return (x2 - x1) * (y3 - y1) - (x3 - x1) * (y2 - y1);
}
struct dsu {
 public:
  dsu() : _n(0) {}
  dsu(long long n) : _n(n), parent_or_size(n, -1) {}
  long long merge(long long a, long long b) {
    assert(0 <= a && a < _n);
    assert(0 <= b && b < _n);
    long long x = leader(a), y = leader(b);
    if (x == y) return x;
    if (-parent_or_size[x] < -parent_or_size[y]) std::swap(x, y);
    parent_or_size[x] += parent_or_size[y];
    parent_or_size[y] = x;
    return x;
  }
  bool same(long long a, long long b) {
    assert(0 <= a && a < _n);
    assert(0 <= b && b < _n);
    return leader(a) == leader(b);
  }
  long long leader(long long a) {
    assert(0 <= a && a < _n);
    if (parent_or_size[a] < 0) return a;
    return parent_or_size[a] = leader(parent_or_size[a]);
  }
  long long size(long long a) {
    assert(0 <= a && a < _n);
    return -parent_or_size[leader(a)];
  }
  std::vector<std::vector<long long>> groups() {
    std::vector<long long> leader_buf(_n), group_size(_n);
    for (long long i = 0; i < _n; i++) {
      leader_buf[i] = leader(i);
      group_size[leader_buf[i]]++;
    }
    std::vector<std::vector<long long>> result(_n);
    for (long long i = 0; i < _n; i++) {
      result[i].reserve(group_size[i]);
    }
    for (long long i = 0; i < _n; i++) {
      result[leader_buf[i]].push_back(i);
    }
    result.erase(std::remove_if(result.begin(), result.end(),
                                [&](const std::vector<long long> &v) {
                                  return v.empty();
                                }),
                 result.end());
    return result;
  }

 private:
  long long _n;
  std::vector<long long> parent_or_size;
};
class Trie {
 public:
  bool leaf;
  Trie *children[26];
  Trie() {
    this->leaf = false;
    for (long long i = 0; i < 26; i++) {
      this->children[i] = nullptr;
    }
  }
  void insert(string s) {
    Trie *node = this;
    for (long long i = 0; i < s.size(); i++) {
      long long idx = s[i] - 'a';
      if (node->children[idx] == nullptr) node->children[idx] = new Trie();
      node = node->children[idx];
    }
    node->leaf = true;
  }
  bool search(string key) {
    Trie *node = this;
    for (long long i = 0; i < key.length(); i++) {
      long long idx = key[i] - 'a';
      if (!node->children[idx]) return false;
      node = node->children[idx];
    }
    return (node->leaf);
  }
};
void io_util() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.precision(17);
}
signed main() {
  io_util();
  long long t;
  ri(t);
  while (t--) {
    long long n;
    ri(n);
    vector<long long> a(n), b(n);
    ri(a, b);
    vector<pair<long long, long long>> aa(n), bb(n);
    for (long long i = 0; i < n; i++) {
      aa[i] = {a[i], i};
      bb[i] = {b[i], i};
    }
    sort(aa.rbegin(), aa.rend());
    sort(bb.rbegin(), bb.rend());
    vector<long long> ans(n);
    ans[aa[0].second] = 1;
    ans[bb[0].second] = 1;
    long long a_lo = a[bb[0].second];
    long long b_lo = b[aa[0].second];
    long long ii = 1;
    long long jj = 1;
    while (ii < n || jj < n) {
      auto [aaa, iii] = aa[ii];
      auto [bbb, jjj] = bb[jj];
      if (aaa > a_lo || bbb > b_lo) {
        if (aaa > a_lo) {
          ans[iii] = 1;
          b_lo = min(b_lo, b[iii]);
          ii++;
        }
        if (bbb > b_lo) {
          ans[jjj] = 1;
          a_lo = min(a_lo, a[jjj]);
          jj++;
        }
      } else
        break;
    }
    while (ii < n) {
      auto [aaa, iii] = aa[ii];
      if (aaa > a_lo) {
        ans[iii] = 1;
        b_lo = min(b_lo, b[iii]);
        ii++;
      } else
        break;
    }
    while (jj < n) {
      auto [bbb, jjj] = bb[jj];
      if (bbb > b_lo) {
        ans[jjj] = 1;
        a_lo = min(a_lo, a[jjj]);
        jj++;
      } else
        break;
    }
    for (auto x : ans) {
      cout << x;
    }
    cout << "\n";
  }
  return 0;
}
