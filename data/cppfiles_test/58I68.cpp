#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, t;
  cin >> t;
  while (t--) {
    cin >> n;
    int a[2][n];
    vector<pair<int, int>> v;
    for (int i = 0; i < 2; i++) {
      for (int j = 0; j < n; j++) {
        cin >> a[i][j];
        if (a[i][j] == 0) {
          v.push_back(make_pair(i, j));
        }
      }
    }
    int flag = 0;
    for (int i = 0; i < v.size(); i++) {
      if (v[i].first == 0) {
        if (a[v[i].first + 1][v[i].second + 1] == 1 &&
            a[v[i].first][v[i].second + 1] == 1 &&
            a[v[i].first + 1][v[i].second] == 1) {
          flag = 1;
          break;
        }
      } else {
        if (a[v[i].first - 1][v[i].second + 1] == 1 &&
            a[v[i].first][v[i].second + 1] == 1 &&
            a[v[i].first - 1][v[i].second] == 1) {
          flag = 1;
          break;
        }
      }
    }
    if (flag == 0) {
      cout << "YES\n";
    } else {
      cout << "NO\n";
    }
  }
}
