#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, m;
    cin >> n >> m;
    vector<int> arr;
    for (int i = 0; i < m; i++) {
      int temp;
      cin >> temp;
      arr.push_back(temp);
    }
    vector<int> arr2;
    for (int i = m - 1; i >= 0; i--) {
      arr2.push_back(arr[i]);
    }
    sort(arr2.begin(), arr2.end());
    vector<int> index(m, m + 1);
    int ans = 0;
    for (int i = 0; i < m; i++) {
      int val = arr[i];
      int ind;
      for (int j = m - 1; j >= 0; j--) {
        if (val == arr2[j]) {
          ind = j;
          break;
        }
      }
      int count = 0;
      for (int j = 0; j < i; j++) {
        if (index[j] < ind) count++;
      }
      index[i] = ind;
      ans += count;
    }
    cout << ans << "\n";
  }
}
