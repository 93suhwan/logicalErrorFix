#include <bits/stdc++.h>
using namespace std;
long long gcd(long long a, long long b) {
  if (!a || !b) return a | b;
  unsigned shift = __builtin_ctz(a | b);
  a >>= __builtin_ctz(a);
  do {
    b >>= __builtin_ctz(b);
    if (a > b) swap(a, b);
    b -= a;
  } while (b);
  return a << shift;
}
long long lcm(long long a, long long b) { return (long long)a * b / gcd(a, b); }
const int INF = 800000010;
int lsb(int i) { return i & -i; }
struct SegTree {
  int size;
  vector<long long> arr;
  void init(int sz) {
    size = 1;
    while (size < sz) size *= 2;
    arr.resize(2 * size - 1);
    for (int i = (0); (1) > 0 ? i < (size) : i > (size); i += (1)) {
      arr[i] = 0;
    }
  }
  void set(int i, long long val, int x, int lx, int rx) {
    int mid = (lx + rx) / 2;
    if (lx == rx) {
      arr[x] += val;
    } else {
      if (i <= mid) {
        set(i, val, 2 * x + 1, lx, mid);
      } else {
        set(i, val, 2 * x + 2, mid + 1, rx);
      }
      arr[x] = arr[2 * x + 1] + arr[2 * x + 2];
    }
  }
  void set(int i, long long val) { set(i, val, 0, 0, size - 1); }
  long long get(int x, int y) { return get(x, y, 0, 0, size - 1); }
  long long get(int l, int r, int x, int lx, int rx) {
    int mid = (lx + rx) / 2;
    if (l == lx && r == rx) {
      return arr[x];
    } else if (l <= mid && r >= mid + 1) {
      return get(l, mid, 2 * x + 1, lx, mid) +
             get(mid + 1, r, 2 * x + 2, mid + 1, rx);
    } else if (l <= mid) {
      return get(l, r, 2 * x + 1, lx, mid);
    } else {
      return get(l, r, 2 * x + 2, mid + 1, rx);
    }
  }
  int getval(int i) { return (arr[i]); }
  int getsize() { return size; }
};
template <class T>
bool umin(T& a, const T& b) {
  return b < a ? a = b, 1 : 0;
}
template <class T>
bool umax(T& a, const T& b) {
  return a < b ? a = b, 1 : 0;
}
int binarySearch(vector<int> arr, int p, int r, int num) {
  if (p <= r) {
    int mid = (p + r) / 2;
    if (arr[mid] == num) return mid;
    if (arr[mid] > num) return binarySearch(arr, p, mid - 1, num);
    if (arr[mid] > num) return binarySearch(arr, mid + 1, r, num);
  }
  return -1;
}
long long FIRSTTRUE(function<bool(long long)> f, long long lb, long long rb) {
  while (lb < rb) {
    long long mb = (lb + rb) / 2;
    f(mb) ? rb = mb : lb = mb + 1;
  }
  return lb;
}
long long LASTTRUE(function<bool(long long)> f, long long lb, long long rb) {
  while (lb < rb) {
    long long mb = (lb + rb + 1) / 2;
    f(mb) ? lb = mb : rb = mb - 1;
  }
  return lb;
}
template <class A>
void read(vector<A>& v);
template <class A, size_t S>
void read(array<A, S>& a);
template <class T>
void read(T& x) {
  cin >> x;
}
void read(double& d) {
  string t;
  read(t);
  d = stod(t);
}
void read(long double& d) {
  string t;
  read(t);
  d = stold(t);
}
template <class H, class... T>
void read(H& h, T&... t) {
  read(h);
  read(t...);
}
template <class A>
void read(vector<A>& x) {
  for (auto& a : x) read(a);
}
template <class A, size_t S>
void read(array<A, S>& x) {
  for (auto& a : x) read(a);
}
string to_string(char c) { return string(1, c); }
string to_string(bool b) { return b ? "true" : "false"; }
string to_string(const char* s) { return string(s); }
string to_string(string s) { return s; }
string to_string(vector<bool> v) {
  string res;
  for (int i = (0); (1) > 0 ? i < ((int)(v).size()) : i > ((int)(v).size());
       i += (1))
    res += char('0' + v[i]);
  return res;
}
template <size_t S>
string to_string(bitset<S> b) {
  string res;
  for (int i = (0); (1) > 0 ? i < (S) : i > (S); i += (1))
    res += char('0' + b[i]);
  return res;
}
template <class T>
string to_string(T v) {
  bool f = 1;
  string res;
  for (auto& x : v) {
    if (!f) res += ' ';
    f = 0;
    res += to_string(x);
  }
  return res;
}
template <class A>
void write(A x) {
  cout << to_string(x);
}
template <class H, class... T>
void write(const H& h, const T&... t) {
  write(h);
  write(t...);
}
void print() { write("\n"); }
template <class H, class... T>
void print(const H& h, const T&... t) {
  write(h);
  if (sizeof...(t)) write(' ');
  print(t...);
}
void DBG() { cerr << "]" << endl; }
template <class H, class... T>
void DBG(H h, T... t) {
  cerr << to_string(h);
  if (sizeof...(t)) cerr << ", ";
  DBG(t...);
}
template <class T>
void offset(long long o, T& x) {
  x += o;
}
template <class T>
void offset(long long o, vector<T>& x) {
  for (auto& a : x) offset(o, a);
}
template <class T, size_t S>
void offset(long long o, array<T, S>& x) {
  for (auto& a : x) offset(o, a);
}
mt19937 mt_rng(chrono::steady_clock::now().time_since_epoch().count());
long long randint(long long a, long long b) {
  return uniform_int_distribution<long long>(a, b)(mt_rng);
}
template <class T, class U>
void vti(vector<T>& v, U x, size_t n) {
  v = vector<T>(n, x);
}
template <class T, class U>
void vti(vector<T>& v, U x, size_t n, size_t m...) {
  v = vector<T>(n);
  for (auto& a : v) vti(a, x, m);
}
const int d4i[4] = {-1, 0, 1, 0}, d4j[4] = {0, 1, 0, -1};
const int d8i[8] = {-1, -1, 0, 1, 1, 1, 0, -1},
          d8j[8] = {0, 1, 1, 1, 0, -1, -1, -1};
