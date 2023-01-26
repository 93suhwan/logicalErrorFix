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
    set<pair<int, int>> st;
    for (int i = n - 1; i >= 0; i--) {
      st.emplace(arr[r[i]].second, i);
    }
    int best = -1;
    bool lst = false;
    for (int i = 0; i < n; i++) {
      best = max(best, arr[r[i]].second);
      auto it = st.lower_bound({arr[r[i]].second, 0});
      if (it != st.end() && it->first == arr[r[i]].second) {
        st.erase(it);
      }
      while (lst == 0 && st.size() && st.begin()->first < best) {
        if (st.begin()->second == n - 1) {
          lst = true;
          break;
        }
        st.erase(st.begin());
      }
      if (st.empty() || lst) {
        ans[r[i]] = '1';
      }
    }
    cout << ans << '\n';
  }
  return 0;
}
