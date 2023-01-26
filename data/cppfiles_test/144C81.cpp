#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;
using vll = vector<ll>;
using vvll = vector<vll>;
using vb = vector<bool>;
using vvb = vector<vb>;
using vd = vector<double>;
using vs = vector<string>;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using pdd = pair<double, double>;
using vpii = vector<pii>;
using vpll = vector<pll>;
using vpdd = vector<pdd>;
template <typename T>
void ckmin(T &a, const T &b) {
  a = min(a, b);
}
template <typename T>
void ckmax(T &a, const T &b) {
  a = max(a, b);
}
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
namespace __input {
template <class T1, class T2>
void re(pair<T1, T2> &p);
template <class T>
void re(vector<T> &a);
template <class T, size_t SZ>
void re(array<T, SZ> &a);
template <class T>
void re(T &x) {
  cin >> x;
}
void re(double &x) {
  string t;
  re(t);
  x = stod(t);
}
template <class Arg, class... Args>
void re(Arg &first, Args &...rest) {
  re(first);
  re(rest...);
}
template <class T1, class T2>
void re(pair<T1, T2> &p) {
  re(p.first, p.second);
}
template <class T>
void re(vector<T> &a) {
  for (auto &x : a) re(x);
}
template <class T, size_t SZ>
void re(array<T, SZ> &a) {
  for (auto &x : a) re(x);
}
}  // namespace __input
using namespace __input;
namespace __output {
template <typename T>
struct is_outputtable {
  template <typename C>
  static constexpr decltype(declval<ostream &>() << declval<const C &>(),
                            bool())
  test(int) {
    return true;
  }
  template <typename C>
  static constexpr bool test(...) {
    return false;
  }
  static constexpr bool value = test<T>(int());
};
template <
    class T, typename V = decltype(declval<const T &>().begin()),
    typename S = typename enable_if<!is_outputtable<T>::value, bool>::type>
void pr(const T &x);
template <class T,
          typename V = decltype(declval<ostream &>() << declval<const T &>())>
void pr(const T &x) {
  cout << x;
}
template <class T1, class T2>
void pr(const pair<T1, T2> &x);
template <class Arg, class... Args>
void pr(const Arg &first, const Args &...rest) {
  pr(first);
  pr(rest...);
}
template <class T, bool pretty = true>
void prContain(const T &x) {
  if (pretty) pr("{");
  bool fst = 1;
  for (const auto &a : x) pr(!fst ? pretty ? ", " : " " : "", a), fst = 0;
  if (pretty) pr("}");
}
template <class T>
void pc(const T &x) {
  prContain<T, false>(x);
  pr("\n");
}
template <class T1, class T2>
void pr(const pair<T1, T2> &x) {
  pr("{", x.first, ", ", x.second, "}");
}
template <class T, typename V, typename S>
void pr(const T &x) {
  prContain(x);
}
void ps() { pr("\n"); }
template <class Arg>
void ps(const Arg &first) {
  pr(first);
  ps();
}
template <class Arg, class... Args>
void ps(const Arg &first, const Args &...rest) {
  pr(first, " ");
  ps(rest...);
}
}  // namespace __output
using namespace __output;
namespace __algorithm {
template <typename T>
void dedup(vector<T> &v) {
  sort((v).begin(), (v).end());
  v.erase(unique((v).begin(), (v).end()), v.end());
}
template <typename T>
typename vector<T>::const_iterator find(const vector<T> &v, const T &x) {
  auto it = lower_bound((v).begin(), (v).end(), x);
  return it != v.end() && *it == x ? it : v.end();
}
template <typename T>
size_t index(const vector<T> &v, const T &x) {
  auto it = find(v, x);
  assert(it != v.end() && *it == x);
  return it - v.begin();
}
template <typename I>
struct _reversed_struct {
  I &v_;
  explicit _reversed_struct(I &v) : v_{v} {}
  typename I::reverse_iterator begin() const { return v_.rbegin(); }
  typename I::reverse_iterator end() const { return v_.rend(); }
};
template <typename I>
_reversed_struct<I> reversed(I &v) {
  return _reversed_struct<I>(v);
}
template <typename I>
struct _range_struct {
  const I first_, last_;
  explicit _range_struct(const I first, const I last)
      : first_{first}, last_{last} {}
  I begin() const { return first_; }
  I end() const { return last_; }
};
template <typename I>
_range_struct<I> range(const I first, const I last) {
  return _range_struct<I>(first, last);
}
}  // namespace __algorithm
using namespace __algorithm;
namespace __io {
void setIO() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout << setprecision(15);
}
}  // namespace __io
using namespace __io;
void solve() {
  int n, m, k;
  re(n, m, k);
  int start = 0;
  vector<int> b(n);
  for (int game = 0; game < k; game++) {
    ;
    vvi tables(m);
    int big = n / m + 1;
    int small = n / m;
    int big_count = n - small * m;
    int small_count = m - big_count;
    int table_index = 0;
    for (int i = 0; i < n; i++) {
      tables[table_index].push_back((start + i) % n);
      if (int((tables[table_index]).size()) ==
          ((table_index < big_count) ? big : small))
        table_index++;
    };
    start = (start + big * big_count) % n;
    for (auto &t : tables) {
      if (int((t).size()) != n / m)
        for (auto i : t) b[i]++;
      for (auto &i : t) i++;
      pr(int((t).size()), " ");
      pc(t);
    }
  };
  ps();
}
int main() {
  setIO();
  int T;
  re(T);
  for (int t = 0; t < T; t++) solve();
  return 0;
}
