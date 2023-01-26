#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    string ex;
    cin >> ex;
    int cnt = 0;
    for (int i = 0; i < n; i++) {
      cnt += (ex[i] == '2');
    }
    vector<vector<int> > ret(n, vector<int>(n, 0));
    if (cnt == 0) {
      puts("YES");
    } else if (cnt < 3) {
      puts("NO");
      continue;
    } else {
      puts("YES");
      vector<int> ok;
      for (int i = 0; i < n; i++)
        if (ex[i] == '2') ok.push_back(i);
      int x = ok[0], y = ok[1], z = ok[2];
      ret[x][y] = 1, ret[y][x] = 2;
      ret[y][z] = 1, ret[z][y] = 2;
      ret[z][x] = 1, ret[x][z] = 2;
      for (int i = 3; i < ok.size(); i++) {
        ret[ok[i]][ok[0]] = 1;
        ret[ok[0]][ok[i]] = 2;
      }
    }
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        if (i == j)
          cout << "X";
        else
          cout << (ret[i][j] == 1 ? "+" : (ret[i][j] == 2 ? "-" : "="));
        if (j == n - 1) cout << '\n';
      }
    }
  }
  return 0;
}
