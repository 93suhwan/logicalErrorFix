#include <bits/stdc++.h>
using namespace std;
using ull = unsigned long long;
using ll = long long;
using ld = long double;
string to_string(char s) {
  string res = "'''";
  res[1] = s;
  return res;
}
string to_string(string s) { return '"' + s + '"'; }
string to_string(const char* s) { return to_string((string)s); }
string to_string(bool b) { return (b ? "true" : "false"); }
template <typename A, typename B>
string to_string(pair<A, B> p) {
  return "(" + to_string(p.first) + ", " + to_string(p.second) + ")";
}
template <typename A>
string to_string(A v) {
  bool first = 1;
  string res = "{";
  for (const auto& x : v) {
    if (!first) res += ", ";
    first = 0;
    res += to_string(x);
  }
  res += "}";
  return res;
}
void debug() { cout << "\n"; }
template <typename Head, typename... Tail>
void debug(Head H, Tail... T) {
  cout << " " << to_string(H);
  debug(T...);
}
const long long int MOD = 1e9 + 7;
inline long long int add(long long int a, long long int b,
                         long long int p = MOD) {
  a = a + b;
  if (a >= p) a -= p;
  return a;
}
inline long long int sub(long long int a, long long int b,
                         long long int p = MOD) {
  a = a - b;
  if (a < 0) a += p;
  return a;
}
inline long long int mul(long long int a, long long int b,
                         long long int p = MOD) {
  a = (a * 1ll * b) % p;
  return a;
}
const ld pi = acos(-1), eps = 1e-9;
const ll inf = 1e18;
const long long int N = 1e2 + 5;
long long int n, m, k;
long long int mat[N][N];
bool vis[N][N];
char ans[N][N];
bool mark[26];
long long int dx[] = {1, -1, 0, 0};
long long int dy[] = {0, 0, 1, -1};
bool valid(long long int x, long long int y) {
  return (x >= 0 && x < n && y >= 0 && y < m);
}
void cover(long long int x, long long int y) {
  for (long long int i = 0; i < (4); ++i) {
    long long int nx = x + dx[i];
    long long int ny = y + dy[i];
    if (valid(nx, ny) && vis[nx][ny]) mark[ans[nx][ny] - 'a'] = true;
  }
}
void insertLetters() {
  for (long long int i = 0; i < (n); ++i) {
    for (long long int j = 0; j < (m); ++j) {
      if (vis[i][j]) continue;
      if (j + 1 < m && mat[i][j] == mat[i][j + 1]) {
        memset(mark, 0, sizeof(mark));
        cover(i, j);
        cover(i, j + 1);
        for (long long int l = 0; l < (26); ++l) {
          if (mark[l]) continue;
          ans[i][j] = ans[i][j + 1] = l + 'a';
          break;
        }
        vis[i][j] = vis[i][j + 1] = true;
      } else {
        memset(mark, 0, sizeof(mark));
        cover(i, j);
        cover(i + 1, j);
        for (long long int l = 0; l < (26); ++l) {
          if (mark[l]) continue;
          ans[i][j] = ans[i + 1][j] = l + 'a';
          break;
        }
        vis[i][j] = vis[i + 1][j] = true;
      }
    }
  }
}
void computeMatrix(long long int toFill) {
  long long int cnt = 1;
  for (long long int i = 0; i < toFill; ++i) {
    for (long long int j = 0; j < m; j += 2) mat[i][j] = mat[i][j + 1] = cnt++;
  }
  long long int rem = k - toFill * (m / 2);
  for (long long int i = toFill; i < n && rem; i += 2) {
    long long int cur = min(rem / 2, m / 2);
    for (long long int j = 0, z = cur; j < m && z; j += 2, --z) {
      for (long long int l = (i); l <= (i + 1); ++l)
        mat[l][j] = mat[l][j + 1] = cnt++;
    }
    rem -= cur * 2;
  }
  for (long long int i = 0; i < (n - 1); ++i) {
    for (long long int j = 0; j < (m); ++j) {
      if (mat[i][j] == 0 && mat[i + 1][j] == 0)
        mat[i][j] = mat[i + 1][j] = cnt++;
    }
  }
  insertLetters();
  for (long long int i = 0; i < (n); ++i) {
    for (long long int j = 0; j < (m); ++j) cout << ans[i][j];
    cout << "\n";
  }
}
void solve() {
  memset(mat, 0, sizeof(mat));
  memset(vis, 0, sizeof(vis));
  cin >> n >> m >> k;
  long long int start = (n % 2 == 0) ? 0 : 1;
  for (long long int i = start; i <= n; i += 2) {
    long long int rem = k - i * (m / 2);
    long long int tot = ((n - i) * (m - m % 2)) / 2;
    if (rem >= 0 && rem <= tot && rem % 2 == 0) {
      cout << "YES\n";
      computeMatrix(i);
      return;
    }
  }
  cout << "NO\n";
}
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  ;
  long long int t = 1;
  cin >> t;
  for (long long int z = 1; z <= t; ++z) {
    solve();
  }
  return 0;
}
