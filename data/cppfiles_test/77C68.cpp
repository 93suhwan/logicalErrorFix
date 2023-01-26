#include <bits/stdc++.h>
using namespace std;
void _print(long long t) { cerr << t; }
void _print(int t) { cerr << t; }
void _print(string t) { cerr << t; }
void _print(char t) { cerr << t; }
void _print(long double t) { cerr << t; }
void _print(double t) { cerr << t; }
void _print(unsigned long long t) { cerr << t; }
template <class T, class V>
void _print(pair<T, V> p);
template <class T>
void _print(vector<T> v);
template <class T>
void _print(set<T> v);
template <class T, class V>
void _print(map<T, V> v);
template <class T>
void _print(multiset<T> v);
template <class T, class V>
void _print(pair<T, V> p) {
  cerr << "{";
  _print(p.first);
  cerr << ",";
  _print(p.second);
  cerr << "}";
}
template <class T>
void _print(vector<T> v) {
  cerr << "[ ";
  for (T i : v) {
    _print(i);
    cerr << " ";
  }
  cerr << "]";
}
template <class T>
void _print(set<T> v) {
  cerr << "[ ";
  for (T i : v) {
    _print(i);
    cerr << " ";
  }
  cerr << "]";
}
template <class T>
void _print(multiset<T> v) {
  cerr << "[ ";
  for (T i : v) {
    _print(i);
    cerr << " ";
  }
  cerr << "]";
}
template <class T, class V>
void _print(map<T, V> v) {
  cerr << "[ ";
  for (auto i : v) {
    _print(i);
    cerr << " ";
  }
  cerr << "]";
}
int dx8[] = {0, 0, 1, 1, 1, -1, -1, -1};
int dy8[] = {1, -1, 1, -1, 0, 0, -1, 1};
int dx4[] = {-1, 0, 1, 0};
int dy4[] = {0, 1, 0, -1};
const int maxx = 1003;
const long long MOD = 1000000007;
const double rad = (acos(-1) / 180.00);
const int INF = 0x3f3f3f3f;
const long long LL_INF = 0x3f3f3f3f3f3f3f3f;
const long long negInf = -1e18;
const long long posInf = 1e18;
inline void normal(long long &a) {
  a %= MOD;
  (a < 0) && (a += MOD);
}
inline long long modMul(long long a, long long b) {
  a %= MOD, b %= MOD;
  normal(a), normal(b);
  return (a * b) % MOD;
}
inline long long modAdd(long long a, long long b) {
  a %= MOD, b %= MOD;
  normal(a), normal(b);
  return (a + b) % MOD;
}
inline long long modSub(long long a, long long b) {
  a %= MOD, b %= MOD;
  normal(a), normal(b);
  a -= b;
  normal(a);
  return a;
}
inline long long modPow(long long b, long long p) {
  long long r = 1;
  while (p) {
    if (p & 1) r = modMul(r, b);
    b = modMul(b, b);
    p >>= 1;
  }
  return r;
}
inline long long modInverse(long long a) { return modPow(a, MOD - 2); }
inline long long modDiv(long long a, long long b) {
  return modMul(a, modInverse(b));
}
long long gcd(long long a, long long b) {
  if (a == 0) return b;
  return gcd(b % a, a);
}
long long lcm(long long a, long long b) { return (a * b) / gcd(a, b); }
double sq(double x) { return x * x; }
long long po(long long b, long long p) {
  long long res = 1;
  while (p) {
    res *= b;
    p--;
  }
  return res;
}
long long lg2(long long x) {
  long long res = 0;
  while (x > 1) {
    res++;
    x /= 2ll;
  }
  return res;
}
bool get_bit(int mask, int pos) { return mask & (1 << pos); }
bool sortinrev(const pair<int, int> &a, const pair<int, int> &b) {
  return a.first > b.first;
}
int cs = 0;
int n, m;
int mat[maxx][maxx], vis[maxx][maxx];
int cnt = 0;
void dfs(int i, int j) {
  vis[i][j] = 1;
  cnt++;
  for (int k = 0; k < 4; k++) {
    int newi = dx4[k] + i, newj = dy4[k] + j;
    if (((newi >= 0 && newi < n) && (newj >= 0 && newj < m)) and
        !(mat[i][j] & (1 << (4 - k - 1))) and vis[newi][newj] == 0) {
      dfs(newi, newj);
    }
  }
}
void solve() {
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> mat[i][j];
    }
  }
  vector<int> ans;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (!vis[i][j]) {
        cnt = 0;
        dfs(i, j);
        ans.push_back(cnt);
      }
    }
  }
  sort(ans.begin(), ans.end());
  reverse(ans.begin(), ans.end());
  for (auto it : ans) cout << it << " ";
  cout << "\n";
}
signed main() {
  ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
  ;
  int t;
  t = 1;
  while (t--) {
    solve();
  }
  return 0;
}
