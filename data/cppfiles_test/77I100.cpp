#include <bits/stdc++.h>
using namespace std;
bool px(int a, int b) { return a > b; }
int main() {
  int n, m;
  cin >> n >> m;
  int tu[n + 5][m + 5];
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> tu[i][j];
    }
  }
  int sf = -1;
  vector<long long> mk;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      long long h = 0;
      queue<int> qu;
      queue<int> X;
      queue<int> Y;
      if (tu[i][j] >= 0) {
        qu.push(tu[i][j]);
        X.push(i);
        Y.push(j);
      }
      while (!qu.empty()) {
        int x = X.front(), y = Y.front(), s = qu.front();
        qu.pop();
        Y.pop();
        X.pop();
        h++;
        tu[x][y] = sf;
        int fx = 0;
        for (int is = 3; is >= 0; is--, fx++) {
          int ms = s >> is;
          if (ms % 2 == 0) {
            if (fx == 0 && x - 1 >= 0 && tu[x - 1][y] >= 0) {
              qu.push(tu[x - 1][y]);
              X.push(x - 1);
              Y.push(y);
            }
            if (fx == 1 && y + 1 < m && tu[x][y + 1] >= 0) {
              qu.push(tu[x][y + 1]);
              X.push(x);
              Y.push(y + 1);
            }
            if (fx == 2 && x + 1 < n && tu[x + 1][y] >= 0) {
              qu.push(tu[x + 1][y]);
              X.push(x + 1);
              Y.push(y);
            }
            if (fx == 3 && y - 1 >= 0 && tu[x][y - 1] >= 0) {
              qu.push(tu[x][y - 1]);
              X.push(x);
              Y.push(y - 1);
            }
          }
        }
      }
      if (h > 0) {
        mk.push_back(h);
      }
    }
  }
  sort(mk.begin(), mk.end(), px);
  for (int i = 0; i < mk.size(); i++) {
    cout << mk[i] << " ";
  }
  cout << endl;
  return 0;
}
