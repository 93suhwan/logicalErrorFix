#include <bits/stdc++.h>
using namespace std;
const long long MOD = pow(10, 9) + 7;
const long long MAX = LONG_LONG_MAX;
long long check(long long x, long long y, long long k) {
  k -= y * (ceil(x / 2.0));
  return k;
}
void solve() {
  long long n, m, k, l;
  cin >> n >> m >> k;
  l = ((n * m) / 2) - k;
  long long y, d = l / m;
  if (l % m != 0) {
    d++;
    long long flow = m - l % m;
    if (n % 2 != 0 && d == n - 1)
      flow = 2 * ceil(flow / 2.0) - 1;
    else
      flow = 2 * ceil(flow / 2.0);
    k -= flow;
  }
  y = max(n - 2 * (d), long long(0));
  k = check(m, y, k);
  if (k >= 0) {
    cout << "YES";
  } else
    cout << "NO";
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long t = 1;
  cin >> t;
  while (t > 0) {
    solve();
    t--;
    cout << endl;
  }
}
