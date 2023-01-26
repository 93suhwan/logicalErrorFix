#include <bits/stdc++.h>
using namespace std;
const int inf = 0x3f3f3f3f;
const int mod = 1000000007;
const double pi = acos(-1.0);
const long long INF = 0x3f3f3f3f3f3f3f3f;
const int dx[] = {-1, 0, 1, 0}, dy[] = {0, 1, 0, -1};
long long gcd(long long a, long long b) { return b ? gcd(b, a % b) : a; }
long long poww(long long a, long long b) {
  long long s = 1;
  while (b) {
    if (b & 1) s = (s * a) % mod;
    a = (a * a) % mod;
    b >>= 1;
  }
  return s % mod;
}
const int N = 1e6 + 11;
long long n, m;
void solve() {
  cin >> n >> m;
  vector<int> ve(n + 1, 0);
  for (int i = 1; i <= m; i++) {
    int a, b, c;
    cin >> a >> b >> c;
    ve[b] = 1;
  }
  for (int i = 1; i <= n; i++) {
    if (ve[i] == 0) {
      for (int j = 1; j <= n; j++) {
        if (i == j) continue;
        cout << i << ' ' << j << '\n';
      }
      return;
    }
  }
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout << setprecision(15);
  long long T = 1;
  cin >> T;
  while (T--) solve();
  return 0;
}
