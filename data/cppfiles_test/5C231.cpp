#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int test;
  cin >> test;
  while (test--) {
    int n;
    cin >> n;
    string e, g;
    cin >> e;
    cin >> g;
    int cnt = 0;
    for (int i = 0; i < n; i++) {
      if (g[i] == '1') {
        if (e[i] == '0') {
          cnt++;
          e[i] = '2';
        } else if (i == 0) {
          if (e[i + 1] == '1') {
            cnt++;
            e[i + 1] = '2';
          }
        } else if (i == n - 1) {
          if (e[i - 1] == '1') {
            cnt++;
            e[i - 1] = '2';
          }
        } else if (e[i - 1] == '1') {
          cnt++;
          e[i - 1] = '2';
        } else if (e[i + 1] == '1') {
          cnt++;
          e[i + 1] = '2';
        }
      }
    }
    cout << cnt << "\n";
  }
  return 0;
}
