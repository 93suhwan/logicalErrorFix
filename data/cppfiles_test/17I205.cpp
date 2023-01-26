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
    int a[n][5];
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < 5; j++) cin >> a[i][j];
    }
    vector<int> v;
    for (int j = 0; j < 5; j++) {
      int mini = 1000000, ind = -1;
      for (int i = 0; i < n; i++) {
        if (a[i][j] < mini) {
          mini = a[i][j];
          ind = i;
        }
      }
      v.push_back(ind);
      ind = -1;
      int flag = 1000000;
      for (int i = 0; i < n; i++) {
        if (a[i][j] > mini && a[i][j] < flag) {
          flag = a[i][j];
          ind = i;
        }
      }
      if (ind != -1) v.push_back(ind);
    }
    int fg = 0, ans = 0;
    int siz = v.size();
    for (int k = 0; k < siz; k++) {
      int ind = v[k], maxi = 0;
      for (int i = 0; i < n; i++) {
        if (ind == i) continue;
        int cnt = 0;
        for (int j = 0; j < 5; j++) {
          if (a[i][j] > a[ind][j]) cnt++;
        }
        if (cnt >= 3) {
          maxi++;
        }
      }
      if (maxi == n - 1) {
        ans = ind;
        fg++;
      }
    }
    if (fg == 0)
      cout << -1;
    else
      cout << (ans + 1);
    cout << '\n';
  }
  return 0;
}
