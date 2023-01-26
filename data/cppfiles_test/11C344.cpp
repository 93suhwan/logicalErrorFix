#include <bits/stdc++.h>
using namespace std;
int t, n;
string s;
int main() {
  cin >> t;
  while (t--) {
    cin >> n;
    int i, k;
    vector<string> vec(n);
    vector<vector<int>> diff(5, vector<int>(n, 0));
    for (i = 0; i < n; i++) {
      cin >> vec[i];
      for (auto j : vec[i]) {
        for (k = 97; k < 102; k++) {
          if (j == k)
            diff[k - 97][i]++;
          else
            diff[k - 97][i]--;
        }
      }
    }
    int m = 0;
    for (i = 0; i < 5; i++) {
      int sum = 0;
      sort(diff[i].begin(), diff[i].end(), greater<int>());
      for (k = 0; k < n; k++) {
        if (sum + diff[i][k] > 0) {
          sum += diff[i][k];
        } else {
          m = max(k, m);
          break;
        }
      }
      if (k == n) m = n;
    }
    cout << m << "\n";
  }
  return 0;
}
