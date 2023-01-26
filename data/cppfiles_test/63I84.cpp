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
int n;
int a[21], b[21];
vector<int> con[21];
int stk[2000050], tp;
int sum[2000050], dp[2000050];
int getcon(int i, int j) {
  if (j < con[i].size()) return con[i][j];
  return 0;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0), cout.tie(0);
  cin >> n;
  for (__typeof(0) i = (0), _end = (n), _step = 1 - 2 * ((0) > (n)); i != _end;
       i += _step) {
    string s;
    cin >> s;
    con[i].resize(s.size() + 1);
    tp = 0;
    for (__typeof(0) j = (0), _end = (s.size()),
                     _step = 1 - 2 * ((0) > (s.size()));
         j != _end; j += _step) {
      if (s[j] == ')' && tp && s[stk[tp]] == '(')
        --tp;
      else
        stk[++tp] = j;
      if (tp && s[stk[tp]] == '(') continue;
      ++con[i][tp];
    }
    for (; tp; --tp) {
      if (s[stk[tp]] == '(')
        ++b[i];
      else
        ++a[i];
    }
  }
  memset(dp, 0xc0, sizeof(dp));
  dp[0] = sum[0] = 0;
  int ans = 0;
  for (int s = 0; s < (1 << n); ++s) {
    for (int i = 0; i < n; ++i) {
      if (~s >> i & 1) continue;
      int t = s ^ (1 << i);
      if (sum[t] < a[i]) continue;
      sum[s] = sum[t] - a[i] + b[i];
      dp[s] = max(dp[s], dp[t] + getcon(i, sum[t]));
    }
    for (int i = 0; i < n; ++i)
      if (~s >> i & 1) ans = max(ans, dp[s] + getcon(i, sum[s]));
  }
  cout << ans << endl;
  return 0;
}
