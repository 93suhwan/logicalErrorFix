#include <bits/stdc++.h>
using namespace std;
const long long maxn = 2e5 + 10;
long long n;
long long a[maxn];
void getInput() {
  cin >> n;
  for (long long i = (1); i <= (n); i++) cin >> a[i];
}
void solve() {
  getInput();
  vector<long long> ans;
  long long ones = 0;
  for (long long i = (1); i <= (n); i++) ones += a[i];
  if (ones & 1) {
    cout << "NO\n";
    return;
  }
  if (n & 1) {
    for (long long i = n - 2; i >= 1; i -= 2) ans.push_back(i);
    for (long long i = 1; i <= n - 2; i += 2) ans.push_back(i);
    cout << "YES\n";
    cout << ((long long)ans.size()) << '\n';
    for (auto x : ans) cout << x << " ";
    cout << '\n';
    return;
  } else {
    ones = 0;
    for (long long i = 1; i <= n; i += 2) {
      ones += a[i - 1] + a[i];
      if (ones % 2 == 0) {
        long long k = i;
        for (long long j = k - 2; j >= 1; j -= 2) ans.push_back(j);
        for (long long j = 1; j <= k - 2; j += 2) ans.push_back(j);
        for (long long j = n - 2; j >= k + 1; j -= 2) ans.push_back(j);
        for (long long j = k + 1; j <= n - 2; j += 2) ans.push_back(j);
        cout << "YES\n";
        cout << ((long long)ans.size()) << '\n';
        for (auto x : ans) cout << x << " ";
        cout << '\n';
        return;
      }
    }
    cout << "NO\n";
    return;
  }
}
signed main() {
  cin.tie(0);
  cout.tie(0);
  ios_base::sync_with_stdio(false);
  long long T;
  cin >> T;
  while (T--) solve();
}
