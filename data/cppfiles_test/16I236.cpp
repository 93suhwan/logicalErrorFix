#include <bits/stdc++.h>
using namespace std;
const long double r = 1e+9;
void solve() {
  long long n;
  cin >> n;
  vector<long long> a(n);
  vector<pair<long long, long long>> v;
  long long numOfNotZeroes = 0;
  for (long long i = 0; i < n; i++) {
    cin >> a[i];
    if (a[i] != 0) {
      numOfNotZeroes++;
    }
    v.push_back({a[i], i + 1});
  }
  vector<pair<long long, long long>> ans;
  while (numOfNotZeroes > 1) {
    sort(v.begin(), v.end());
    for (long long j = 1; j <= v[n - 2].first; j++) {
      ans.push_back({v[n - 1].second, v[n - 2].second});
    }
    v[n - 1].first -= v[n - 2].first;
    v[n - 2].first = 0;
    numOfNotZeroes--;
  }
  cout << ans.size() << "\n";
  for (long long i = 0; i < ans.size(); i++) {
    cout << ans[i].first << " " << ans[i].second << "\n";
  }
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
