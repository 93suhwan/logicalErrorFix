#include <bits/stdc++.h>
using namespace std;
void per() { cerr << endl; }
template <typename Head, typename... Tail>
void per(Head H, Tail... T) {
  cerr << H << ' ';
  per(T...);
}
template <class T>
bool uin(T& a, T b) {
  return a > b ? (a = b, true) : false;
}
template <class T>
bool uax(T& a, T b) {
  return a < b ? (a = b, true) : false;
}
template <class U, class V>
ostream& operator<<(ostream& out, const pair<U, V>& a) {
  return out << "(" << a.first << ", " << a.second << ")";
}
template <class U, class V>
istream& operator>>(istream& in, pair<U, V>& a) {
  return in >> a.first >> a.second;
}
template <typename W,
          typename T = typename enable_if<!is_same<W, string>::value,
                                          typename W::value_type>::type>
ostream& operator<<(ostream& out, const W& v) {
  out << "{ ";
  for (const auto& first : v) out << first << ", ";
  return out << '}';
}
template <class T>
void readArr(T from, T to) {
  for (auto i = from; i != to; ++i) cin >> *i;
}
mt19937 mrand(1337);
unsigned int myRand32() { return mrand() & (unsigned int)(-1); }
unsigned long long myRand64() {
  return ((unsigned long long)myRand32() << 32) ^ myRand32();
}
const int mod = 1000000007;
void add(int& a, int b) {
  a += b;
  if (a >= mod) a -= mod;
}
void dec(int& a, int b) {
  a -= b;
  if (a < 0) a += mod;
}
int mult(int a, int b) { return a * (long long)b % mod; }
int bp(int a, int b) {
  int res = 1;
  while (b > 0) {
    if (b & 1) res = mult(res, a);
    a = mult(a, a);
    b >>= 1;
  }
  return res;
}
long long n, m;
long long a[4444];
int dd = 0;
vector<int> g[4444];
long long d[4444];
int sz[4444];
int build(int vl, int vr) {
  int v = vl;
  for (int i = vl; i <= vr; ++i)
    if (a[i] < a[v]) v = i;
  int now = dd++;
  d[now] = a[v];
  sz[now] = vr - vl + 1;
  if (v != vl) g[now].push_back(build(vl, v - 1));
  if (v != vr) g[now].push_back(build(v + 1, vr));
  return now;
}
long long dp[4004][4004];
void dfs(int v) {
  for (int to : g[v]) dfs(to);
  dp[v][0] = 0;
  dp[v][1] = (m - 1) * d[v];
  if (g[v].size() == 1) {
    int to = g[v][0];
    for (int s = 0; s <= sz[to]; ++s) uax(dp[v][s], dp[to][s]);
    for (int s = 0; s <= sz[to]; ++s)
      uax(dp[v][s + 1], dp[to][s] + (m - 1 - 2 * s) * d[v]);
  } else if (g[v].size() == 2) {
    int to1 = g[v][0];
    int to2 = g[v][1];
    for (int s1 = 0; s1 <= sz[to1]; ++s1)
      for (int s2 = 0; s2 <= sz[to2]; ++s2)
        uax(dp[v][s1 + s2],
            dp[to1][s1] + dp[to2][s2] + (-2 * s1 * (long long)s2) * d[v]);
    for (int s1 = 0; s1 <= sz[to1]; ++s1)
      for (int s2 = 0; s2 <= sz[to2]; ++s2)
        uax(dp[v][s1 + s2 + 1],
            dp[to1][s1] + dp[to2][s2] +
                (m - 1 - 2 * (s1 + s2 + s1 * (long long)s2)) * d[v]);
  }
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  fill((long long*)dp, (long long*)dp + 4004 * 4004, -1e18);
  cin >> n >> m;
  readArr(a, a + n);
  int root = build(0, n - 1);
  dfs(root);
  cout << dp[root][m];
}
