#include <bits/stdc++.h>
using namespace std;
void s_y() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
}
void solve() {
  int n;
  cin >> n;
  int rank[n][5];
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < 5; j++) {
      cin >> rank[i][j];
    }
  }
  int bestc[5];
  int idx = 0;
  for (int i = 0; i < 5; i++) {
    bestc[i] = rank[0][i];
  }
  for (int i = 1; i < n; i++) {
    int ptbc = 0;
    int ptnc = 0;
    for (int j = 0; j < 5; j++) {
      if (bestc[j] == rank[i][j]) {
      } else if (bestc[j] > rank[i][j]) {
        ptnc++;
      } else {
        ptbc++;
      }
    }
    if (ptnc > ptbc) {
      for (int j = 0; j < 5; j++) {
        bestc[j] = rank[i][j];
        idx = i;
      }
    }
  }
  for (int i = 0; i < n; i++) {
    if (i != idx) {
      int ptbc = 0;
      int ptnc = 0;
      for (int j = 0; j < 5; j++) {
        if (bestc[j] == rank[i][j]) {
        } else if (bestc[j] > rank[i][j]) {
          ptnc++;
        } else {
          ptbc++;
        }
      }
      if (ptbc < 3) {
        idx = -2;
      }
    }
  }
  cout << idx + 1 << endl;
}
int main() {
  s_y();
  int t = 1;
  cin >> t;
  while (t--) {
    solve();
  }
}
