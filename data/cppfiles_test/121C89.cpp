#include <bits/stdc++.h>
using namespace std;
const long long N = 1e5 + 7, inf = 1e9 + 7, pi = 3.14159265;
long long dirx[8] = {1, -1, 0, 0, 1, 1, -1, -1};
long long diry[8] = {0, 0, 1, -1, 1, -1, 1, -1};
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
long long quik_pow(long long a, long long n, long long p) {
  if (n == 1) return a % p;
  if (n == 0) return 1;
  if (n % 2 == 0) {
    long long b = quik_pow(a, n / 2, p);
    return (b * b) % p;
  } else
    return (a * quik_pow(a, n - 1, p)) % p;
}
long long gcd(long long a, long long b, long long &first, long long &second) {
  if (a == 0) {
    first = 0;
    second = 1;
    return b;
  }
  long long x1, y1;
  long long g = gcd(b % a, a, x1, y1);
  first = y1 - (b / a) * x1;
  second = x1;
  return g;
}
long long d[2 * N][20];
void calc(long long n) {
  vector<long long> c;
  long long k = n;
  while (n) {
    c.push_back(n % 2);
    n /= 2;
  }
  for (long long i = 0; i < c.size(); i++) {
    d[k][i] = c[i] + d[k - 1][i];
  }
}
void solve() {
  long long n;
  cin >> n;
  string a, b;
  cin >> a >> b;
  long long first = 0, second = 0, ans, dif = 0;
  ans = n + 1;
  for (long long i = 0; i < n; i++) {
    if (a[i] == '1') first++;
    if (b[i] == '1') second++;
    if (a[i] != b[i]) dif++;
  }
  if (first == second) {
    ans = min(ans, dif);
  }
  if (n - first + 1 == second) {
    ans = min(ans, n - dif);
  }
  if (ans == n + 1) {
    ans = -1;
  }
  cout << ans << '\n';
}
signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  for (long long i = 1; i < 2 * N; i++) {
    calc(i);
  }
  long long _;
  cin >> _;
  while (_--) {
    solve();
  }
}
