#include <bits/stdc++.h>
using namespace std;
template <typename T, typename U>
void min_self(T &x, U y) {
  if (y < x) x = y;
}
template <typename T, typename U>
void max_self(T &x, U y) {
  if (y > x) x = y;
}
template <typename T, typename U>
ostream &operator<<(ostream &os, const pair<T, U> &p) {
  return os << '(' << p.first << ", " << p.second << ')';
}
template <typename T_container, typename T = typename enable_if<
                                    !is_same<T_container, string>::value,
                                    typename T_container::value_type>::type>
ostream &operator<<(ostream &os, const T_container &a) {
  os << '{';
  string sep;
  for (const T &x : a) os << sep << x, sep = ", ";
  return os << '}';
}
void debug() { cerr << endl; }
template <typename Head, typename... Tail>
void debug(Head h, Tail... t) {
  cerr << h << ' ';
  debug(t...);
}
const int64_t MX = 2e5, MOD = 1e9 + 7, MOD2 = 998244353, INF = 1e18;
int64_t n;
vector<pair<int64_t, int64_t>> caves;
bool works(int64_t health) {
  for (auto &[minstart, increase] : caves) {
    if (health < minstart) return false;
    health += increase;
  }
  return true;
}
void solve() {
  cin >> n;
  for (int64_t i = 0; i < n; ++i) {
    int64_t k;
    cin >> k;
    int64_t maxai = 0;
    for (int64_t j = 0; j < k; ++j) {
      int64_t aj;
      cin >> aj;
      max_self(maxai, aj - j);
    }
    caves.emplace_back(make_pair(maxai + 1, k));
  }
  sort(begin(caves), end(caves),
       [](pair<int64_t, int64_t> &a, pair<int64_t, int64_t> &b) {
         if (a.first == b.first) return a.second > b.second;
         return a.first < b.first;
       });
  int64_t health = 0;
  int64_t gaps = 0;
  for (auto &[start, increase] : caves) {
    if (health < start) {
      gaps += start - health;
      health = start;
    }
    health += increase;
  }
  cout << gaps << '\n';
  caves.clear();
}
int32_t main() {
  ios::sync_with_stdio(false), cin.tie(NULL);
  int64_t tc = 1;
  cin >> tc;
  while (tc--) solve();
}
