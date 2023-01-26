#include <bits/stdc++.h>
using namespace std;
template <class T>
istream& operator>>(istream& in, vector<T>& vec) {
  for (auto& v : vec) {
    in >> v;
  }
  return in;
}
template <class T>
ostream& operator<<(ostream& o, const vector<T>& vec) {
  o << "[";
  for (const auto& v : vec) {
    o << v << ' ';
  }
  o << "]\n";
  return o;
}
int main() {
  int n, m, t;
  cin >> n >> m >> t;
  vector<vector<int>> mat(n, vector<int>(m));
  vector<vector<int>> bsm(m);
  cin >> mat;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (mat[i][j] != 2) {
        bsm[j].push_back(i);
      }
    }
  }
  while (t--) {
    int colI, rowI = -1;
    cin >> colI;
    colI--;
    while (true) {
      int newRowI = n;
      {
        auto& bsv = bsm[colI];
        int l = 0, r = bsv.size(), m;
        while (l < r) {
          m = (l + r) / 2;
          if (bsv[m] < rowI) {
            l = m + 1;
          } else {
            r = m;
          }
        }
        if (l < bsv.size()) {
          newRowI = bsv[l];
          int i = l + 1;
          for (; i < bsv.size() && bsv[i] == bsv[l]; i++) {
          }
          if (i < bsv.size()) {
            for (int a = l; a < i; a++) {
              bsv[a] = bsv[i];
            }
          } else {
            bsv.resize(bsv.size() - i + l);
          }
        }
      }
      rowI = newRowI;
      if (rowI >= n) {
        cout << colI + 1 << ' ';
        break;
      } else {
        if (mat[rowI][colI] == 1) {
          colI++;
        } else {
          colI--;
        }
      }
    }
  }
  cout << '\n';
}
