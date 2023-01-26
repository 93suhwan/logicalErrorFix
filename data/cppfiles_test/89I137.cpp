#include <bits/stdc++.h>
int dx[] = {1, -1, 0, 0}, dy[] = {0, 0, 1, -1};
using namespace std;
const long long N = 1e6 + 10, OO = 1e18, MAX = 1e12 + 10, mod = 1e9 + 7;
void test() {
  long long n;
  cin >> n;
  vector<long long> v(n + 1);
  for (long long i = 1; i <= n; ++i) {
    cin >> v[i];
  }
  if (v[1] % 2 == 0) {
    cout << "NO\n";
    return;
  }
  long long erased = 0, last_idx = 1;
  bool ok = true;
  for (long long i = 2; i <= n; ++i) {
    long long idx = i + 1 - erased;
    if (v[i] % idx == 0 && v[i] % (last_idx + 1) == 0) {
      ok = false;
      break;
    }
    if (v[i] % idx) {
      last_idx = idx - 1;
      continue;
    }
    if (v[i] % idx == 0 && v[i] % (last_idx + 1)) erased++;
  }
  (ok ? cout << "YES\n" : cout << "NO\n");
}
int32_t main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  long long tc = 1;
  cin >> tc;
  while (tc--) test();
}
