#include <bits/stdc++.h>
using namespace std;
int32_t main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  long long int t;
  cin >> t;
  while (t--) {
    long long int n, k;
    cin >> n >> k;
    vector<long long int> nums(n), ans(n, -1);
    for (long long int i = 0; i < n; i++) cin >> nums[i];
    map<long long int, long long int> mp;
    unordered_map<long long int, set<long long int>> index;
    for (long long int i = 0; i < n; i++) {
      mp[nums[i]] += 1;
      index[nums[i]].insert(i);
    }
    vector<set<long long int>> coloring(k);
    long long int id = 0;
    for (auto val : mp) {
      long long int hold = val.first;
      for (long long int i = 0; i < min(k, val.second); i++) {
        coloring[id].insert(hold);
        id = (id + 1) % k;
      }
    }
    long long int mn = INT_MAX;
    for (long long int i = 0; i < k; i++) {
      mn = min(mn, (long long int)coloring[i].size());
    }
    for (long long int i = 0; i < k; i++) {
      if (coloring[i].size() > mn) {
        for (long long int j = mn; j < coloring[i].size(); j++) {
          coloring[i].erase(coloring[i].begin());
        }
      }
    }
    for (long long int i = 0; i < k; i++) {
      for (long long int val : coloring[i]) {
        ans[*(index[val].begin())] = i + 1;
        index[val].erase(index[val].begin());
      }
    }
    for (long long int i = 0; i < n; i++) {
      if (ans[i] == -1) {
        cout << 0 << " ";
      } else {
        cout << ans[i] << " ";
      }
    }
    cout << "\n";
  }
}
