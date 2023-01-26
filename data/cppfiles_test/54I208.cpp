#include <bits/stdc++.h>
using namespace std;
template <class t, class u>
void mxz(t &a, u b) {
  if (a < b) a = b;
}
template <class t, class u>
void mnz(t &a, u b) {
  if (b < a) a = b;
}
template <typename T, typename U, typename V, typename W>
void mxz(T &a, U b, V &max_arg, W arg) {
  if (a < b) {
    a = b;
    max_arg = arg;
  }
}
template <typename T, typename U, typename V, typename W>
void mnz(T &a, U b, V &min_arg, W arg) {
  if (a > b) {
    a = b;
    min_arg = arg;
  }
}
void fastIO() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
}
void _scan(unsigned long long &x) { scanf("%llu", &x); }
void _scan(int &x) { scanf("%d", &x); }
void _scan(long long &x) { scanf("%lld", &x); }
void _scan(double &x) { scanf("%lf", &x); }
void _scan(char &x) { scanf(" %c", &x); }
void _scan(char *x) { scanf("%s", x); }
template <typename T>
void _scan(T &v) {
  for (auto &it : v) _scan(it);
}
void scan() {}
template <typename T, typename... U>
void scan(T &head, U &...tail) {
  _scan(head);
  scan(tail...);
}
void _print(long double x) { printf("%Lf", x); }
void _print(unsigned long long x) { printf("%llu", x); }
void _print(int x) { printf("%d", x); }
void _print(long long x) { printf("%lld", x); }
void _print(double x) { printf("%0.10lf", x); }
void _print(char x) { printf("%c", x); }
void _print(char *x) { printf("%s", x); }
void _print(string x) { printf("%s", x.c_str()); }
void _print(bool x) { printf("%s", (x) ? "YES" : "NO"); }
template <typename T, typename V>
void _print(const pair<T, V> &x) {
  _print(x.first);
  _print(' ');
  _print(x.second);
}
template <typename T>
void _print(const T &x) {
  int f = 0;
  for (auto &i : x) {
    if (f++) _print(' ');
    _print(i);
  }
}
void print() {}
template <typename T, typename... U>
void print(T head, U... tail) {
  _print(head);
  print(tail...);
}
inline long long flr(long long x, long long y);
inline long long cil(long long x, long long y) {
  assert(y != 0);
  if (y < 0LL) {
    y *= -1LL;
    x *= -1LL;
  }
  return (x < 0LL) ? -1 * flr(-1 * x, y) : (x + y - 1) / y;
}
inline long long flr(long long x, long long y) {
  assert(y != 0);
  if (y < 0LL) {
    y *= -1LL;
    x *= -1LL;
  }
  return (x < 0LL) ? -1 * cil(-1 * x, y) : x / y;
}
inline long long di(long long x, long long y) {
  assert(y != 0);
  assert(!(x % y));
  return x / y;
}
inline long long mod(long long x, long long y) {
  assert(y != 0);
  return x % y;
}
template <typename T>
inline void decr(T &x) {
  for (auto &it : x) it = it - 1;
}
void ___print(int x) { cerr << x; }
void ___print(long x) { cerr << x; }
void ___print(long long x) { cerr << x; }
void ___print(unsigned x) { cerr << x; }
void ___print(unsigned long x) { cerr << x; }
void ___print(unsigned long long x) { cerr << x; }
void ___print(float x) { cerr << x; }
void ___print(double x) { cerr << x; }
void ___print(long double x) { cerr << x; }
void ___print(char x) { cerr << '\'' << x << '\''; }
void ___print(const char *x) { cerr << '\"' << x << '\"'; }
void ___print(const string &x) { cerr << '\"' << x << '\"'; }
void ___print(bool x) { cerr << (x ? "true" : "false"); }
template <typename T, typename V>
void ___print(const pair<T, V> &x) {
  cerr << '{';
  ___print(x.first);
  cerr << ',';
  ___print(x.second);
  cerr << '}';
}
template <typename T>
void ___print(const T &x) {
  int f = 0;
  cerr << '{';
  for (auto &i : x) cerr << (f++ ? "," : ""), ___print(i);
  cerr << "}";
}
void __print() { cerr << "]\n"; }
template <typename T, typename... V>
void __print(T t, V... v) {
  ___print(t);
  if (sizeof...(v)) cerr << ", ";
  __print(v...);
}
const int MAXN = 2e5 + 3;
int n, m;
vector<pair<int, int> > G[MAXN];
int fin[2];
set<pair<pair<int, int>, int> > edges;
vector<int> col;
bool dfs(int fro, int color, vector<int> &clean_list) {
  col[fro] = color;
  clean_list.emplace_back(fro);
  fin[color]++;
  bool ok = false;
  for (auto e : G[fro]) {
    int to = e.first;
    int trans = e.second;
    int to_color = trans ^ color;
    if (col[to] == -1) {
      ok |= dfs(to, to_color, clean_list);
    } else {
      if (col[to] != to_color) ok = true;
    }
  }
  return ok;
}
void solve() {
  cin >> n >> m;
  edges.clear();
  col.clear();
  for (int i = 0; i < n; ++i) G[i].clear();
  bool ok = true;
  while (m--) {
    int u, v;
    string s;
    cin >> u >> v;
    --u;
    --v;
    cin >> s;
    if (s[0] == 'i') {
      if (edges.count(make_pair(make_pair(u, v), 0)) == 1) {
        ok = false;
      }
      if (edges.count(make_pair(make_pair(u, v), 1)) == 1) {
        continue;
      }
      G[u].emplace_back(make_pair(v, 1));
      edges.insert(make_pair(make_pair(u, v), 1));
    } else {
      if (edges.count(make_pair(make_pair(u, v), 1)) == 1) {
        ok = false;
      }
      if (edges.count(make_pair(make_pair(u, v), 0)) == 1) {
        continue;
      }
      G[u].emplace_back(make_pair(v, 0));
      edges.insert(make_pair(make_pair(u, v), 0));
    }
  }
  if (!ok) {
    cout << -1 << endl;
    return;
  }
  col.assign(n, -1);
  ok = false;
  long long res = 0ll;
  for (int i = 0; i < n; ++i) {
    if (col[i] == -1) {
      int ans = 0;
      fin[0] = fin[1] = 0;
      vector<int> clean_list;
      bool op1 = dfs(i, 0, clean_list);
      if (!op1) ans = max(ans, fin[1]);
      for (int x : clean_list) col[x] = -1;
      clean_list.clear();
      fin[0] = fin[1] = 0;
      bool op2 = dfs(i, 1, clean_list);
      if (!op2) ans = max(ans, fin[1]);
      if (op1 && op2) {
        ok = true;
      } else
        res += ans;
    }
    if (ok) {
      cout << -1 << endl;
      return;
    }
  }
  cout << res << endl;
}
int main() {
  int t;
  fastIO();
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
