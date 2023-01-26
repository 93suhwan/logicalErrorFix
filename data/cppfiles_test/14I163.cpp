#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<int> arr;
    for (int i = 0; i < n; i++) {
      int x;
      cin >> x;
      arr.push_back(x);
    }
    vector<pair<int, pair<int, int>>> ans;
    for (int i = 0; i < n - 1; i++) {
      for (int j = i + 1; j < n; j++) {
        if (arr[i] > arr[j]) {
          swap(arr[i], arr[j]);
          ans.push_back({1, {i, j}});
        }
      }
    }
    cout << ans.size() << endl;
    for (int i = 0; i < ans.size(); i++) {
      cout << ans[i].second.first + 1 << " " << ans[i].second.second + 1 << " "
           << ans[i].first << endl;
    }
  }
  return 0;
}
