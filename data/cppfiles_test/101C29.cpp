#include <bits/stdc++.h>
#pragma GCC optimize("Ofast", "unroll-loops")
using namespace std;
void __print(int x) { cerr << x; }
void __print(long x) { cerr << x; }
void __print(long long x) { cerr << x; }
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
template <typename T, typename V>
void __print(const pair<T, V> &x) {
  cerr << '{';
  __print(x.first);
  cerr << ',';
  __print(x.second);
  cerr << '}';
}
template <typename T>
void __print(const T &x) {
  int f = 0;
  cerr << '{';
  for (auto &i : x) {
    cerr << (f++ ? "," : "");
    __print(i);
  }
  cerr << "}";
}
void _print() { cerr << "]\n"; }
template <typename T, typename... V>
void _print(T t, V... v) {
  __print(t);
  if (sizeof...(v)) cerr << ", ";
  _print(v...);
}
struct custom_hash {
  static uint64_t splitmix64(uint64_t x) {
    x += 0x9e3779b97f4a7c15;
    x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
    x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
    return x ^ (x >> 31);
  }
  size_t operator()(uint64_t x) const {
    static const uint64_t FIXED_RANDOM =
        chrono::steady_clock::now().time_since_epoch().count();
    return splitmix64(x + FIXED_RANDOM);
  }
};
const long long mod = 1e9 + 7;
const long double PI = 3.14159265358979;
inline long long add(long long x, long long y) {
  x += y;
  if (x >= mod) x -= mod;
  return x;
}
inline long long mul(long long x, long long y) {
  x *= y;
  if (x >= mod) x %= mod;
  return x;
}
long long power(long long x, long long y) {
  long long res = 1;
  x = x % mod;
  if (x == 0) return 0;
  while (y > 0) {
    if (y & 1) res = (res * x) % mod;
    y = y >> 1;
    x = (x * x) % mod;
  }
  return res;
}
void solve() {
  int n, m, k;
  cin >> n >> m >> k;
  vector<int> X(n), Y(m);
  for (int i = 0; i < n; i++) cin >> X[i];
  for (int i = 0; i < m; i++) cin >> Y[i];
  vector<pair<int, int> > points(k);
  for (int i = 0; i < k; i++) cin >> points[i].first >> points[i].second;
  sort(points.begin(), points.end(),
       [&](const pair<int, int> &a, const pair<int, int> &b) {
         return a.second < b.second;
       });
  long long ans = 0;
  int j = 0;
  for (int i = 0; i < m; i++) {
    int z = j;
    map<int, long long> found;
    while (z < k and points[z].second < Y[i]) {
      found[points[z].first]++;
      z++;
    }
    long long temp = 0;
    for (auto &a : found) temp += (a.second * (a.second - 1)) / 2;
    ans += (((long long)z - j) * (z - j - 1)) / 2 - temp;
    j = z;
    while (j < k and points[j].second == Y[i]) j++;
    if (j >= k) break;
  }
  sort(points.begin(), points.end(),
       [&](const pair<int, int> &a, const pair<int, int> &b) {
         return a.first < b.first;
       });
  j = 0;
  for (int i = 0; i < n; i++) {
    int z = j;
    map<int, long long> found;
    while (z < k and points[z].first < X[i]) {
      found[points[z].second]++;
      z++;
    }
    long long temp = 0;
    for (auto &a : found) temp += (a.second * (a.second - 1)) / 2;
    ans += (((long long)z - j) * (z - j - 1)) / 2 - temp;
    j = z;
    while (j < k and points[j].first == X[i]) j++;
    if (j >= k) break;
  }
  cout << ans;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int tt = 1;
  cin >> tt;
  while (tt) {
    solve();
    cout << '\n';
    tt--;
  }
  return 0;
}
