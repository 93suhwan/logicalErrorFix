#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++) {
      cin >> arr[i];
    }
    vector<pair<int, int>> pr;
    int j = 1;
    int i = 0;
    while (i < n - 1 && j < n) {
      if (arr[i] > 0 && arr[j] > 0) {
        pr.push_back({i + 1, j + 1});
        arr[i]--;
        arr[j]--;
      } else if (arr[i] > 0 && arr[j] <= 0) {
        j++;
      } else if (arr[i] <= 0 && arr[j] > 0) {
        i = j;
        j++;
      } else {
        i = j + 1;
        j = i + 1;
      }
    }
    cout << pr.size() << endl;
    for (auto it = pr.begin(); it != pr.end(); it++) {
      cout << it->first << " " << it->second << endl;
    }
  }
  return 0;
}
