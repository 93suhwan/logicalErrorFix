#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e3 + 10;
vector<int> vecr[maxn], vecl[maxn];
int main() {
  int n, m, k;
  cin >> n >> m >> k;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      int s;
      cin >> s;
      if (s == 1) {
        vecr[j].push_back(i);
      }
      if (s == 3) {
        vecl[j].push_back(i);
      }
    }
  }
  for (int i = 1; i <= k; i++) {
    int v;
    cin >> v;
    int row = 1;
    int col = v;
    while (true) {
      int ok = 0;
      {
        auto upper =
            std::upper_bound(vecl[col].begin(), vecl[col].end(), row - 1);
        if (upper != vecl[col].end()) {
          row = *upper;
          int xd = std::distance(vecl[col].begin(), upper);
          vecl[col].erase(vecl[col].begin() + xd);
          col--;
          ok = 1;
        }
      }
      if (ok == 0) {
        auto upper =
            std::upper_bound(vecr[col].begin(), vecr[col].end(), row - 1);
        if (upper != vecr[col].end()) {
          row = *upper;
          int xd = std::distance(vecr[col].begin(), upper);
          vecr[col].erase(vecr[col].begin() + xd);
          col++;
          ok = 1;
        }
      }
      if (ok == 0) {
        cout << col << " ";
        break;
      }
    }
  }
  return 0;
}
