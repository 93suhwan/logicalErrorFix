#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1e9 + 7;
const long long infi = INT_MAX;
const long long infll = LLONG_MAX;
const long double PI = 3.1415926535897932384626;
void solve(long long test_case) {
  long long n, a, b;
  cin >> n >> a >> b;
  if (a + b + 2 > n) {
    cout << -1 << "\n";
    return;
  }
  if (abs(a - b) > 1) {
    cout << -1 << "\n";
    return;
  }
  vector<long long> ans(n, 3);
  if (a == b) b++;
  if (a > b) {
    for (long long i = 1; a >= 1; i += 2) {
      ans[i] = 4;
      a--;
    }
  } else {
    for (long long i = 1; b >= 1; i += 2) {
      ans[i] = 2;
      b--;
    }
  }
  for (auto x : ans) cout << x << " ";
  cout << "\n";
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  ios_base ::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long tc = 1;
  cin >> tc;
  while (tc--) solve(tc);
  return 0;
}