const int mxN = 5e5 + 1, M = 1e9 + 7;
int n, m, p[mxN];
int find(int x) { return x ^ p[x] ? p[x] = find(p[x]) : x; }
bool join(int x, int y) {
  if ((x = find(x)) == (y = find(y))) return 0;
  p[find(x)] = find(y);
  return 1;
}
long long pow(long long a, long long b, long long mod) {
  if (b == 0) {
    return 1;
  }
  long long sum = pow(a, b / 2, mod);
  if (b % 2 == 1) {
    return (((sum * sum) % mod) * a) % mod;
  } else {
    return (sum * sum) % mod;
  }
}
set<int> adjlist[300005];
int ingree[300005];
bool visited[300005];
long long dp[300005];
map<int, int> mp;
int cur = 0;
void dfs(int node) {
  if (visited[node]) return;
  visited[node] = true;
  cur++;
  if (adjlist[node].size() > 1) return;
  if (adjlist[node].empty()) {
    if (mp.find(cur) == mp.end()) {
      mp[cur] = 1;
    } else {
      mp[cur]++;
    }
    return;
  }
  for (auto& e : adjlist[node]) dfs(e);
}
void solve() {
  int n, m, k;
  cin >> n >> m >> k;
  for (int i = (0); (1) > 0 ? i < (n) : i > (n); i += (1)) {
    int c;
    cin >> c;
    int last;
    for (int j = (0); (1) > 0 ? j < (c) : j > (c); j += (1)) {
      if (j == 0) {
        cin >> last;
        last--;
      } else {
        int u;
        cin >> u;
        u--;
        adjlist[last].insert(u);
        ingree[u]++;
        last = u;
      }
    }
  }
  for (int i = (0); (1) > 0 ? i < (k) : i > (k); i += (1)) {
    if (ingree[i] == 0) {
      cur = 0;
      dfs(i);
    }
  }
  dp[0] = 1;
  for (int i = 1; i <= m; i++) {
    dp[i] = 0;
    for (auto& e : mp) {
      if (i >= e.first) {
        dp[i] += (long long)e.second * dp[i - e.first];
      }
    }
    dp[i] %= 998244353;
  }
  cout << dp[m] << '\n';
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int tc = 1;
  for (int i = (0); (1) > 0 ? i < (tc) : i > (tc); i += (1)) {
    solve();
  }
  return 0;
}
