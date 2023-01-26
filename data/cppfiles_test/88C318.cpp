#include <bits/stdc++.h>
using namespace std;
vector<long long int> arr(4), ans;
void solve() {
  long long int n, m;
  cin >> n >> m;
  vector<pair<long long int, long long int>> arr(n * m + 1, {0, 0});
  for (long long int i = 1; i <= n * m; i++)
    cin >> arr[i].first, arr[i].second = i;
  long long int cnt = 0;
  sort(arr.begin(), arr.begin() + n * m + 1);
  for (long long int i = 1; i <= n; i++) {
    for (long long int j = 1; j <= m; j++) {
      for (long long int k = 1; k < j; k++) {
        if (arr[m * (i - 1) + j].second > arr[m * (i - 1) + k].second &&
            arr[m * (i - 1) + j].first != arr[m * (i - 1) + k].first)
          cnt++;
      }
    }
  }
  cout << cnt << "\n";
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long int t;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
