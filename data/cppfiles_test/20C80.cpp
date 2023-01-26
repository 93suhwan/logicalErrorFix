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
int n, m;
int a[444][444];
long long dp[404][404][5];
void solve() {
  cin >> n >> m;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      char c;
      cin >> c;
      a[i][j] = c - '0';
    }
  }
  for (int j1 = 0; j1 <= m + 1; j1++)
    for (int j2 = 0; j2 <= m + 1; j2++)
      for (int i = 0; i < 5; ++i) dp[j1][j2][i] = 1e9;
  long long res = 1e18;
  for (int i = 0; i < n; ++i) {
    for (int j1 = 0; j1 < m; ++j1) {
      int cnt0 = 0;
      int cnt1 = 0;
      for (int j2 = j1 + 1; j2 < m; ++j2) {
        if (j2 - j1 >= 3) {
          uin(res, dp[j1][j2][3] + cnt0);
          dp[j1][j2][3] = min(dp[j1][j2][2], dp[j1][j2][3]) + cnt1 +
                          (a[i][j1] == 0) + (a[i][j2] == 0);
          dp[j1][j2][2] =
              dp[j1][j2][1] + cnt1 + (a[i][j1] == 0) + (a[i][j2] == 0);
          dp[j1][j2][1] =
              dp[j1][j2][0] + cnt1 + (a[i][j1] == 0) + (a[i][j2] == 0);
          dp[j1][j2][0] = cnt0;
        }
        cnt0 += 1 - a[i][j2];
        cnt1 += a[i][j2];
      }
    }
  }
  cout << res << "\n";
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    solve();
  }
}
