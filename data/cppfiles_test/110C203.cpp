#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
bool indicator;
vector<vector<int>> arr;
vector<int> price;
vector<bool> visited;
int dfs(int x) {
  if (visited[x]) {
    if (price[x] == -1) {
      printf("-1\n");
      indicator = true;
      return -1;
    } else {
      return price[x];
    }
  }
  visited[x] = true;
  int curr = 1, temp;
  for (int i = 0; i < arr[x].size(); i++) {
    temp = dfs(arr[x][i]);
    if (arr[x][i] > x) temp++;
    curr = max(temp, curr);
    if (indicator) return -1;
  }
  return price[x] = curr;
}
void solve() {
  indicator = false;
  int n, x;
  scanf("%d", &n);
  arr.resize(n);
  price.resize(n, -1);
  visited.resize(n, false);
  for (int i = 0; i < n; i++) {
    scanf("%d", &x);
    arr[i].resize(x);
    for (int j = 0; j < x; j++) {
      scanf("%d", &arr[i][j]);
      arr[i][j]--;
    }
  }
  int ans = 1;
  for (int i = 0; i < n; i++) {
    if (visited[i]) continue;
    ans = max(ans, dfs(i));
    if (indicator) return;
  }
  printf("%d\n", ans);
}
int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    solve();
    arr.clear();
    price.clear();
    visited.clear();
  }
  return 0;
}
