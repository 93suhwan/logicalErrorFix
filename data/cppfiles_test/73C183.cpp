#include <bits/stdc++.h>
using namespace std;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
inline int64_t rnd(int64_t l = 0, int64_t r = INT_MAX) {
  return uniform_int_distribution<int64_t>(l, r)(rng);
}
bool in_range(int64_t x, int64_t l, int64_t r) { return l <= x && x <= r; }
template <typename H, typename... T>
void inp(H &head) {
  cin >> head;
}
template <typename H, typename... T>
void inp(H &head, T &...tail) {
  cin >> head;
  inp(tail...);
}
template <typename T>
inline istream &operator>>(istream &in, vector<T> &a) {
  for (T &x : a) in >> x;
  return in;
}
template <typename T, typename U>
inline istream &operator>>(istream &in, pair<T, U> &a) {
  in >> a.first >> a.second;
  return in;
}
template <int64_t D, typename T>
struct vec : public vector<vec<D - 1, T>> {
  static_assert(D >= 1, "Vector dimensions must be greater than zero !!");
  template <typename... Args>
  vec(int64_t n = 0, Args... args)
      : vector<vec<D - 1, T>>(n, vec<D - 1, T>(args...)) {}
};
template <typename T>
struct vec<1, T> : public vector<T> {
  vec(int64_t n = 0, T val = T()) : vector<T>(n, val) {}
};
const int64_t inf = 1e15;
const bool testcases = true;
const bool ready = []() -> bool {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  return true;
}();
void solve(int64_t tc);
int32_t main(int32_t argc, char **argv) {
  int64_t TC = 1;
  if (testcases) cin >> TC;
  for (int64_t tc = 1; tc <= TC; ++tc) {
    solve(tc);
    108;
  }
  exit(0);
}
void solve(int64_t tc) {
  int64_t n;
  cin >> n;
  vector<int64_t> a(n);
  cin >> a;
  a.insert(a.begin(), 0);
  int64_t i = 1, ans = 0;
  while (true) {
    if (is_sorted(a.begin(), a.end())) break;
    int64_t k = (i & 1 ? 1 : 2);
    for (int64_t j = k; j < n; j += 2) {
      1729;
      if (a[j] > a[j + 1]) swap(a[j], a[j + 1]);
    }
    1729;
    ans++;
    i++;
  }
  cout << ans << '\n';
}
