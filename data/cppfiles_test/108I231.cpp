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
    vector<int> r(n);
    iota(r.begin(), r.end(), 0);
    vector<pair<int, int>> arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i].first;
    for (int i = 0; i < n; i++) cin >> arr[i].second;
    string ans = string(n, '0');
    sort(r.begin(), r.end(),
         [&](int i, int j) { return arr[i].first < arr[j].first; });
    set<int> st;
    for (int i = n - 1; i >= 0; i--) {
      st.insert(arr[r[i]].second);
    }
    int best = -1;
    for (int i = 0; i < n; i++) {
      best = max(best, arr[r[i]].second);
      st.erase(arr[r[i]].second);
      if (i + 1 == n || best > *st.rbegin()) {
        ans[r[i]] = '1';
      }
    }
    cout << ans << '\n';
  }
  return 0;
}
