#include <bits/stdc++.h>
using namespace std;
void leftRotatebyOne(vector<int> &arr, int n, int s) {
  int temp = arr[s], i;
  for (i = s; i < n; i++) arr[i] = arr[i + 1];
  arr[n] = temp;
}
void leftRotate(vector<int> &arr, int d, int n, int s) {
  for (int i = 0; i < d; i++) leftRotatebyOne(arr, n, s);
}
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
          leftRotate(arr, j - i, j, i);
          ans.push_back({j - i, {i, j}});
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
