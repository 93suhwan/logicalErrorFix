#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    int cave_size[n];
    vector<pair<int, int>> v;
    while (n--) {
      int k;
      cin >> k;
      int curr = 0;
      for (int i = 0; i < k; i++) {
        int temp;
        cin >> temp;
        curr = max(curr, temp + 1 - i);
      }
      v.push_back({curr, k});
    }
    sort(v.begin(), v.end());
    int curr = v[0].first;
    int ans = curr;
    for (int i = 0; i < v.size(); i++) {
      ans += max(0, v[i].first - curr);
      curr += v[i].second;
    }
    cout << ans << endl;
  }
  return 0;
}
