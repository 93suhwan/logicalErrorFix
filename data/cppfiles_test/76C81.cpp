#include <bits/stdc++.h>
using namespace std;
int M[50][50], n, m;
bool check(vector<int> vec) {
  bool con = true, uncon = true;
  for (int i = 0; i < 5; i++) {
    for (int j = i + 1; j < 5; j++) {
      if (M[vec[i]][vec[j]])
        uncon = false;
      else
        con = false;
    }
  }
  return con || uncon;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> n >> m;
  for (int i = 1; i <= m; i++) {
    int x, y;
    cin >> x >> y;
    if (x <= 48 && y <= 48) M[x][y] = M[y][x] = 1;
  }
  vector<int> ans(5);
  for (int i = 1; i <= min(48, n); i++) {
    ans[0] = i;
    for (int j = i + 1; j <= min(48, n); j++) {
      ans[1] = j;
      for (int k = j + 1; k <= min(48, n); k++) {
        ans[2] = k;
        for (int h = k + 1; h <= min(48, n); h++) {
          ans[3] = h;
          for (int l = h + 1; l <= min(48, n); l++) {
            ans[4] = l;
            if (check(ans)) {
              for (int x : ans) cout << x << ' ';
              return 0;
            }
          }
        }
      }
    }
  }
  cout << "-1\n";
  return 0;
}
