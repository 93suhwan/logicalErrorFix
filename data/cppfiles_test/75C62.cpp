#include <bits/stdc++.h>
using namespace std;
void solve() {
  int n;
  cin >> n;
  int k[n], a[n], r, ans = 0, sum = 0;
  vector<pair<int, int> > ka;
  int i, j;
  for (i = 0; i < n; i++) {
    cin >> k[i];
    cin >> r;
    a[i] = r;
    for (j = 1; j < k[i]; j++) {
      cin >> r;
      a[i] = max(a[i], r - j);
    }
    ka.push_back(make_pair(a[i], k[i]));
  }
  sort(ka.begin(), ka.end());
  ans = ka[0].first + 1;
  sum = ka[0].second;
  for (i = 1; i < n; i++) {
    ans = max(ans, ka[i].first - sum + 1);
    sum += ka[i].second;
  }
  cout << ans << "\n";
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long int t, T = 1;
  cin >> T;
  for (t = 0; t < T; t++) {
    solve();
  }
  return 0;
}
