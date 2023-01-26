#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    int arr[n];
    vector<pair<int, int>> arr2;
    for (int i = 0; i < n; i++) {
      cin >> arr[i];
      arr2.push_back(make_pair(arr[i], i));
    }
    sort(arr2.begin(), arr2.end());
    int ans = 0;
    for (int i = n - 2; i >= 0; i--) {
      if (arr2[i].second > arr2[n - 1].second) {
        ans = n - arr2[i].second;
        break;
      }
    }
    cout << ans << endl;
  }
}
