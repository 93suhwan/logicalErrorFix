#include <bits/stdc++.h>
int dx[] = {1, -1, 0, 0}, dy[] = {0, 0, 1, -1};
using namespace std;
const long long N = 1e6 + 10, OO = 1e18, MAX = 1e12 + 10, mod = 1e9 + 7;
void test() {
  long long n;
  cin >> n;
  vector<long long> v(n + 1);
  for (long long i = 1; i <= n; ++i) cin >> v[i];
  for (long long i = 1; i <= n; ++i) {
    long long pwr = i;
    while (v[i] % (pwr + 1) == 0 and pwr >= 2) pwr--;
    if (v[i] % (pwr + 1) == 0) return void(cout << "NO\n");
  }
  cout << "YES\n";
}
int32_t main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  long long tc = 1;
  cin >> tc;
  while (tc--) test();
}
