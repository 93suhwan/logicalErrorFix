#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m, k;
  cin >> n >> m >> k;
  int a[n + 1][m + 1];
  int c;
  pair<int, int> v;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) cin >> a[i][j];
  }
  for (int i = 1; i <= k; i++) {
    cin >> c;
    v = {1, c};
    while (v.first <= n) {
      int id1 = v.first, id2 = v.second;
      if (a[id1][id2] == 1)
        v.second++;
      else if (a[id1][id2] == 2)
        v.first++;
      else if (a[id1][id2] == 3)
        v.second--;
      a[id1][id2] = 2;
    }
    cout << v.second << " ";
  }
}
