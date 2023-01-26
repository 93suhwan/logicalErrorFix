#include <bits/stdc++.h>
using std::cin;
using std::cout;
using std::deque;
using std::endl;
using std::get;
using std::greater;
using std::ifstream;
using std::ios_base;
using std::less;
using std::list;
using std::lower_bound;
using std::make_pair;
using std::make_tuple;
using std::map;
using std::max;
using std::max_element;
using std::min;
using std::min_element;
using std::multimap;
using std::multiset;
using std::ofstream;
using std::pair;
using std::priority_queue;
using std::queue;
using std::set;
using std::stack;
using std::string;
using std::swap;
using std::tuple;
using std::unordered_map;
using std::unordered_multimap;
using std::unordered_set;
using std::upper_bound;
using std::vector;
[[maybe_unused]] const string sep = " ";
[[maybe_unused]] const string yes = "YES\n";
[[maybe_unused]] const string no = "NO\n";
[[maybe_unused]] const string ng = "NG\n";
[[maybe_unused]] const string ok = "OK\n";
[[maybe_unused]] const double pi = acos(-1);
[[maybe_unused]] const unsigned long long modular = 1e9 + 7;
template <class T>
T min(const T &a, const T &b, const T &c) {
  return min(a, min(b, c));
}
template <class T>
T max(const T &a, const T &b, const T &c) {
  return max(a, max(b, c));
}
long long gcd(long long a, long long b) {
  if (a == 0) {
    return b;
  }
  return gcd(b % a, a);
}
long long fast_power(long long a, long long pow) {
  if (pow == 0) {
    return 1;
  }
  if (pow % 2 == 0) {
    auto x = fast_power(a, pow / 2);
    return (x * x);
  } else {
    auto x = fast_power(a, pow - 1);
    return (a * x);
  }
}
long long fast_power(long long a, long long pow, long long mod) {
  if (pow == 0) {
    return 1;
  }
  if (pow % 2 == 0) {
    auto x = fast_power(a, pow / 2, mod);
    return (x * x) % mod;
  } else {
    auto x = fast_power(a, pow - 1, mod);
    return (a * x) % mod;
  }
}
void getFactorialsModular(const long long n, const long long mod,
                          vector<long long> &F) {
  F.resize(n + 1);
  F[0] = 1;
  for (long long i = 1; i <= n; ++i) {
    F[i] = (F[i - 1] * i) % mod;
  }
}
void getFactorialsAndInverseModular(const long long n, const long long mod,
                                    vector<long long> &F,
                                    vector<long long> &I) {
  getFactorialsModular(n, mod, F);
  I.resize(n + 1);
  I[0] = 1;
  for (long long i = 1; i <= n; ++i) {
    I[i] = fast_power(F[i], mod - 2, mod);
  }
}
long long CnkMod(long long n, long long k, long long mod, vector<long long> &F,
                 vector<long long> &I) {
  return (((F[n] * I[k]) % mod) * I[n - k]) % mod;
}
long long CnkWithRepetitionMod(long long n, long long k, long long mod,
                               vector<long long> &F, vector<long long> &I) {
  return CnkMod(n + k - 1, k - 1, mod, F, I);
}
template <typename valueType, typename tagType>
class segmentTreeNode {
 public:
  int id, left, right;
  valueType val;
  tagType tag;
};
template <typename valueType, typename tagType,
          valueType (*merge)(valueType, valueType),
          void (*update)(segmentTreeNode<valueType, tagType> &, tagType)>
class segmentTree {
 private:
  std::vector<segmentTreeNode<valueType, tagType> > nodes;
  int leftRange, rightRange;
  valueType valueZero;
  tagType tagZero;
  void push_up(int cur) {
    nodes[cur].val = merge(nodes[cur << 1].val, nodes[cur << 1 | 1].val);
  }
  void push_down(int cur) {
    update(nodes[cur << 1], nodes[cur].tag);
    update(nodes[cur << 1 | 1], nodes[cur].tag);
    nodes[cur].tag = tagZero;
  }
  void build(int cur, int l, int r, const std::vector<valueType> &initValue) {
    nodes[cur].id = cur;
    nodes[cur].left = l;
    nodes[cur].right = r;
    nodes[cur].tag = tagZero;
    if (l == r - 1)
      nodes[cur].val = initValue[l - leftRange];
    else {
      build(cur << 1, l, (l + r) >> 1, initValue);
      build(cur << 1 | 1, (l + r) >> 1, r, initValue);
      push_up(cur);
    }
  }
  void init(const std::vector<valueType> &_initValue,
            const valueType &_valueZero, const tagType &_tagZero) {
    valueZero = _valueZero;
    tagZero = _tagZero;
    nodes.resize((rightRange - leftRange) << 2);
    build(1, leftRange, rightRange, _initValue);
  }
  void modify(int cur, int l, int r, int L, int R, const tagType &tag) {
    if (l >= R || r <= L) return;
    if (L <= l && r <= R)
      update(nodes[cur], tag);
    else {
      push_down(cur);
      modify(cur << 1, l, (l + r) >> 1, L, R, tag);
      modify(cur << 1 | 1, (l + r) >> 1, r, L, R, tag);
      push_up(cur);
    }
  }
  valueType query(int cur, int l, int r, int L, int R) {
    if (l >= R || r <= L) return valueZero;
    if (L <= l && r <= R) return nodes[cur].val;
    push_down(cur);
    return merge(query(cur << 1, l, (l + r) >> 1, L, R),
                 query(cur << 1 | 1, (l + r) >> 1, r, L, R));
  }

 public:
  segmentTree() {}
  segmentTree(int _leftRange, int _rightRange,
              const std::vector<valueType> &_initValue,
              const valueType &_valueZero, const tagType &_tagZero) {
    leftRange = _leftRange;
    rightRange = _rightRange;
    init(_initValue, _valueZero, _tagZero);
  }
  segmentTree(int size, const std::vector<valueType> &_initValue,
              const valueType &_valueZero, const tagType &_tagZero) {
    leftRange = 1;
    rightRange = size + 1;
    init(_initValue, _valueZero, _tagZero);
  }
  void modify(int l, int r, const tagType &tag) {
    modify(1, leftRange, rightRange, l, r, tag);
  }
  void modify(int p, const tagType &tag) { modify(p, p + 1, tag); }
  valueType query(int l, int r) {
    return query(1, leftRange, rightRange, l, r);
  }
  valueType query(int p) { return query(p, p + 1); }
};
long long merge(long long x, long long y) { return min(x, y); }
void update(segmentTreeNode<long long, long long> &node, long long x) {
  node.val += x;
}
int main() {
  long long tests;
  cin >> tests;
  for (long long test = 1; test <= tests; ++test) {
    bool good = false;
    long long n;
    cin >> n;
    vector<long long> v(n);
    for (auto &t : v) {
      cin >> t;
    }
    for (int i = 1; i < fast_power(3, n); ++i) {
      vector<long long> operations(n);
      long long t = i;
      long long k = 0;
      while (t != 0) {
        operations[k] = t % 3;
        t /= 3;
        ++k;
      }
      long long sum = 0;
      for (int j = 0; j < n; ++j) {
        if (operations[j] == 1) {
          sum += abs(v[j]);
        } else if (operations[j] == 2) {
          sum -= abs(v[j]);
        }
      }
      if (sum == 0) {
        good = true;
      }
    }
    if (good) {
      cout << yes;
    } else {
      cout << no;
    }
  }
}
