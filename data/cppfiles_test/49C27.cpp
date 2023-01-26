#include <bits/stdc++.h>
using namespace std;
template <class T = int>
void readArray(vector<T> &v, int n) {
  T a;
  for (int i = 0; i < n; i = i + 1) {
    cin >> a;
    v.push_back(a);
  }
}
template <class T = int>
void printArray(vector<T> &v, int a = 0) {
  for (int i = a; i < v.size(); i = i + 1) {
    cout << v[i] << " ";
  }
  cout << "\n";
}
const int mod = 998244353;
double logy(int n, int b) {
  if (b == 0) {
    return (-1);
  }
  if (n == 1) {
    return (0);
  }
  return ((double)log10(n) / (double)log10(b));
}
long long power(long long k, long long n, long long m = mod) {
  long long res = 1;
  while (n) {
    if (n % 2 != 0) {
      res = (res * k) % m;
    }
    k = (k * k) % m;
    n = n / 2;
  }
  return (res);
}
double powerD(double k, long long n) {
  double res = 1;
  while (n) {
    if (n % 2 != 0) {
      res = (res * k);
    }
    k = (k * k);
    n = n / 2;
  }
  return (res);
}
int gcdExtend(int a, int b, int &x, int &y) {
  if (a == 0) {
    x = 0;
    y = 1;
    return (b);
  }
  int x1, y1;
  int g = gcdExtend(b % a, a, x1, y1);
  x = y1 - (b / a) * x1;
  y = x1;
  return (g);
}
int gcd(int a, int b) { return b ? gcd(b, a % b) : a; }
int lcm(int a, int b) { return ((a / gcd(a, b)) * b); }
const int N = 1000009;
const int M = 100005;
const int inf = 1e9;
const int minf = -1e9;
int n, m, k, a1, a2, a3, h, t;
string str, str1, str2;
bool ok = true;
vector<pair<int, int> > tmp;
vector<vector<int> > v, query;
vector<int> bit, cnt, g, ans;
vector<set<int> > s;
void add(int i, int del) {
  for (; i < n + 3; i += i & (-i)) {
    bit[i] += del;
  }
}
int sum(int i) {
  int res = 0;
  for (; i > 0; i -= i & (-i)) {
    res += bit[i];
  }
  return (res);
}
void postProcess() {
  v.clear();
  bit.clear();
  cnt.clear();
  g.clear();
  query.clear();
  s.clear();
  tmp.clear();
  ans.clear();
  v.resize(n + 1);
  g.resize(n + 1);
  s.resize(n + 1);
  query.resize(n + 1);
  cnt.assign(n + 1, 0);
  bit.assign(n + 3, 0);
}
void dfs(int i, int par) {
  int a = g[i];
  if (cnt[a]) {
    s[cnt[a]].erase(a);
    add(cnt[a], -1);
    cnt[a]++;
    s[cnt[a]].insert(a);
    add(cnt[a], 1);
  } else {
    cnt[a]++;
    s[cnt[a]].insert(a);
    add(cnt[a], 1);
  }
  for (auto j : query[i]) {
    int l, k;
    tie(l, k) = tmp[j];
    int cur = -1;
    int lo = l;
    int hi = n;
    int subThis = sum(l - 1);
    while (lo <= hi) {
      int mid = lo + (hi - lo) / 2;
      int qans = sum(mid) - subThis;
      if (qans >= k) {
        cur = mid;
        hi = mid - 1;
      } else {
        lo = mid + 1;
      }
    }
    if (cur > 0 && (long long)(s[cur]).size()) {
      cur = *s[cur].begin();
    }
    ans[j] = cur;
  }
  for (auto j : v[i]) {
    dfs(j, i);
  }
  a = g[i];
  add(cnt[a], -1);
  s[cnt[a]].erase(a);
  cnt[a]--;
  if (cnt[a] >= 1) {
    s[cnt[a]].insert(a);
    add(cnt[a], 1);
  }
}
void naruto() {
  int a, b, c, d, i, j, x, y, z, tt;
  int p, q, u, w;
  cin >> n >> q;
  m = n + 5;
  postProcess();
  for (i = 1; i <= n; i++) {
    cin >> g[i];
  }
  for (i = 2; i <= n; i++) {
    cin >> a;
    v[a].push_back(i);
  }
  for (i = 0; i < q; i++) {
    cin >> a >> b >> c;
    query[a].push_back(i);
    tmp.push_back({b, c});
  }
  ans.resize(q);
  dfs(1, -1);
  printArray(ans);
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int t;
  t = 1;
  cin >> t;
  while (t--) {
    naruto();
  }
}
