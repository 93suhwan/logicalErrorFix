#include <bits/stdc++.h>
using namespace std;
template <class a, class b>
ostream& operator<<(ostream& os, const pair<a, b>& p) {
  os << "(" << p.first << "," << p.second << ")";
  return os;
}
template <class T>
ostream& operator<<(ostream& os, const vector<T>& v) {
  os << "[";
  if (!v.size())
    os << "]";
  else
    for (int i = 0; i < v.size(); ++i) os << v[i] << ",]"[i == v.size() - 1];
  return os;
}
template <class T>
ostream& operator<<(ostream& os, const set<T>& s) {
  os << "{";
  if (!s.size())
    os << "}";
  else
    for (auto x : s) os << x << ",}"[x == *s.rbegin()];
  return os;
}
void printr(ostream& os) { os << '\n'; }
template <class T, class... Args>
void printr(ostream& os, const T& t, const Args&... args) {
  os << t;
  if (sizeof...(args)) os << " ";
  printr(os, args...);
}
template <class T>
void read(T& x) {
  cin >> x;
}
template <class T, class... Args>
void read(T& t, Args&... args) {
  read(t), read(args...);
}
template <class T>
void readarray(T* A, int n) {
  for (__typeof(0) i = (0), _end = (n), _step = 1 - 2 * ((0) > (n)); i != _end;
       i += _step)
    read(A[i]);
}
void dbgr(ostream& os) { os << endl; }
template <class T, class... Args>
void dbgr(ostream& os, const T& t, const Args&... args) {
  os << t;
  if (sizeof...(args)) os << ", ";
  dbgr(os, args...);
}
long long randll(long long a, long long b) {
  uniform_int_distribution<int> u(a, b);
  static mt19937 e(time(0));
  return u(e);
}
long long pw(long long a, long long k = 998244353 - 2) {
  long long ans = 1;
  for (a %= 998244353; k; k >>= 1) {
    if (k & 1) ans = ans * a % 998244353;
    a = a * a % 998244353;
  }
  return ans;
}
int n, a[7000050];
int sz = 0;
int num[7000050];
map<int, int> id, pos;
vector<int> G[7000050];
int getid(int x) {
  if (!id.count(x)) {
    num[++sz] = x;
    return id[x] = sz;
  }
  return id[x];
}
int getfa(int x) {
  int pw2 = 1;
  while (pw2 < x) pw2 <<= 1;
  assert(pw2 - x < x);
  return pw2 - x;
}
void build(int a) {
  while (a) {
    int fa = getfa(a);
    G[getid(fa)].push_back(getid(a));
    a = fa;
  }
}
int ans = 0, ansp, ansq;
int mx[7000050], mxp[7000050];
void dfs(int i) {
  mx[i] = 0, mxp[i] = i;
  sort(G[i].begin(), G[i].end());
  G[i].resize(unique(G[i].begin(), G[i].end()) - G[i].begin());
  for (int j : G[i]) {
    dfs(j);
    if (mx[i] + mx[j] + 1 > ans) {
      ans = mx[i] + mx[j] + 1;
      ansp = mxp[i];
      ansq = mxp[j];
    }
    if (mx[j] + 1 > mx[i]) {
      mx[i] = mx[j] + 1;
      mxp[i] = mxp[j];
    }
  }
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0), cout.tie(0);
  cin >> n;
  for (int i = 1; i <= n; ++i) cin >> a[i], build(a[i]), pos[a[i]] = i;
  dfs(getid(0));
  cout << pos[num[ansp]] << " " << pos[num[ansq]] << " " << ans << endl;
  return 0;
}
