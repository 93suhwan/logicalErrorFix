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
[[maybe_unused]] const unsigned long long modular = 998244353;
class BigInteger {
 public:
  BigInteger();
  BigInteger(int int_to_big_integer);
  BigInteger(const std::string &string_to_big_integer);
  friend BigInteger operator+(const BigInteger &big_integer_a,
                              const BigInteger &big_integer_b);
  friend BigInteger operator-(const BigInteger &big_integer_a,
                              const BigInteger &big_integer_b);
  friend BigInteger operator*(const BigInteger &big_integer_a,
                              const BigInteger &big_integer_b);
  friend BigInteger operator/(const BigInteger &big_integer_a,
                              const BigInteger &big_integer_b);
  friend BigInteger operator%(const BigInteger &big_integer_a,
                              const BigInteger &big_integer_b);
  BigInteger &operator+=(const BigInteger &big_integer_a);
  BigInteger &operator-=(const BigInteger &big_integer_a);
  BigInteger &operator*=(const BigInteger &big_integer_a);
  BigInteger &operator%=(const BigInteger &big_integer_a);
  BigInteger &operator/=(const BigInteger &big_integer_a);
  bool operator<(BigInteger const &big_integer_a) const;
  bool operator>(BigInteger const &big_integer_a) const;
  bool operator<=(BigInteger const &big_integer_a) const;
  bool operator>=(BigInteger const &big_integer_a) const;
  bool operator==(BigInteger const &big_integer_a) const;
  bool operator!=(BigInteger const &big_integer_a) const;
  BigInteger &operator++();
  const BigInteger operator++(int);
  BigInteger &operator--();
  const BigInteger operator--(int);
  BigInteger operator-();
  std::string toString() const;
  explicit operator bool();
  friend std::istream &operator>>(std::istream &in, BigInteger &big_integer_a);
  friend std::ostream &operator<<(std::ostream &out,
                                  const BigInteger &big_integer_a);

