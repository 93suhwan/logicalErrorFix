#include <bits/stdc++.h>
using namespace std;
long long power(long long x, long long y, long long p);
const long long inf = 999999999;
const long long mod = 1e9 + 7;
bool tc = true;
void solve() {
  long long n, m, k;
  cin >> n >> m >> k;
  m -= m & 1;
  n -= n & 1;
  k -= m / 2;
  cout << (k >= 0 && k <= n * m / 2 && k % 2 == 0 ? "Yes" : "No") << endl;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL), cout.tie(NULL);
  clock_t start = clock();
  long long t = 1;
  if (tc) cin >> t;
  while (t--) solve();
  cerr << fixed << setprecision(6);
  cerr << (double)(clock() - start) / CLOCKS_PER_SEC << endl;
  return 0;
}
long long power(long long x, long long y, long long p) {
  long long res = 1;
  x = x % p;
  if (x == 0) return 0;
  while (y > 0) {
    if (y & 1) res = (res * x) % p;
    y = y >> 1;
    x = (x * x) % p;
  }
  return res;
}
