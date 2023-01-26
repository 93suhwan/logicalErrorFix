#include <bits/stdc++.h>
using namespace std;
const int64_t inf = 1e18;
const int64_t mod = 998244353;
int32_t main() {
  int64_t q;
  cin >> q;
  while (q--) {
    int64_t n;
    cin >> n;
    vector<int64_t> arr(n);
    for (int64_t& e : arr) {
      cin >> e;
    }
    vector<pair<int64_t, int64_t>> lst{{inf, 1}};
    int64_t ans = 0;
    for (int64_t i = n - 1; i >= 0; --i) {
      vector<pair<int64_t, int64_t>> new_lst;
      for (auto& e : lst) {
        int64_t d = (arr[i] + e.first - 1) / e.first;
        ans += e.second * (i + 1) * (d - 1) % mod;
        new_lst.push_back({arr[i] / d, e.second});
      }
      lst.clear();
      lst.push_back(new_lst[0]);
      for (int64_t i = 1; i < new_lst.size(); ++i) {
        if (new_lst[i].first == lst.back().first) {
          lst.back().second += new_lst[i].second;
        } else {
          lst.push_back(new_lst[i]);
        }
      }
      lst.push_back({inf, 1});
    }
    cout << ans << endl;
  }
}
