#include <bits/stdc++.h>
using namespace std;
const double eps = 1e-8;
const double pi = acos(-1);
const int inf = 0x3f3f3f3f;
const long long INF = 0x3f3f3f3f3f3f3f3f;
const int N = 2e5 + 5;
int n, m, k;
bool solve() {
  cin >> n >> m >> k;
  if ((2 * k) % m == 0 && (n - (2 * k / m)) % 2 == 0 && m % 2 == 0) return 1;
  int val = k % n;
  if ((n - val) & 1) return 0;
  if ((k + n - 1) / n * 2 < m) return n % 2 == 0;
  return 0;
}
int main() {
  int t;
  cin >> t;
  while (t--) puts(solve() ? "YES" : "NO");
  return 0;
}
