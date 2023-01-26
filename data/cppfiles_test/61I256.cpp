#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<pair<int, int>> a;
    map<int, int> mp, mp2;
    for (int i = 0; i < n; i++) {
      int j, k;
      cin >> j >> k;
      a.push_back({j, k});
      mp[k]++;
      mp2[j]++;
    }
    int j = n;
    long long my = (n * (n - 1) * (n - 2));
    my = my / 6;
    long long ans = 0;
    sort(a.begin(), a.end());
    for (int i = 0; i < n; i++) {
      mp[a[i].second]--;
      mp2[a[i].first]--;
      ans += (mp[a[i].second] * mp2[a[i].first]);
      mp[a[i].second]++;
      mp2[a[i].first]++;
    }
    cout << my - ans << endl;
  }
  return 0;
}
