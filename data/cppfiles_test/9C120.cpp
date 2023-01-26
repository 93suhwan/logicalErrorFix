#include <bits/stdc++.h>
using namespace std;
const int N = 1001;
int n, m, k;
int arr[N][N];
int dfs(int i, int j) {
  if (i == n) return j;
  if (arr[i][j] == 1) {
    arr[i][j] = 2;
    return dfs(i, j + 1);
  } else if (arr[i][j] == 2) {
    return dfs(i + 1, j);
  } else {
    arr[i][j] = 2;
    return dfs(i, j - 1);
  }
}
int main() {
  cin >> n >> m >> k;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> arr[i][j];
    }
  }
  vector<int> ans;
  while (k--) {
    int a;
    cin >> a;
    a--;
    ans.push_back(dfs(0, a));
  }
  for (int i : ans) cout << i + 1 << " ";
  return 0;
}
