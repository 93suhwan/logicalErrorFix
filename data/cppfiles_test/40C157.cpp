#include <bits/stdc++.h>
using namespace std;
long long gcd(long long a, long long b) { return b ? gcd(b, a % b) : a; }
long long lcm(long long a, long long b) { return (a * b) / gcd(a, b); }
long double pointdist(long double x, long double y, long double point) {
  return ((x - point) * (y - point)) / abs(x - y);
}
long double dist(long double x, long double y, long double a, long double b) {
  return sqrt((x - a) * (x - a) + (y - b) * (y - b));
}
const int nx[4] = {0, 0, 1, -1}, ny[4] = {1, -1, 0, 0};
const int xcav[8] = {1, 2, 2, 1, -1, -2, -2, -1};
const int ycav[8] = {-2, -1, 1, 2, 2, 1, -1, -2};
const int crapx[4] = {0, 2, 0, -2};
const int crapy[4] = {-2, 0, 2, 0};
long long m;
long long mat[MAX_M][2];
long long solve() {
  cin >> m;
  long long pref[m + 1][2];
  pref[0][0] = 0;
  pref[0][1] = 0;
  for (int j = 0; j < 2; j++) {
    for (int i = 0; i < m; i++) {
      cin >> mat[i][j];
      pref[i + 1][j] = pref[i][j] + mat[i][j];
    }
  }
  long long ans = (long long)(1e18);
  for (int i = 1; i <= m; i++) {
    long long r1 = pref[m][0] - pref[i][0];
    long long r2 = pref[i - 1][1];
    ans = min(ans, max(r1, r2));
  }
  return ans;
}
int main() {
  int tt;
  cin >> tt;
  while (tt--) {
    cout << solve() << '\n';
  }
}
