#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using qi = queue<int>;
using stki = stack<int>;
template <typename T>
using vec = vector<T>;
template <typename T>
using us = unordered_set<T>;
template <typename T>
using os = set<T>;
template <typename T>
using ms = multiset<T>;
template <typename T1, typename T2>
using um = unordered_map<T1, T2>;
template <typename T1, typename T2>
using om = map<T1, T2>;
template <typename T>
using pq = priority_queue<T>;
template <typename T>
using pqg = priority_queue<T, vec<T>, greater<T> >;
using vi = vec<int>;
using vpii = vec<pii>;
using vll = vec<ll>;
using vpll = vec<pll>;
using vb = vec<bool>;
const int INF = 0x3f3f3f3f;
const ll LLINF = 0x3f3f3f3f3f3f3f3f;
const int MOD = 1e9 + 7;
const int dir[8][2] = {{0, 1},  {0, -1}, {-1, 0},  {1, 0},
                       {-1, 1}, {1, -1}, {-1, -1}, {1, 1}};
struct Edge {
  int u, v, w;
};
namespace comfun {
template <typename T>
inline void cmax(T& u, T v) {
  u = max(u, v);
}
template <typename T>
inline void cmin(T& u, T v) {
  u = min(u, v);
}
template <typename T>
inline T lowbit(T x) {
  return x & (-x);
}
template <typename T>
inline T gcd(T a, T b) {
  if (a == 0) return b;
  if (b == 0) return a;
  return gcd(b, a % b);
}
template <typename T>
inline T lcm(T a, T b) {
  return a / gcd(a, b) * b;
}
template <typename T1, typename T2>
inline T1 fast_pow(T1 a, T2 b) {
  if (b == 1) return a;
  if (b == 0) return 1;
  T1 tmp = fast_pow(a, b >> 1);
  if (b & 1)
    return tmp * tmp * a;
  else
    return tmp * tmp;
}
template <typename T1, typename T2, typename T3>
inline T1 fast_pow(T1 a, T2 b, T3 m) {
  if (b == 1) return a % m;
  if (b == 0) return 1;
  T1 tmp = fast_pow(a, b >> 1, m);
  if (b & 1)
    return tmp * tmp % m * a % m;
  else
    return tmp * tmp % m;
}
template <typename T>
inline bool is_prime(T x) {
  if (x == 1) return false;
  for (T i = 2; i * i <= x; i++)
    if (x % i == 0) return false;
  return true;
}
}  // namespace comfun
namespace debug {
template <typename T>
inline void debugArray(T* arr, int sz) {
  cout << "[";
  for (int i = 0; i < sz; i++) {
    cout << arr[i] << ", ";
  }
  cout << "]\n";
}
template <typename T>
inline void printArray(T* arr, int sz) {
  for (int i = 0; i < sz; i++) {
    cout << arr[i] << " ";
  }
  cout << "\n";
}
}  // namespace debug
namespace fast_io {
void read(int& number) {
  bool negative = false;
  int c;
  number = 0;
  c = getchar();
  if (c == '-') {
    negative = true;
    c = getchar();
  }
  for (; (c > 47 && c < 58); c = getchar()) number = number * 10 + c - 48;
  if (negative) number *= -1;
}
}  // namespace fast_io
using namespace comfun;
using namespace debug;
using namespace fast_io;
inline void init1() {}
const int N = 2e5 + 10;
vi e[N];
int cnt[N];
inline void init2() {
  for (vi& i : e) i.clear();
  memset(cnt, 0, sizeof(cnt));
}
void dfs(int u, int fa) {
  if (e[u].size() == 1 && u != 1) {
    cnt[u]++;
    return;
  }
  bool flag = 1;
  for (int i = 0; i < e[u].size(); ++i) {
    int v = e[u][i];
    if (v == fa) continue;
    dfs(v, u);
    if (cnt[v] != 1) flag = 0;
    if (cnt[v] == -1) {
      e[u].erase(e[u].begin() + i);
      --i;
    }
  }
  if (flag && u != 1) {
    cnt[u]--;
  }
  if ((e[u].size() == 1 && u != 1) || (u == 1 && e[u].empty())) {
    if (cnt[u] == 1) return;
    cnt[u]++;
  }
}
inline void solve() {
  int n;
  cin >> n;
  for (int i = 1; i < n; i++) {
    int u, v;
    cin >> u >> v;
    e[u].push_back(v);
    e[v].push_back(u);
  }
  dfs(1, 0);
  int ans = 0;
  for (int i = 1; i <= n; i++) {
    ans += cnt[i];
  }
  cout << ans << '\n';
}
inline void setIO() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
}
int main() {
  setIO();
  init1();
  srand(time(0));
  int t;
  cin >> t;
  for (int i = 1; i <= t; i++) {
    if (0) cout << "Case #" << i << ": ";
    init2();
    solve();
  }
  string jack = "Jack is always within you";
  return 0;
}
