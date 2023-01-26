#include <bits/stdc++.h>
using namespace std;
template <class T>
using pq = priority_queue<T>;
template <class T>
using pqg = priority_queue<T, vector<T>, greater<T>>;
template <class T>
inline bool ckmin(T& a, const T& b) {
  return b < a ? a = b, 1 : 0;
}
template <class T>
inline bool ckmax(T& a, const T& b) {
  return a < b ? a = b, 1 : 0;
}
template <typename T, typename U>
istream& operator>>(istream& is, pair<T, U>& p) {
  is >> p.first >> p.second;
  return is;
}
template <typename T, typename U>
ostream& operator<<(ostream& os, const pair<T, U>& p) {
  os << p.first << ' ' << p.second;
  return os;
}
template <typename T>
istream& operator>>(istream& is, vector<T>& v) {
  for (auto& i : v) is >> i;
  return is;
}
template <typename T>
ostream& operator<<(ostream& os, const vector<T>& v) {
  int f = 0;
  for (auto& i : v) {
    if (f++) os << ' ';
    os << i;
  }
  return os;
}
template <typename T>
vector<T>& operator--(vector<T>& v) {
  for (auto& i : v) --i;
  return v;
}
template <typename T>
vector<T>& operator++(vector<T>& v) {
  for (auto& i : v) ++i;
  return v;
}
template <typename T, typename Iter>
int find_position(Iter b, Iter e, const T& x) {
  auto it = lower_bound(b, e, x);
  if (it != e && *it == x) {
    return it - b;
  } else {
    return -1;
  }
}
template <typename T>
inline T median(T a, T b, T c) {
  return 1LL * (a + b + c) - max({a, b, c}) - min({a, b, c});
}
template <typename T>
inline long long max(const T& v) {
  return *max_element(v.begin(), v.end());
}
template <typename T>
inline long long min(const T& v) {
  return *min_element(v.begin(), v.end());
}
template <typename T>
inline long long sum(const T& v) {
  return accumulate(v.begin(), v.end(), 0LL);
}
constexpr int pct(int x) { return __builtin_popcount(x); }
constexpr int bits(int x) { return x == 0 ? 0 : 31 - __builtin_clz(x); }
long long cdiv(long long a, long long b) {
  return a / b + ((a ^ b) > 0 && a % b);
}
long long fdiv(long long a, long long b) {
  return a / b - ((a ^ b) < 0 && a % b);
}
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
const int SIZE = 1 << 19;
const long long infll = (long long)1e18;
const int inf = 0x3f3f3f3f;
void solve() {
  int N, M;
  cin >> N >> M;
  string S;
  cin >> S;
  string base = "abc";
  vector<vector<int>> prefix_diff(6, vector<int>(N + 1));
  for (int i = 0; i < 6; ++i) {
    int times = N / 3;
    int rem = N % 3;
    string T;
    for (int t = (0); t < (times); ++t) T += base;
    for (int r = (0); r < (rem); ++r) T += base[r];
    cerr << T << '\n';
    for (int j = 0; j < N; ++j) {
      prefix_diff[i][j + 1] = prefix_diff[i][j] + (T[j] != S[j]);
    }
    next_permutation((base).begin(), (base).end());
  }
  while (M--) {
    int L, R;
    cin >> L >> R;
    int ans = inf;
    for (int i = (0); i < (6); ++i) {
      ckmin(ans, prefix_diff[i][R] - prefix_diff[i][L - 1]);
    }
    cout << ans << '\n';
  }
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt = 1;
  while (tt--) {
    solve();
  }
  return 0;
}
