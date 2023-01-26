#include <bits/stdc++.h>
using namespace std;
void dbg_out() { cerr << endl; }
template <typename Head, typename... Tail>
void dbg_out(Head H, Tail... T) {
  cerr << ' ' << H;
  dbg_out(T...);
}
pair<int, int> operator*(const pair<int, int> &p, const pair<int, int> &x) {
  pair<int, int> np = make_pair(p.first * x.first, p.second * x.second);
  return np;
}
pair<long long, long long> operator%(const pair<long long, long long> &p,
                                     const pair<long long, long long> &x) {
  pair<long long, long long> np =
      make_pair(p.first % x.first, p.second % x.second);
  return np;
}
pair<long long, long long> operator*(const pair<long long, long long> &p,
                                     const pair<int, int> &x) {
  pair<long long, long long> np =
      make_pair(p.first * x.first, p.second * x.second);
  return np;
}
pair<long long, long long> operator*(const pair<long long, long long> &p,
                                     const pair<long long, long long> &x) {
  pair<long long, long long> np =
      make_pair(p.first * x.first, p.second * x.second);
  return np;
}
pair<long long, long long> operator+(const pair<long long, long long> &p,
                                     const pair<long long, long long> &x) {
  pair<long long, long long> np =
      make_pair(p.first + x.first, p.second + x.second);
  return np;
}
pair<long long, long long> operator-(const pair<long long, long long> &p,
                                     const pair<long long, long long> &x) {
  pair<long long, long long> np =
      make_pair(p.first - x.first, p.second - x.second);
  return np;
}
pair<int, int> operator+(const pair<int, int> &p, const pair<int, int> &x) {
  pair<int, int> np = make_pair(p.first + x.first, p.second + x.second);
  return np;
}
pair<int, int> operator-(const pair<int, int> &p, const pair<int, int> &x) {
  pair<int, int> np = make_pair(p.first - x.first, p.second - x.second);
  return np;
}
vector<int> prime;
bool sortinrev(const pair<int, int> &a, const pair<int, int> &b) {
  return (a.first > b.first);
}
bool sortbysecdesc(const pair<int, int> &a, const pair<int, int> &b) {
  if (a.second == b.second) return a.first > b.first;
  return a.second > b.second;
}
bool sortbysec(const pair<int, int> &a, const pair<int, int> &b) {
  if (a.second == b.second) return a.first > b.first;
  return (a.second < b.second);
}
long long powerm(long long a, long long k) {
  if (!k) {
    return 1;
  }
  long long b = powerm(a, k / 2);
  b = b * b % 998244353;
  if (k % 2) {
    return a * b % 998244353;
  } else {
    return b;
  }
}
long long power(long long a, long long b) {
  if (b == 1) return a;
  if (b == 0) return 1;
  long long m1 = power(a, b / 2);
  if (b % 2) return m1 * m1 * a;
  return m1 * m1;
}
void PFactor(int x) {
  prime.clear();
  for (int i = 2; i <= x / i; i++)
    if (x % i == 0) {
      while (x % i == 0) x /= i, prime.push_back(i);
    }
  if (x > 1) prime.push_back(x);
}
bool isprime(long long a) {
  if (a <= 1) return false;
  if (a == 2 || a == 3) return true;
  if (a % 2 == 0 || a % 3 == 0) return false;
  for (long long i = 5; i * i <= a; i = i + 6) {
    if (a % i == 0 || a % (i + 2) == 0) return false;
  }
  return true;
}
long long read() {
  long long a = 0;
  char b = 1, c;
  do
    if ((c = getchar()) == 45) b = -1;
  while (c < 48 || c > 57);
  do a = (a << 3) + (a << 1) + (c & 15);
  while ((c = getchar()) > 47 && c < 58);
  return a * b;
}
void write(long long x, char c) {
  if (x < 0) putchar(45), x = -x;
  char a[20], s = 0;
  do a[++s] = x % 10 | 48;
  while (x /= 10);
  do putchar(a[s]);
  while (--s);
  putchar(c);
}
const int LOGN = 20;
const int N = (1 << LOGN);
set<long long> g[N];
long long n = 0, m = 0, k = 0;
long long a = 0, b = 0, c = 0;
string str;
long long d[N] = {0};
bool ban[N];
bool vis[N];
map<long long, long long> tim;
long long dp[N];
long long dfs(long long u, long long fa) {
  if (vis[u]) return -1;
  vis[u] = true;
  if (fa != 0 && (long long)(g[u]).size() == 1) return 1;
  if ((long long)(g[u]).size() == 2 || fa == 0) {
    long long v = (*g[u].begin()) == fa ? (*g[u].rbegin()) : (*g[u].begin());
    long long ans = dfs(v, u);
    if (ans == -1)
      return -1;
    else
      return ans + 1;
  }
  return -1;
}
signed main() {
  dp[0] = 1;
  cin >> n >> m >> k;
  for (long long i = 1; i <= n; i++) {
    cin >> a;
    cin >> b;
    for (long long i = 2; i <= a; i++) {
      cin >> c;
      g[b].insert(c);
      g[c].insert(b);
      b = c;
    }
  }
  for (long long i = 1; i <= k; i++) {
    if ((long long)(g[i]).size() == 0) tim[1]++;
    if ((long long)(g[i]).size() != 1 || vis[i]) continue;
    long long ans = dfs(i, 0);
    if (ans != -1) tim[ans]++;
  }
  for (long long i = 1; i <= m; i++) {
    for (auto x : tim) {
      if (i >= x.first) dp[i] += dp[i - x.first] * x.second;
      dp[i] %= 998244353;
    }
  }
  cout << dp[m];
}
