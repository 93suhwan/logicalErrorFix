#include <bits/stdc++.h>
using namespace std;
constexpr long long bits(long long x) {
  return x == 0 ? 0 : 31 - __builtin_clz(x);
}
long long INF = 2000000007;
long long INFLL = (long long)INF * (long long)INF;
double EPS = 10e-7;
long double pi = 2 * acos(0.0);
long long mod = 998244353;
const long long array_size = 2e5 + 7;
long long Power(long long aa, long long bb) {
  long long $a = aa;
  long long $b = bb;
  long long $result = 1ll;
  $a %= 1000000007;
  while ($b) {
    if ($b % 2ll == 1ll) $result *= $a;
    $a *= $a;
    $a %= 1000000007;
    $result %= 1000000007;
    $b /= 2ll;
  }
  return $result % 1000000007;
}
void solve(long long tc) {
  long long n;
  cin >> n;
  if (n == 10) {
    cout << "7 2 1" << endl;
    return;
  }
  if (n % 2 == 0) {
    cout << (n - 1) / 2 << " " << (n + 1) / 2 << " " << 1 << endl;
    return;
  }
  n -= 1;
  n /= 2;
  if (n % 2 == 0) {
    cout << n - 1 << " " << n + 1 << " ";
    cout << 1 << endl;
    return;
  }
  cout << n - 2 << " " << n + 2 << " ";
  cout << 1 << endl;
}
int32_t main() {
  clock_t start, end;
  start = clock();
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long tc = 1;
  cin >> tc;
  for (long long i = 1; i <= tc; i++) {
    solve(i);
  }
  end = clock();
  double time_taken = double(end - start) / double(CLOCKS_PER_SEC);
  cerr << "\nTime taken by program is : " << fixed << time_taken
       << setprecision(5);
  cerr << " sec " << endl;
  return 0;
}
