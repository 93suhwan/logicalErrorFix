#include <bits/stdc++.h>
using namespace std;
int mp[50010][5];
int main(void) {
  cin.tie(0);
  ios::sync_with_stdio(0);
  int t;
  cin >> t;
  while (t--) {
    int n, f = 0;
    cin >> n;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < 5; j++) cin >> mp[i][j];
      if (i != 0) {
        int sum = 0;
        for (int j = 0; j < 5; j++)
          if (mp[i][j] < mp[f][j]) sum++;
        if (sum >= 3) f = i;
      }
    }
    for (int i = 0; i < n; i++) {
      int sum = 0;
      for (int j = 0; j < 5; j++)
        if (mp[i][j] < mp[f][j]) sum++;
      if (sum >= 3) {
        f = -2;
        break;
      }
    }
    cout << f + 1 << endl;
  }
  return 0;
}
