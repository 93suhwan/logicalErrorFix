#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    int a[n][5];
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < 5; j++) {
        cin >> a[i][j];
      }
    }
    vector<int> days;
    for (int i = 0; i < 5; i++) {
      int cnt = 0;
      for (int j = 0; j < n; j++) {
        if (a[j][i] == 1) cnt++;
      }
      if (cnt >= n / 2) days.push_back(i);
    }
    int f = 0;
    for (int i = 0; i < days.size(); i++) {
      for (int j = i + 1; j < days.size(); j++) {
        int cnt1 = 0;
        for (int k = 0; k < n; k++) {
          if (a[k][days[i]] == 0 && a[k][days[j]] == 0) {
            break;
          } else {
            cnt1++;
          }
        }
        if (cnt1 == n) {
          f = 1;
          break;
        }
      }
      if (f == 1) break;
    }
    if (f == 1)
      cout << "YES\n";
    else
      cout << "NO\n";
  }
  return 0;
}
