#include <bits/stdc++.h>
using namespace std;
int vis[20];
int res[20];
int main() {
  int t;
  cin >> t;
  vis[2] = vis[3] = vis[5] = vis[7] = 1;
  while (t--) {
    memset(res, 0, sizeof(res));
    int k;
    cin >> k;
    string a;
    cin >> a;
    int cnt = 0, flag = -1;
    for (int i = 0; i < k; i++) {
      if (!vis[a[i] - '0']) {
        flag = i;
        cnt = 1;
        break;
      }
    }
    if (flag >= 0) {
      cout << cnt << endl;
      cout << a[flag] << endl;
    } else {
      for (int i = 0; i < k; i++) {
        res[a[i] - '0']++;
      }
      flag = -1;
      for (int i = 1; i <= 9; i++) {
        if (res[i] > 1) {
          cnt = 2;
          flag = i;
          break;
        }
      }
      if (flag >= 0) {
        cout << 2 << endl;
        cout << flag << flag << endl;
        continue;
      } else {
        for (int i = 0; i < k; i++) {
          if (a[i] == '5') {
            flag = i;
          }
        }
        if (flag > 0) {
          cout << 2 << endl;
          cout << a[flag - 1] << a[flag] << endl;
          continue;
        } else {
          if (res[2] && res[7]) {
            for (int i = 0; i < k; i++) {
              if (a[i] == '2') {
                cout << 2 << endl << 27 << endl;
                break;
              }
              if (a[i] == '7') {
                cout << 2 << endl << 72 << endl;
                break;
              }
            }
          }
        }
      }
    }
  }
}
