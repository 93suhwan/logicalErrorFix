#include <bits/stdc++.h>
using namespace std;
const int Maxn = 1e6 + 10;
int a[Maxn];
pair<int, int> ma[Maxn][5];
int pre[Maxn][5];
int main() {
  int cas, n;
  cin >> cas;
  while (cas--) {
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    int cnt = 0;
    ma[0][cnt++] = pair<int, int>(-Maxn, -Maxn);
    for (int i = 1; i <= n; i++) {
      if (cnt == 0) break;
      int b[4] = {Maxn, Maxn, Maxn, Maxn};
      int pre_index[4] = {-1, -1, -1, -1};
      for (int j = 0; j < cnt; j++) {
        if (-a[i] > ma[i - 1][j].first && b[0] > ma[i - 1][j].second)
          b[0] = ma[i - 1][j].second, pre_index[0] = j;
        else if (-a[i] > ma[i - 1][j].second && b[1] > ma[i - 1][j].first)
          b[1] = ma[i - 1][j].first, pre_index[1] = j;
        if (a[i] > ma[i - 1][j].first && b[2] > ma[i - 1][j].second)
          b[2] = ma[i - 1][j].second, pre_index[2] = j;
        else if (a[i] > ma[i - 1][j].second && b[3] > ma[i - 1][j].first)
          b[3] = ma[i - 1][j].first, pre_index[3] = j;
      }
      cnt = 0;
      if (b[0] != Maxn)
        pre[i][cnt] = pre_index[0], ma[i][cnt++] = pair<int, int>(-a[i], b[0]);
      if (b[1] != Maxn)
        pre[i][cnt] = pre_index[1], ma[i][cnt++] = pair<int, int>(b[1], -a[i]);
      if (b[2] != Maxn)
        pre[i][cnt] = pre_index[2], ma[i][cnt++] = pair<int, int>(a[i], b[2]);
      if (b[3] != Maxn)
        pre[i][cnt] = pre_index[3], ma[i][cnt++] = pair<int, int>(b[3], a[i]);
    }
    if (!cnt) {
      cout << "NO\n";
      continue;
    }
    cout << "YES\n";
    for (int i = n, index = 0; i > 0; i--) {
      pair<int, int> res = ma[i][index];
      index = pre[i][index];
      if (res.first == -a[i] || res.second == -a[i]) a[i] *= -1;
    }
    for (int i = 1; i <= n; i++) cout << a[i] << " ";
    cout << endl;
  }
}
