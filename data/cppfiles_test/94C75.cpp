#include <bits/stdc++.h>
using namespace std;
void solve() {
  long long int n, k;
  cin >> n >> k;
  vector<long long int> v(n);
  for (int i = 0; i < n; i++) cin >> v[i];
  ;
  sort(v.begin(), v.end());
  vector<long long int> p(10, 0);
  p[0] = 1;
  for (int i = 1; i <= 9; i++) {
    p[i] = p[i - 1] * 10;
  }
  long long int s = 2e18;
  long long int ans = 0;
  long long int cnt = 0;
  k++;
  for (int i = 0; i < n; i++) {
    if (i == n - 1 || ans + k * p[v[i]] < p[v[i + 1]]) {
      long long int val = ans + k * p[v[i]];
      s = min(val, s);
    }
    long long int diff = 0;
    if (i != n - 1) {
      diff = v[i + 1] - v[i];
    }
    ans += min(p[diff] - 1, k) * p[v[i]];
    k -= min(p[diff] - 1, k);
  }
  cout << s << "\n";
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int t = 1;
  cin >> t;
  for (int i = 1; i <= t; i++) {
    solve();
  }
  return 0;
}
