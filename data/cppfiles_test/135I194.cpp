#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    int n, k;
    cin >> n >> k;
    vector<int> v(n);
    for (auto &it : v) cin >> it;
    sort(v.begin(), v.end());
    int ans = 0;
    for (int i = 0; i < n - k - k; i++) {
      ans += v[i];
    }
    map<int, int> mp;
    for (int i = n - k - k; i < n; i++) {
      mp[v[i]]++;
    }
    vector<int> test;
    for (auto it : mp) {
      test.push_back(it.second);
    }
    for (int i = 0; i < (int)test.size(); i++) {
      for (int j = i + 1; j < (int)test.size(); j++) {
        int mi = min(test[i], test[j]);
        test[i] -= mi;
        test[j] -= mi;
      }
    }
    for (int i = 0; i < (int)test.size(); i++) ans += test[i] / 2;
    cout << ans << '\n';
  }
  return 0;
}
