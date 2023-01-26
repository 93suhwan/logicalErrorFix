#include <bits/stdc++.h>
using namespace std;
long long solve() {
  long long n;
  cin >> n;
  vector<long long> arr(n + 1, 0);
  vector<pair<long long, pair<long long, long long>>> ranges(n), ans(n);
  for (int i = 0; i < n; i++) {
    cin >> ranges[i].second.first >> ranges[i].second.second;
    ranges[i].first = (-ranges[i].second.first + ranges[i].second.second) + 1;
  }
  sort(ranges.begin(), ranges.end());
  set<long long> unset;
  for (int i = 0; i < n; i++) {
    unset.clear();
    for (int j = ranges[i].second.first; j <= ranges[i].second.second; j++) {
      if (arr[j] == 0) unset.insert(j);
    }
    assert(unset.size() == 1);
    ans[i] = {*unset.begin(),
              {ranges[i].second.first, ranges[i].second.second}};
    arr[*unset.begin()] = 1;
  }
  for (int i = 0; i < n; i++)
    cout << ans[i].second.first << " " << ans[i].second.second << " "
         << ans[i].first << '\n';
  return 0;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long t;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
