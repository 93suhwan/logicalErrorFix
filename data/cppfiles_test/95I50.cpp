#include <bits/stdc++.h>
using namespace std;
bool debug;
int main(int argc, char *argv[]) {
  debug = argc > 0;
  int t;
  scanf("%d", &t);
  while (t--) {
    int n, m;
    scanf("%d%d", &n, &m);
    vector<vector<int>> board(n, vector<int>(m));
    for (int i = 0; i < n; i++)
      for (int j = 0; j < m; j++) scanf("%d", &board[i][j]);
    vector<vector<int>> maxiLeft = board;
    vector<vector<int>> miniRight = board;
    for (int i = 0; i < n; i++) {
      for (int j = 1; j < m; j++)
        maxiLeft[i][j] = max(maxiLeft[i][j], maxiLeft[i][j - 1]);
      for (int j = m - 2; j >= 0; j--)
        miniRight[i][j] = min(miniRight[i][j], miniRight[i][j + 1]);
    }
    bool possible = false;
    int cuttingCol = -1;
    vector<bool> config(n);
    auto cmp = [](tuple<int, int, int> &lhs, tuple<int, int, int> &rhs) {
      auto [mxl1, mnr1, id1] = lhs;
      auto [mxl2, mnr2, idr2] = rhs;
      if (mxl1 == mxl2) {
        return mnr1 < mnr2;
      } else {
        return mxl1 > mxl2;
      }
    };
    for (int j = 0; j < m - 1 && !possible; j++) {
      vector<tuple<int, int, int>> rowIdx;
      multiset<int> kecilKanan;
      for (int i = 0; i < n; i++) {
        rowIdx.emplace_back(maxiLeft[i][j], miniRight[i][j + 1], i);
        kecilKanan.insert(miniRight[i][j + 1]);
      }
      sort(rowIdx.begin(), rowIdx.end(), cmp);
      int maxiKanan = -1;
      for (int i = 0; i < n; i++) {
        auto [mxKiri, mnKanan, id] = rowIdx[i];
        maxiKanan = max(maxiKanan, mnKanan);
        kecilKanan.erase(kecilKanan.find(mnKanan));
        if (maxiKanan < *kecilKanan.begin()) {
          possible = true;
          cuttingCol = j;
          for (int k = 0; k <= i; k++) {
            config[get<2>(rowIdx[k])] = true;
          }
          break;
        }
      }
    }
    if (possible) {
      printf("YES\n");
      for (int i = 0; i < n; i++) {
        printf("%c", (config[i]) ? 'R' : 'B');
      }
      printf(" %d\n", cuttingCol + 1);
    } else {
      printf("NO\n");
    }
  }
  return 0;
}
