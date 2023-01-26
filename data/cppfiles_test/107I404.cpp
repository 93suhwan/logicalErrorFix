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
  vector<long long> ans(n);
  for (long long i = 0; i < n; i++) ans[i] = i + 1;
  long long i = 1;
  long long cnt = max(a, b);
  for (; cnt; i += 2) {
    long long temp = ans[i];
    ans[i] = ans[i + 1];
    ans[i + 1] = temp;
    cnt--;
  }
  if (a > b && n > 3) {
    long long temp = ans[n - 1];
    ans[n - 1] = ans[n - 2];
    ans[n - 2] = temp;
  }
  if (b > a) {
    long long temp = ans[0];
    ans[0] = ans[1];
    ans[1] = temp;
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