 private:
  bool is_positive_ = true;
  std::vector<int> digits_;
  void EraseLeadingZeros();
  bool IsZero() const;
  static void SubIfPositive(BigInteger &big_integer_a,
                            const BigInteger &big_integer_b);
  static void Sum(BigInteger &big_integer_a, const BigInteger &big_integer_b);
  BigInteger Abs() const;
  friend std::vector<int> NaiveMultiplication(const std::vector<int> &digits_a,
                                              const std::vector<int> &digits_b);
  friend void Normalize(std::vector<int> &digits);
  friend std::vector<int> FastMultiplication(const std::vector<int> &digits_a,
                                             const std::vector<int> &digits_b);
  bool DifferentSigns(const BigInteger &big_integer_a) const;
};
std::vector<int> NaiveMultiplication(const std::vector<int> &digits_a,
                                     const std::vector<int> &digits_b) {
  auto size = digits_a.size();
  std::vector<int> digits_result(2 * size);
  for (size_t i = 0; i < size; ++i) {
    for (size_t j = 0; j < size; ++j) {
      digits_result[i + j] += digits_a[i] * digits_b[j];
    }
  }
  return digits_result;
}
void Normalize(std::vector<int> &digits) {
  for (size_t i = 0; i < digits.size(); ++i) {
    digits[i + 1] += digits[i] / 10;
    digits[i] %= 10;
  }
}
std::vector<int> FastMultiplication(const std::vector<int> &digits_a,
                                    const std::vector<int> &digits_b) {
  auto size = digits_a.size();
  std::vector<int> digits_result(2 * size);
  return NaiveMultiplication(digits_a, digits_b);
}
BigInteger::BigInteger() : is_positive_(true) {}
BigInteger::BigInteger(int int_to_big_integer) {
  if (int_to_big_integer < 0) {
    is_positive_ = false;
    int_to_big_integer *= -1;
  } else if (int_to_big_integer == 0) {
    digits_.push_back(0);
    is_positive_ = true;
  }
  while (int_to_big_integer != 0) {
    digits_.push_back(int_to_big_integer % 10);
    int_to_big_integer /= 10;
  }
}
BigInteger::BigInteger(const std::string &string_to_big_integer) {
  is_positive_ = true;
  if (!string_to_big_integer.empty()) {
    for (size_t i = string_to_big_integer.length() - 1; i > 0; --i)
      digits_.push_back(string_to_big_integer[i] - '0');
    if (string_to_big_integer[0] == '-')
      is_positive_ = false;
    else
      digits_.push_back(string_to_big_integer[0] - '0');
  }
}
BigInteger operator+(const BigInteger &big_integer_a,
                     const BigInteger &big_integer_b) {
  BigInteger big_integer_sum = big_integer_a;
  return big_integer_sum += big_integer_b;
}
BigInteger operator-(const BigInteger &big_integer_a,
                     const BigInteger &big_integer_b) {
  BigInteger big_integer_sub = big_integer_a;
  return big_integer_sub -= big_integer_b;
}
BigInteger operator*(const BigInteger &big_integer_a,
                     const BigInteger &big_integer_b) {
  BigInteger big_integer_multiplication = big_integer_a;
  return big_integer_multiplication *= big_integer_b;
}
BigInteger operator/(const BigInteger &big_integer_a,
                     const BigInteger &big_integer_b) {
  BigInteger big_integer_division = big_integer_a;
  return big_integer_division /= big_integer_b;
}
BigInteger operator%(const BigInteger &big_integer_a,
                     const BigInteger &big_integer_b) {
  BigInteger big_integer_division_with_remainder = big_integer_a;
  return big_integer_division_with_remainder %= big_integer_b;
}
BigInteger &BigInteger::operator+=(const BigInteger &big_integer_a) {
  if (!DifferentSigns(big_integer_a)) {
    Sum(*this, big_integer_a);
    return *this;
  } else {
    if (this->Abs() >= big_integer_a.Abs()) {
      SubIfPositive(*this, big_integer_a);
      return *this;
    } else {
      BigInteger big_integer_temp_this = *this;
      BigInteger big_integer_temp_a = big_integer_a;
      SubIfPositive(big_integer_temp_a, big_integer_temp_this);
      return *this = big_integer_temp_a;
    }
  }
}
BigInteger &BigInteger::operator-=(const BigInteger &big_integer_a) {
  if (!DifferentSigns(big_integer_a)) {
    if (this->Abs() >= big_integer_a.Abs()) {
      SubIfPositive(*this, big_integer_a);
      return *this;
    } else {
      BigInteger big_integer_temp_this = *this;
      BigInteger big_integer_temp_a = big_integer_a;
      SubIfPositive(big_integer_temp_a, big_integer_temp_this);
      big_integer_temp_a.is_positive_ = !big_integer_temp_a.is_positive_;
      return *this = big_integer_temp_a;
    }
  } else {
    Sum(*this, big_integer_a);
    return *this;
  }
}
BigInteger &BigInteger::operator*=(const BigInteger &big_integer_a) {
  size_t size = std::max(big_integer_a.digits_.size(), digits_.size());
  BigInteger big_integer_result;
  auto big_integer_temp_a = big_integer_a;
  big_integer_temp_a.digits_.resize(size);
  digits_.resize(size);
  digits_ = FastMultiplication(big_integer_temp_a.digits_, digits_);
  Normalize(digits_);
  EraseLeadingZeros();
  is_positive_ = !(DifferentSigns(big_integer_a));
  return *this;
}
BigInteger &BigInteger::operator/=(const BigInteger &big_integer_a) {
  BigInteger big_integer_result;
  big_integer_result.digits_.resize(digits_.size());
  BigInteger big_integer_current;
  for (int i = digits_.size() - 1; i >= 0; --i) {
    big_integer_current.digits_.insert(big_integer_current.digits_.begin(), 0);
    big_integer_current.EraseLeadingZeros();
    big_integer_current.digits_[0] = digits_[i];
    size_t new_digit = 0;
    size_t left = 0, right = 9;
    while (left <= right) {
      size_t middle = (left + right) / 2;
      if ((big_integer_a.Abs() * middle).Abs() <= big_integer_current.Abs()) {
        new_digit = middle;
        left = middle + 1;
      } else
        right = middle - 1;
    }
    big_integer_current -= big_integer_a.Abs() * new_digit;
    big_integer_result.digits_[i] = new_digit;
  }
  big_integer_result.is_positive_ = !(DifferentSigns(big_integer_a));
  big_integer_result.EraseLeadingZeros();
  *this = big_integer_result;
  return *this;
}
BigInteger &BigInteger::operator%=(const BigInteger &big_integer_a) {
  BigInteger big_integer_result;
  big_integer_result.digits_.resize(digits_.size());
  BigInteger big_integer_current;
  for (int i = digits_.size() - 1; i >= 0; --i) {
    big_integer_current.digits_.insert(big_integer_current.digits_.begin(), 0);
    big_integer_current.EraseLeadingZeros();
    big_integer_current.digits_[0] = digits_[i];
    size_t new_digit = 0;
    size_t left = 0, right = 9;
    while (left <= right) {
      size_t middle = (left + right) / 2;
      if ((big_integer_a.Abs() * middle).Abs() <= big_integer_current.Abs()) {
        new_digit = middle;
        left = middle + 1;
      } else
        right = middle - 1;
    }
    big_integer_result.digits_[i] = new_digit;
    big_integer_current = big_integer_current - big_integer_a.Abs() * new_digit;
  }
  big_integer_current.EraseLeadingZeros();
  big_integer_current.is_positive_ = is_positive_;
  if (big_integer_current.digits_.empty())
    big_integer_current.digits_.push_back(0);
  *this = big_integer_current;
  return *this;
}
bool BigInteger::operator<(BigInteger const &big_integer_a) const {
  if (IsZero() && big_integer_a.IsZero()) {
    return false;
  }
  if (DifferentSigns(big_integer_a)) {
    return !is_positive_;
  }
  if (digits_.size() > big_integer_a.digits_.size()) {
    return !is_positive_;
  }
  if (digits_.size() < big_integer_a.digits_.size()) {
    return is_positive_;
  }
  for (int i = digits_.size() - 1; i >= 0; --i) {
    if (digits_[i] > big_integer_a.digits_[i]) {
      return !is_positive_;
    }
    if (digits_[i] < big_integer_a.digits_[i]) {
      return is_positive_;
    }
  }
  return false;
}
bool BigInteger::operator>(BigInteger const &big_integer_a) const {
  return (big_integer_a < *this);
}
bool BigInteger::operator<=(BigInteger const &big_integer_a) const {
  return !(*this > big_integer_a);
}
bool BigInteger::operator>=(BigInteger const &big_integer_a) const {
  return !(*this < big_integer_a);
}
bool BigInteger::operator==(BigInteger const &big_integer_a) const {
  return (*this >= big_integer_a) && (*this <= big_integer_a);
}
bool BigInteger::operator!=(BigInteger const &big_integer_a) const {
  return !(*this == big_integer_a);
}
BigInteger &BigInteger::operator++() {
  *this += 1;
  return *this;
}
const BigInteger BigInteger::operator++(int) {
  BigInteger big_integer_temp_this = *this;
  ++(*this);
  return big_integer_temp_this;
}
BigInteger &BigInteger::operator--() {
  *this -= 1;
  return *this;
}
const BigInteger BigInteger::operator--(int) {
  BigInteger big_integer_temp_this = *this;
  --(*this);
  return big_integer_temp_this;
}
std::istream &operator>>(std::istream &in, BigInteger &big_integer_a) {
  std::string string_to_big_integer;
  in >> string_to_big_integer;
  big_integer_a = BigInteger(string_to_big_integer);
  return in;
}
std::ostream &operator<<(std::ostream &out, const BigInteger &big_integer_a) {
  out << big_integer_a.toString();
  return out;
}
BigInteger BigInteger::operator-() {
  BigInteger big_integer_temp_this = *this;
  big_integer_temp_this.is_positive_ = !this->is_positive_;
  if (IsZero()) {
    big_integer_temp_this.is_positive_ = true;
    big_integer_temp_this.digits_[0] = 0;
    return big_integer_temp_this;
  } else
    return big_integer_temp_this;
}
std::string BigInteger::toString() const {
  std::string s = is_positive_ ? "" : "-";
  if (IsZero()) {
    s = '0';
    return s;
  }
  bool leading_zero = true;
  for (int i = digits_.size() - 1; i >= 0; --i) {
    if (!(digits_[i] == 0 && leading_zero)) {
      leading_zero = false;
      s += digits_[i] + '0';
    }
  }
  if (s.empty() || (s[0] == '-' && s.length() == 1)) s = '0';
  return s;
}
BigInteger::operator bool() { return !this->IsZero(); }
BigInteger BigInteger::Abs() const {
  BigInteger big_integer_temp_this = (*this);
  big_integer_temp_this.is_positive_ = true;
  return big_integer_temp_this;
}
void BigInteger::EraseLeadingZeros() {
  while (!digits_.empty() && *digits_.rbegin() == 0) {
    digits_.pop_back();
  }
  if (digits_.empty()) {
    is_positive_ = true;
    digits_.push_back(0);
  }
}
void BigInteger::SubIfPositive(BigInteger &big_integer_a,
                               const BigInteger &big_integer_b) {
  int carry = 0;
  for (size_t i = 0; i < big_integer_b.digits_.size() || carry; ++i) {
    if (i < big_integer_b.digits_.size()) {
      big_integer_a.digits_[i] -= carry + big_integer_b.digits_[i];
    } else {
      big_integer_a.digits_[i] -= carry;
    }
    carry = (big_integer_a.digits_[i] < 0);
    if (carry != 0) big_integer_a.digits_[i] += 10;
  }
  big_integer_a.EraseLeadingZeros();
}
void BigInteger::Sum(BigInteger &big_integer_a,
                     const BigInteger &big_integer_b) {
  int carry = 0;
  for (size_t i = 0; i < big_integer_a.digits_.size() ||
                     i < big_integer_b.digits_.size() || carry;
       ++i) {
    if (i == big_integer_a.digits_.size()) {
      big_integer_a.digits_.push_back(0);
    }
    if (i < big_integer_b.digits_.size()) {
      big_integer_a.digits_[i] += carry + big_integer_b.digits_[i];
    } else {
      big_integer_a.digits_[i] += carry;
    }
    carry = big_integer_a.digits_[i] / 10;
    big_integer_a.digits_[i] %= 10;
  }
  big_integer_a.EraseLeadingZeros();
}
bool BigInteger::IsZero() const {
  return digits_[0] == 0 && digits_.size() == 1;
}
bool BigInteger::DifferentSigns(const BigInteger &big_integer_a) const {
  return is_positive_ ^ big_integer_a.is_positive_;
}
template <class T>
T min(const T &a, const T &b, const T &c) {
  return min(a, min(b, c));
}
template <class T>
T max(const T &a, const T &b, const T &c) {
  return max(a, max(b, c));
}
vector<long long> lca_h, lca_dfs_list, lca_first, lca_tree;
vector<char> lca_dfs_used;
void lca_dfs(const vector<vector<long long>> &g, long long v, long long h = 1) {
  lca_dfs_used[v] = true;
  lca_h[v] = h;
  lca_dfs_list.push_back(v);
  for (auto i = g[v].begin(); i != g[v].end(); ++i)
    if (!lca_dfs_used[*i]) {
      lca_dfs(g, *i, h + 1);
      lca_dfs_list.push_back(v);
    }
}
void lca_build_tree(long long i, long long l, long long r) {
  if (l == r)
    lca_tree[i] = lca_dfs_list[l];
  else {
    long long m = (l + r) >> 1;
    lca_build_tree(i + i, l, m);
    lca_build_tree(i + i + 1, m + 1, r);
    if (lca_h[lca_tree[i + i]] < lca_h[lca_tree[i + i + 1]])
      lca_tree[i] = lca_tree[i + i];
    else
      lca_tree[i] = lca_tree[i + i + 1];
  }
}
void lca_prepare(const vector<vector<long long>> &g, long long root) {
  long long n = (long long)g.size();
  lca_h.resize(n);
  lca_dfs_list.reserve(n * 2);
  lca_dfs_used.assign(n, 0);
  lca_dfs(g, root);
  long long m = (long long)lca_dfs_list.size();
  lca_tree.assign(lca_dfs_list.size() * 4 + 1, -1);
  lca_build_tree(1, 0, m - 1);
  lca_first.assign(n, -1);
  for (long long i = 0; i < m; ++i) {
    long long v = lca_dfs_list[i];
    if (lca_first[v] == -1) lca_first[v] = i;
  }
}
long long lca_tree_min(long long i, long long sl, long long sr, long long l,
                       long long r) {
  if (sl == l && sr == r) return lca_tree[i];
  long long sm = (sl + sr) >> 1;
  if (r <= sm) return lca_tree_min(i + i, sl, sm, l, r);
  if (l > sm) return lca_tree_min(i + i + 1, sm + 1, sr, l, r);
  long long ans1 = lca_tree_min(i + i, sl, sm, l, sm);
  long long ans2 = lca_tree_min(i + i + 1, sm + 1, sr, sm + 1, r);
  return lca_h[ans1] < lca_h[ans2] ? ans1 : ans2;
}
long long lca(long long a, long long b) {
  long long left = lca_first[a], right = lca_first[b];
  if (left > right) swap(left, right);
  return lca_tree_min(1, 0, (long long)lca_dfs_list.size() - 1, left, right);
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
    return ((a % mod) * x) % mod;
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
  if (n < k) {
    return 0;
  }
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
  std::vector<segmentTreeNode<valueType, tagType>> nodes;
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
long long merge_low(int x, int y) { return min(x, y); }
long long merge_high(int x, int y) { return min(x, y); }
void update(segmentTreeNode<long long, long long> &node, long long x) {
  node.val += x;
}
long long cur_res = 0;
void make_set(int v, vector<int> &parent, vector<int> &rank) {
  parent[v] = v;
  rank[v] = 0;
  ++cur_res;
}
int find_set(int v, vector<int> &parent, vector<int> &rank) {
  if (v == parent[v]) return v;
  return parent[v] = find_set(parent[v], parent, rank);
}
void union_sets(int a, int b, vector<int> &parent, vector<int> &rank) {
  a = find_set(a, parent, rank);
  b = find_set(b, parent, rank);
  if (a != b) {
    --cur_res;
    if (rank[a] < rank[b]) swap(a, b);
    parent[b] = a;
    if (rank[a] == rank[b]) ++rank[a];
  }
}
long long _mergeSort(vector<long long> &arr, vector<long long> &temp,
                     long long left, long long right);
long long merge(vector<long long> &arr, vector<long long> &temp, long long left,
                long long mid, long long right);
int mergeSort(vector<long long> &arr, long long array_size) {
  vector<long long> temp(array_size);
  return _mergeSort(arr, temp, 0, array_size - 1);
}
long long _mergeSort(vector<long long> &arr, vector<long long> &temp,
                     long long left, long long right) {
  long long mid, inv_count = 0;
  if (right > left) {
    mid = (right + left) / 2;
    inv_count += _mergeSort(arr, temp, left, mid);
    inv_count += _mergeSort(arr, temp, mid + 1, right);
    inv_count += merge(arr, temp, left, mid + 1, right);
  }
  return inv_count;
}
long long merge(vector<long long> &arr, vector<long long> &temp, long long left,
                long long mid, long long right) {
  long long i, j, k;
  long long inv_count = 0;
  i = left;
  j = mid;
  k = left;
  while ((i <= mid - 1) && (j <= right)) {
    if (arr[i] <= arr[j]) {
      temp[k++] = arr[i++];
    } else {
      temp[k++] = arr[j++];
      inv_count = inv_count + (mid - i);
    }
  }
  while (i <= mid - 1) temp[k++] = arr[i++];
  while (j <= right) temp[k++] = arr[j++];
  for (i = left; i <= right; i++) arr[i] = temp[i];
  return inv_count;
}
int main() {
  long long tests = 1;
  while (tests--) {
    long long n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    long long result = 1;
    vector<long long> F, I;
    bool g = false;
    getFactorialsAndInverseModular(n, modular, F, I);
    for (int i = k - 1; i < n; ++i) {
      long long count_ones = 0;
      long long j = i;
      while (j >= 0 && count_ones != k) {
        count_ones += (s[j] == '1');
        --j;
      }
      if (count_ones == k) {
        while (j >= 0 && s[j] == '0') {
          --j;
        }
        if (i - j == k) {
          continue;
        }
        ++j;
        result += CnkMod(i - j + 1, k, modular, F, I);
        result %= modular;
        if (g) {
          if (s[i] == '0') {
            result += modular - CnkMod(i - j, k, modular, F, I);
          } else {
            result += modular - CnkMod(i - j, k - 1, modular, F, I);
          }
          result %= modular;
        } else {
          g = true;
        }
      } else {
        continue;
      }
    }
    if (!g) {
      cout << result << endl;
    } else {
      cout << result - 1 << endl;
    }
  }
}
