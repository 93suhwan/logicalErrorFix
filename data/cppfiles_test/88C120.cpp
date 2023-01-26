#include <bits/stdc++.h>
using namespace std;
int a[100000];
vector<int> all;
map<int, int> L, R;
map<int, int> tmp;
int ans;
int n, m;
int alive[310][310];
void Set(int id) {
  int x = id / m, y = id % m;
  for (int i = 0; i <= y; i++) {
    ans += alive[x][i];
  }
  alive[x][y] = 1;
}
int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        alive[i][j] = 0;
      }
    }
    all.clear();
    for (int i = 0; i < n * m; i++) {
      scanf("%d", &a[i]);
      all.push_back(a[i]);
    }
    sort(all.begin(), all.end());
    L.clear(), R.clear(), tmp.clear();
    for (int i = 0; i < all.size(); i++) {
      R[all[i]] = i;
      if (!L.count(all[i])) L[all[i]] = i;
    }
    for (int i = 0; i < all.size(); i++) {
      tmp[all[i]] = L[all[i]] / m == R[all[i]] / m ? R[all[i]]
                                                   : L[all[i]] / m * m + m - 1;
    }
    ans = 0;
    for (int i = 0; i < n * m; i++) {
      int &l = L[a[i]], &r = R[a[i]], &x = tmp[a[i]];
      Set(x), x--;
      if (x < l) l = l / m * m + m, x = l / m == r / m ? r : l / m * m + m - 1;
    }
    printf("%d\n", ans);
  }
  return 0;
}
