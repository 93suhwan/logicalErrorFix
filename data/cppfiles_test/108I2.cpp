#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<pair<int, int>> arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i].first;
    for (int i = 0; i < n; i++) cin >> arr[i].second;
    vector<int> r(n);
    iota(r.begin(), r.end(), 0);
    sort(r.begin(), r.end(),
         [&](int i, int j) { return arr[i].first < arr[j].first; });
    string ans = string(n, '0');
    ans[r[n - 1]] = '1';
    int min_win_second = arr[n - 1].second;
    int j = n - 1;
    for (int i = n - 2; i >= 0; i--) {
      if (arr[r[i]].second > min_win_second) {
        for (int h = i; h < j; h++) {
          min_win_second = min(min_win_second, arr[r[h]].second);
          ans[r[h]] = '1';
        }
        j = i;
      }
    }
    cout << ans << '\n';
  }
  return 0;
}
