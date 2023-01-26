#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    int r[n][5];
    for (int i = 0; i < n; i++)
      for (int j = 0; j < 5; j++) cin >> r[i][j];
    map<int, int> mp;
    for (int i = 1; i <= n; i++) mp[i] = 0;
    for (int i = 0; i < 5; i++) {
      int minIndex = -1;
      int minValue = INT_MAX;
      for (int j = 0; j < n; j++) {
        if (r[j][i] < minValue) {
          minValue = r[j][i];
          minIndex = j;
        }
      }
      ++mp[minIndex + 1];
    }
    int maxValue = 0;
    int player = -1;
    for (auto x : mp) {
      if (x.second > maxValue) {
        maxValue = x.second;
        player = x.first;
      }
    }
    int count = 0;
    for (auto x : mp) {
      if (x.second == maxValue) ++count;
    }
    if (count > 1)
      cout << "-1" << endl;
    else
      cout << player << endl;
  }
  return 0;
}
