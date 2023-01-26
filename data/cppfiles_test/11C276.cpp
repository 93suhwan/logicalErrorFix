#include <bits/stdc++.h>
using namespace std;
int t;
int n;
char li[400001];
int num[200001][5];
int wat[200001];
int l = 1, r = 0;
int res;
int getsum(int u) {
  int orz = 0;
  for (int i = 1; i <= 5; i++) {
    orz += num[u][i];
  }
  return orz;
}
int getrest(int u, int v) { return num[u][v] * 2 - getsum(u); }
void dfs(int u) {
  int ans = 0;
  l = 1;
  r = 0;
  int rst = 0;
  for (int i = 1; i <= n; i++) {
    int tmp = getrest(i, u);
    wat[++r] = tmp;
  }
  sort(wat + 1, wat + 1 + r);
  while (l <= r) {
    if (rst + wat[r] > 0) {
      ans++;
      rst += wat[r];
      r--;
      continue;
    }
    break;
  }
  res = max(res, ans);
}
int main() {
  cin >> t;
  while (t--) {
    cin >> n;
    memset(num, 0, sizeof(num));
    res = 0;
    for (int i = 1; i <= n; i++) {
      scanf("%s", li + 1);
      int len = strlen(li + 1);
      for (int j = 1; j <= len; j++) {
        num[i][li[j] - 'a' + 1]++;
      }
    }
    for (int i = 1; i <= 5; i++) dfs(i);
    cout << res << endl;
  }
}
