#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
const int M = 5e5 + 5;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long int n, t, i, j, k, index;
  cin >> t;
  while (t--) {
    cin >> n >> k;
    vector<pair<long long int, long long int>> v(n);
    map<long long int, long long int> mp;
    vector<long long int> s(n);
    for (i = 0; i < n; i++) {
      cin >> v[i].first;
      s[i] = v[i].first;
      v[i].second = i + 1;
      mp[v[i].first]++;
    }
    sort(v.begin(), v.end());
    sort(s.begin(), s.end());
    vector<pair<long long int, long long int>> ans(n);
    for (i = 0; i < n; i++) {
      ans[i].first = -1;
    }
    for (auto it = mp.begin(); it != mp.end(); ++it) {
      if (it->second > k) {
        index = lower_bound(s.begin(), s.end(), it->first) - s.begin();
        for (i = index - 1; i < index - 1 + it->second - k; i++) {
          ans[i].first = 0;
        }
      }
    }
    long long int step = 0;
    for (i = 0; i < n; i++) {
      if (ans[i].first == -1) {
        ans[i].first = step + 1;
      }
      step++;
      if (step % k == 0) {
        step = 0;
      }
    }
    for (i = 0; i < n; i++) {
      ans[i].second = v[i].second;
    }
    for (i = 0; i < n; i++) {
      swap(ans[i].first, ans[i].second);
    }
    sort(ans.begin(), ans.end());
    for (i = 0; i < n; i++) {
      cout << ans[i].second << " ";
    }
    cout << '\n';
  }
}
