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
    sort(rank[i], rank[i] + 5);
  }
  int bestidx[5];
  for (int i = 0; i < 5; i++) {
    int mrank = 1000000;
    int idx = -1;
    for (int j = 0; j < n; j++) {
      if (rank[j][i] < mrank) {
        mrank = rank[j][i];
        idx = j;
      }
    }
    int cnt = 0;
    for (int j = 0; j < n; j++) {
      if (rank[j][i] == mrank) {
        cnt++;
      }
    }
    if (cnt > 1) {
      idx = -1;
    }
    bestidx[i] = idx;
  }
  sort(bestidx, bestidx + 5);
  int cnt = 0;
  int i = 0;
  while (i < 5 && bestidx[i] == -1) {
    i++;
  }
  int f = -2;
  while (i < 5) {
    int cnt = 1;
    while (i + 1 < 5 && bestidx[i + 1] == bestidx[i]) {
      cnt++;
      i++;
    }
    if (cnt >= 3) {
      f = bestidx[i];
      break;
    }
    i++;
  }
  cout << f + 1 << endl;
}
int main() {
  s_y();
  int t = 1;
  cin >> t;
  while (t--) {
    solve();
  }
}
