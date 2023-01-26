#include <bits/stdc++.h>
using namespace std;
using namespace std;
const int N = 25;
int a[N][N];
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int t;
  char c;
  int n, m, k;
  vector<pair<int, int> > v;
  pair<int, int> p;
  cin >> t;
  while (t--) {
    v.clear();
    cin >> n >> m >> k;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        cin >> c;
        if (c == '*') {
          a[i][j] = 1;
          p.first = i;
          p.second = j;
          v.push_back(p);
        } else {
          a[i][j] = 0;
        }
      }
    }
    for (vector<pair<int, int> >::iterator it = v.begin(); it != v.end();
         it++) {
      int x = it->first;
      int y = it->second;
      int d = 1;
      while (x - d >= 0 && y - d >= 0 && y + d < m && a[x - d][y - d] > 0 &&
             a[x - d][y + d] > 0) {
        d++;
      }
      a[x][y] = max(a[x][y], d);
      for (int i = 0; i < d; i++) {
        a[x - i][y - i] = max(a[x - i][y - i], d);
        a[x - i][y + i] = max(a[x - i][y + i], d);
      }
    }
    int flag = 1;
    for (vector<pair<int, int> >::iterator it = v.begin();
         flag && it != v.end(); it++) {
      int x = it->first;
      int y = it->second;
      if (a[x][y] <= k) {
        flag = 0;
      }
    }
    if (flag) {
      cout << "YES\n";
    } else {
      cout << "NO\n";
    }
  }
  return 0;
}
