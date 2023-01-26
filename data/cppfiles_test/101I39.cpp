#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<vector<int>> a(n);
    for (int i = 0; i < n; i++) {
      int u;
      cin >> u;
      a[i].push_back(u);
    }
    for (int i = 0; i < n; i++) {
      char ch;
      cin >> ch;
      if (ch == 'B') {
        a[i].push_back(-1);
      } else {
        a[i].push_back(1);
      }
    }
    long long int tot = 0;
    bool flg = true;
    sort(a.begin(), a.end());
    for (int i = 0; i < n; i++) {
      int o = i + 1;
      if (a[i][0] > o) {
        if (a[i][1] == -1) {
          tot += a[i][0] - o;
        } else {
          int j = a[i][0] - 1;
          while (j < n) {
            if (a[j][1] == -1) {
              break;
            }
            j++;
          }
          if (j >= n) {
            cout << "NO\n";
            flg = false;
            break;
          }
        }
      } else if (a[i][0] < o) {
        if (a[i][1] == 1) {
          tot += o - a[i][0];
        } else {
          int j = i - 1;
          while (j >= 0) {
            if (a[j][1] == 1) {
              break;
            }
            j--;
          }
          if (j < 0) {
            cout << "NO\n";
            flg = false;
            break;
          }
        }
      }
    }
    if (flg) {
      cout << "YES\n";
    }
  }
}
