#include <bits/stdc++.h>
using namespace std;
const long double r = 1e+9;
void solve() {
  long long n;
  cin >> n;
  vector<long long> a(n + 1);
  map<long long, long long> exist, done;
  for (long long i = 1; i <= n; i++) {
    cin >> a[i];
    exist[a[i]]++;
  }
  vector<long long> want, maxes;
  long long ws = 0, ms = 0;
  for (long long i = 1; i <= n; i++) {
    if (exist[i] > 0) {
      exist[i]--;
    } else {
      want.push_back(i);
      ws++;
    }
  }
  for (long long i = 1; i <= n; i++) {
    if (exist[a[i]] > 0) {
      maxes.push_back(a[i] - (a[i] / 2 + 1));
      ms++;
      exist[a[i]]--;
    }
  }
  if (ws != ms) {
    cout << -1 << "\n";
    return;
  }
  sort(want.begin(), want.end());
  sort(maxes.begin(), maxes.end());
  long long ans = 0;
  for (long long i = 0; i < ws; i++) {
    if (want[i] > maxes[i]) {
      cout << -1 << "\n";
      return;
    } else {
      ans++;
    }
  }
  cout << ans << "\n";
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long t = 1;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
