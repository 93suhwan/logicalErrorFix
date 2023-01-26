#include <bits/stdc++.h>
using namespace std;
int k;
vector<vector<int>> ans;
int max_h;
void helper(int l, int r, int dep) {
  if (l >= r) return;
  int nodes = (r - l + 1) / k;
  int ll = (r - l + 1) % k;
  max_h = max(max_h, dep);
  int ns = l;
  for (int i = 0; i < k; i++) {
    int ne = nodes;
    if (i < ll) {
      ne++;
    }
    helper(ns, ns + ne - 1, dep + 1);
    ns = ns + ne;
  }
  for (int i = l; i <= r; i++) {
    for (int j = l + 1; j <= r; j++) {
      if (ans[i][j] == 0) ans[i][j] = dep + 1;
    }
  }
}
int main() {
  int n;
  cin >> n >> k;
  ans = vector<vector<int>>(n, vector<int>(n, 0));
  helper(0, n - 1, 0);
  cout << max_h << endl;
  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
      cout << ans[i][j] << " ";
    }
  }
}
