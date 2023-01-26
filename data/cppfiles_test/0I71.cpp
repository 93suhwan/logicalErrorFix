#include <bits/stdc++.h>
using namespace std;
int mon[20] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
long long gcd(long long x, long long y) {
  return ((y == 0) ? x : gcd(y, x % y));
}
inline int read() {
  int x = 0;
  char ch = getchar();
  while (ch < '0' || ch > '9') ch = getchar();
  while (ch >= '0' && ch <= '9') {
    x = x * 10 + ch - '0';
    ch = getchar();
  }
  return x;
}
const int GJMAX = 1005;
struct Int {
  int a[GJMAX];
  int len;
  Int(int k) { *this = k; }
  Int() { *this = 0; }
  void clean() {
    while (len > 1 && !a[len - 1]) len--;
  }
  void operator=(int k) {
    if (!k) {
      len = 1;
      a[0] = 0;
      return;
    }
    len = 0;
    while (k) a[len++] = k % 10, k /= 10;
  }
  void operator=(string k) {
    len = k.length();
    for (int i = 0; i < len; i++) {
      a[i] = k[len - i - 1] - '0';
    }
  }
  Int operator+(Int &B) {
    Int C;
    C.len = len > B.len ? len : B.len;
    for (int i = len; i < C.len; i++) a[i] = 0;
    for (int i = B.len; i < C.len; i++) B.a[i] = 0;
    int d = 0;
    for (int i = 0; i < C.len; i++) {
      C.a[i] = a[i] + B.a[i] + d;
      d = C.a[i] / 10;
      C.a[i] %= 10;
    }
    if (d) C.a[C.len++] = d;
    return C;
  }
  Int operator+=(Int B) {
    *this = *this + B;
    return *this;
  }
  Int operator+(int &b) {
    Int B = b;
    return *this + B;
  }
  Int operator+(const int &b) {
    Int B = b;
    return *this + B;
  }
  Int operator-(Int &B) {
    Int C;
    C.len = len;
    for (int i = B.len; i < C.len; i++) B.a[i] = 0;
    int d = 0;
    for (int i = 0; i < C.len; i++) {
      C.a[i] = a[i] - B.a[i] - d;
      d = 0;
      while (C.a[i] < 0) d++, C.a[i] += 10;
    }
    while (C.len > 0 && !C.a[C.len - 1]) C.len--;
    if (C.len == 0) C = 0;
    return C;
  }
  Int operator-=(Int B) {
    *this = *this - B;
    return *this;
  }
  Int operator-(int &b) {
    Int B = b;
    return *this - B;
  }
  Int operator-(const int &b) {
    Int B = b;
    return *this - B;
  }
  Int operator*(Int &B) {
    int i, j;
    Int C;
    C.len = len + B.len;
    for (j = 0; j < B.len; j++)
      for (i = 0; i < len; i++) C.a[i + j] += a[i] * B.a[j];
    for (i = 0; i < C.len - 1; i++) C.a[i + 1] += C.a[i] / 10, C.a[i] %= 10;
    C.clean();
    return C;
  }
  Int operator*=(Int B) {
    *this = *this * B;
    return *this;
  }
  Int operator*(int &b) {
    Int B = b;
    return *this * B;
  }
  Int operator*(const int &b) {
    Int B = b;
    return *this * B;
  }
  Int operator*=(int b) {
    *this = *this * b;
    return *this;
  }
  Int operator/(Int &b) {
    int i, j;
    Int c = *this, d = 0;
    for (i = len - 1; i >= 0; i--) {
      d = d * 10 + a[i];
      for (j = 0; j < 10; j++)
        if (d < b * (j + 1)) break;
      c.a[i] = j;
      d -= b * j;
    }
    c.clean();
    return c;
  }
  Int operator/(const int &b) {
    Int B = b;
    return *this / B;
  }
  Int operator/=(Int B) {
    *this = *this / B;
    return *this;
  }
  Int operator/(int &b) {
    Int B = b;
    return *this / B;
  }
  Int operator/=(int b) {
    *this = *this / b;
    return *this;
  }
  Int operator%(Int &b) {
    int i, j;
    Int d = 0;
    for (i = len - 1; i >= 0; i--) {
      d = d * 10 + a[i];
      for (j = 0; j < 10; j++)
        if (d < b * (j + 1)) break;
      d -= b * j;
    }
    return d;
  }
  Int operator%=(Int B) {
    *this = *this % B;
    return *this;
  }
  bool operator<=(Int B) {
    if (len < B.len) return 1;
    if (len > B.len) return 0;
    for (int i = len - 1; i >= 0; i--) {
      if (a[i] < B.a[i]) return 1;
      if (a[i] > B.a[i]) return 0;
    }
    return 1;
  }
  bool operator<(Int B) {
    if (len < B.len) return 1;
    if (len > B.len) return 0;
    for (int i = len - 1; i >= 0; i--) {
      if (a[i] < B.a[i]) return 1;
      if (a[i] > B.a[i]) return 0;
    }
    return 0;
  }
  bool operator>(Int B) { return !(*this <= B); }
  bool operator>=(Int B) { return !(*this < B); }
  bool operator==(Int B) { return *this <= B && *this >= B; }
  bool operator!=(Int B) { return !(*this == B); }
  bool zero() { return len == 1 && a[0] == 0; }
  void printout() {
    for (int i = len - 1; i >= 0; i--) printf("%d", a[i]);
  }
  string str() const {
    char s[GJMAX] = {};
    for (int i = 0; i < len; i++) s[len - 1 - i] = a[i] + '0';
    return s;
  }
};
istream &operator>>(istream &in, Int &x) {
  string s;
  in >> s;
  x = s.c_str();
  return in;
}
ostream &operator<<(ostream &out, const Int &x) {
  out << x.str();
  return out;
}
const int maxn = 200005;
int c[maxn];
int n, m;
int dp[maxn];
map<pair<int, int>, int> dis;
int u, v, w;
bool vis[maxn];
vector<int> vec[maxn];
int ans = 0;
int INF = 0x3f3f3f3f;
void work(stack<int> path) {
  u = path.top();
  path.pop();
  dp[u] = INF;
  while (path.size()) {
    v = path.top();
    path.pop();
    dp[v] = min(dp[u] - c[v], dis[make_pair(v, u)]);
    u = v;
  }
  ans = max(ans, dp[1]);
}
stack<int> path;
void dfs(int idx, int step) {
  if (step == n) {
    work(path);
    return;
  }
  vis[idx] = 1;
  for (int i = 0; i < vec[idx].size(); i++) {
    u = vec[idx][i];
    if (!vis[u]) path.push(u), dfs(u, step + 1), path.pop();
  }
}
void solve() {
  cin >> n >> m;
  path.push(1);
  for (int i = 1; i <= n; i++) cin >> c[i];
  for (int i = 1; i <= m; i++) {
    cin >> u >> v >> w;
    vec[u].push_back(v);
    vec[v].push_back(u);
    dis[make_pair(u, v)] = w - c[u];
    dis[make_pair(v, u)] = w - c[v];
  }
  dfs(1, 1);
  if (ans > 0) {
    cout << ans;
  } else
    cout << -1;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int t;
  t = 1;
  while (t--) solve();
  return 0;
}
