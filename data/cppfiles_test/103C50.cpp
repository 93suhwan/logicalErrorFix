#include <bits/stdc++.h>
using namespace std;
bool CustomCompareF(const pair<long long int, long long int> &,
                    const pair<long long int, long long int> &);
struct CustomCompareS {
  bool operator()(const pair<long long int, long long int> &,
                  const pair<long long int, long long int> &);
};
long long int modmul(long long int, long long int);
long long int modadd(long long int, long long int);
long long int modsub(long long int, long long int);
long long int moddiv(long long int, long long int);
long long int ncr(long long int, long long int);
long long int fpow(long long int x, long long int y,
                   long long int p = 1000000007);
vector<long long int> fact(5000005, 0);
void facto();
template <class L, class R>
ostream &operator<<(ostream &os, pair<L, R> P);
template <class T>
ostream &operator<<(ostream &os, vector<T> V);
template <class T>
ostream &operator<<(ostream &os, set<T> second);
template <class T>
ostream &operator<<(ostream &os, unordered_set<T> second);
template <class T, class T1>
ostream &operator<<(ostream &os, map<T, T1> second);
template <class T, class T1>
ostream &operator<<(ostream &os, unordered_map<T, T1> second);
int n, m;
vector<string> mat;
vector<vector<int> > dp, vis, perm;
int t;
int inRange(int r, int c) { return r >= 0 && r < n && c >= 0 && c < m; }
pair<long long int, long long int> get_p(char c) {
  switch (c) {
    case 'U':
      return {-1, 0};
    case 'D':
      return {1, 0};
    case 'R':
      return {0, 1};
    case 'L':
      return {0, -1};
  }
  return {-1, -1};
}
void markCycle(int r, int c, int length) {
  int nextr = r, nextc = c;
  do {
    vis[nextr][nextc] = 0;
    dp[nextr][nextc] = length;
    pair<long long int, long long int> next = get_p(mat[nextr][nextc]);
    nextr = nextr + next.first;
    nextc = nextc + next.second;
  } while (!(nextr == r && nextc == c));
}
void dfs(int r, int c) {
  int r1 = r, c1 = c;
  while (inRange(r, c) && !perm[r][c]) {
    if (vis[r][c]) {
      markCycle(r, c, t - vis[r][c]);
      break;
    }
    vis[r][c] = t++;
    pair<long long int, long long int> next = get_p(mat[r][c]);
    r = r + next.first;
    c = c + next.second;
  }
  r = r1;
  c = c1;
  while (inRange(r, c) && !perm[r][c]) {
    vis[r][c] = 0;
    perm[r][c] = 1;
    pair<long long int, long long int> next = get_p(mat[r][c]);
    r = r + next.first;
    c = c + next.second;
  }
}
int dfs1(int r, int c) {
  int r1 = r, c1 = c;
  int ans = 0;
  int cnt = 0;
  while (inRange(r, c) && !dp[r][c]) {
    cnt++;
    ans++;
    pair<long long int, long long int> next = get_p(mat[r][c]);
    r = r + next.first;
    c = c + next.second;
  }
  if (inRange(r, c)) ans += dp[r][c];
  r = r1;
  c = c1;
  while (cnt--) {
    dp[r][c] = ans--;
    pair<long long int, long long int> next = get_p(mat[r][c]);
    r = r + next.first;
    c = c + next.second;
  }
  return dp[r1][c1];
}
void solve() {
  t = 1;
  cin >> n >> m;
  mat = vector<string>(n);
  for (int i = 0; i < n; i++) cin >> mat[i];
  dp = perm = vis = vector<vector<int> >(n, vector<int>(m));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      dfs(i, j);
    }
  }
  int ans = 0;
  int ar = 0, ac = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      int d = dfs1(i, j);
      if (d > ans) {
        ans = d;
        ar = i;
        ac = j;
      }
    }
  }
  cout << ar + 1 << " " << ac + 1 << " " << ans << '\n';
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  ;
  int t = 1;
  cin >> t;
  int i = 1;
  while (i <= t) {
    solve();
    i++;
  }
  return 0;
}
template <class L, class R>
ostream &operator<<(ostream &os, pair<L, R> P) {
  return os << "(" << P.first << ", " << P.second << ")";
}
template <class T>
ostream &operator<<(ostream &os, vector<T> V) {
  if (V.size()) {
    os << "[" << V[0];
    for (int i = 1; i < V.size(); i++) os << ", " << V[i];
    return os << "]";
  }
  return os << "[]";
}
template <class T>
ostream &operator<<(ostream &os, set<T> second) {
  os << "{";
  for (auto s : second) os << s << ", ";
  return os << "}";
}
template <class T>
ostream &operator<<(ostream &os, unordered_set<T> second) {
  os << "{";
  for (auto s : second) os << s << ", ";
  return os << "}";
}
template <class T, class T1>
ostream &operator<<(ostream &os, map<T, T1> second) {
  os << "{" << '\n';
  for (auto s : second)
    os << "\t" << s.first << " : " << s.second << "," << '\n';
  return os << "}" << '\n';
}
template <class T, class T1>
ostream &operator<<(ostream &os, unordered_map<T, T1> second) {
  os << "{" << '\n';
  for (auto s : second)
    os << "\t" << s.first << " : " << s.second << "," << '\n';
  return os << "}" << '\n';
}
bool CustomCompareF(const pair<long long int, long long int> &i,
                    const pair<long long int, long long int> &j) {
  if (i.first == j.first) return i.second < j.second;
  return i.first < j.first;
}
bool CustomCompareS::operator()(const pair<long long int, long long int> &i,
                                const pair<long long int, long long int> &j) {
  if (i.first == j.first) return i.second < j.second;
  return i.first < j.first;
}
long long int modmul(long long int a, long long int b) {
  long long int ret = (a % 1000000007) * (b % 1000000007);
  ret %= 1000000007;
  return ret;
}
long long int modadd(long long int a, long long int b) {
  long long int ret = (a % 1000000007) + (b % 1000000007);
  ret %= 1000000007;
  return ret;
}
long long int modsub(long long int a, long long int b) {
  a = a % 1000000007;
  b = b % 1000000007;
  if (a < b) a += 1000000007;
  long long int ret = a - b;
  ret %= 1000000007;
  return ret;
}
long long int moddiv(long long int a, long long int b) {
  return modmul(a, fpow(b, 1000000007 - 2));
}
long long int fpow(long long int x, long long int y, long long int p) {
  x = x % p;
  long long int sum = 1;
  while (y) {
    if (y & 1) sum = sum * x;
    sum %= p;
    y = y >> 1;
    x = x * x;
    x %= p;
  }
  return sum;
}
void facto() {
  fact[0] = 1;
  fact[1] = 1;
  for (int i = 2; i < fact.size(); i++)
    fact[i] = (fact[i - 1] * i) % 1000000007;
}
long long int ncr(long long int n, long long int r) {
  if (r > n) return 0;
  long long int res = 1;
  res = fact[n];
  res = (res * (fpow(fact[r], 1000000007 - 2))) % 1000000007;
  res = (res * (fpow(fact[n - r], 1000000007 - 2))) % 1000000007;
  return res;
}
