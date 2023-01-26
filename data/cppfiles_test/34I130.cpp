#include <bits/stdc++.h>
using namespace std;
int n, k;
void solve() {
  cin >> n >> k;
  vector<pair<long long, int>> a(n);
  for (int i = 0; i < n; i++) {
    int num;
    cin >> num;
    a[i] = make_pair(num, i + 1);
  }
  vector<pair<long long, int>> b = a;
  sort(a.begin(), a.end());
  long long ans = LLONG_MIN;
  long long best = n * (n - 1) - k * (b[n - 2].first | b[n - 1].first);
  for (int i = n - 1; i > 0; i--) {
    for (int j = i - 1; j >= 0; j--) {
      if ((i + 1) * (j + 1) <= ans) break;
      ans = max(ans, (i + 1) * (j + 1) - k * (b[i].first | b[j].first));
    }
  }
  cout << ans;
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t;
  cin >> t;
  for (int tc = 1; tc <= t; tc++) {
    solve();
    cout << '\n';
  }
}
