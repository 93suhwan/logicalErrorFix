#include <bits/stdc++.h>
using namespace std;
unordered_map<int, unordered_set<int>> G;
int ans = 0;
void update(int i, int j, int op) {
  int mn = i;
  if (mn > j) mn = j;
  int mx = i + j - mn;
  if (op == 1) {
    if (G[mn].size() == 0) ans--;
    G[mn].insert(mx);
  } else {
    G[mn].erase(mx);
    if (G[mn].size() == 0) ans++;
  }
}
int main() {
  int n, m, i, j, q;
  scanf("%d %d", &n, &m);
  ans = n;
  for (int g = 0; g < m; g++) {
    scanf("%d %d", &i, &j);
    update(i, j, 1);
  }
  scanf("%d", &q);
  while (q > 0) {
    q--;
    int op;
    scanf("%d", &op);
    if (op == 3) {
      cout << ans << endl;
    } else {
      scanf("%d %d", &i, &j);
      update(i, j, op);
    }
  }
}
