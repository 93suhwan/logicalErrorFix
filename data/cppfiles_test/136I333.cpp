#include <bits/stdc++.h>
using namespace std;
const long long N = 1e9 + 7;
void solve() {
  long long n;
  cin >> n;
  vector<long long> a(n, 0);
  for (long long i = 0; i < n; i++) cin >> a[i];
  vector<long long> ans(n, 0);
  long long sm = 0;
  for (auto &i : a) sm += i;
  long long check = 2 * sm;
  long long y = n * (n + 1);
  if (check % y) {
    cout << "NO\n";
    return;
  }
  sm = check / y;
  for (long long i = 0; i < n; i++) {
    long long x = a[i];
    long long y = 0;
    if (i == 0)
      y = a[n - 1];
    else
      y = a[i - 1];
    if ((sm - (x - y)) % (n)) {
      cout << "NO\n";
      return;
    }
    ans[i] = (sm - (x - y)) / n;
    if (ans[i] < 1 || ans[i] > n) {
      cout << "NO\n";
      return;
    }
  }
  cout << "YES\n";
  for (auto &i : ans) cout << i << " ";
  cout << endl;
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long t = 1;
  cin >> t;
  for (long long x = 1; x < t + 1; x++) {
    solve();
  }
  return 0;
}
