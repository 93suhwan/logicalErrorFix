#include <bits/stdc++.h>
using namespace std;
const int INF = 1e9 + 7;
const long long MOD1 = 1000000007;
const unsigned long long MOD2 = 1000000009;
const long long INF64 = 1e18 + 7;
const int MAXN = 1e5 + 2;
const int MAXMAXN = 1e6 + 10;
const double EPS = 1e-5;
const long double PI = 3.14159265358979323846;
template <typename T>
inline T getint() {
  T val = 0;
  char c;
  bool neg = false;
  while ((c = getchar()) && !(c >= '0' && c <= '9')) {
    neg |= c == '-';
  }
  do {
    val = (val * 10) + c - '0';
  } while ((c = getchar()) && (c >= '0' && c <= '9'));
  return val * (neg ? -1 : 1);
}
template <typename T>
T gcd(T a, T b) {
  while (a && b) a > b ? a %= b : b %= a;
  return a + b;
}
long long mypow(long long x, long long y) {
  long long ans = 1;
  x %= MOD1;
  while (y) {
    if (y & 1) ans = (ans * x) % MOD1;
    y >>= 1;
    x = (x * x) % MOD1;
  }
  return ans;
}
void solve() {
  int n, m;
  cin >> n >> m;
  vector<int> used(n + 1);
  for (int i = 0; i < m; i++) {
    int a, b, c;
    cin >> a >> b >> c;
    used[b] = 1;
  }
  for (int i = 1; i <= n; i++) {
    if (used[i] == 0) {
      for (int j = 1; j <= n; j++) {
        if (j == i) continue;
        cout << i << " " << j << '\n';
      }
      return;
    }
  }
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cout.precision(8);
  int t;
  cin >> t;
  for (int tt = 0; tt < t; tt++) solve();
  return 0;
}
