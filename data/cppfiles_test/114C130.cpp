#include <bits/stdc++.h>
using namespace std;
void solve() {
  long long int n;
  cin >> n;
  long long int arr[n];
  vector<bool> chk(1e6 + 1, false);
  for (long long int i = 0; i < n; i++) {
    cin >> arr[i];
    chk[arr[i]] = true;
  }
  sort(arr, arr + n);
  vector<pair<long long int, long long int>> ans;
  for (long long int i = 1; i < n; i++) {
    for (long long int j = 0; j < i; j++) {
      if (chk[arr[i] % arr[j]] == 0) {
        ans.push_back({arr[i], arr[j]});
      }
      if (ans.size() >= n / 2) {
        break;
      }
    }
    if (ans.size() >= n / 2) {
      break;
    }
  }
  for (long long int i = 0; i < ans.size(); i++) {
    cout << ans[i].first << " " << ans[i].second << "\n";
  }
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  long long int t;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
