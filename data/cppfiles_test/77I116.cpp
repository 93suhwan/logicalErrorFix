#include <bits/stdc++.h>
using namespace std;
struct debugger {
  static void call(string::iterator it, string::iterator ed) {}
  template <typename T, typename... aT>
  static void call(string::iterator it, string::iterator ed, T a, aT... rest) {
    string b;
    for (; *it != ','; ++it)
      if (*it != ' ') b += *it;
    cout << b << "=" << a << " ";
    call(++it, ed, rest...);
  }
};
int a[1005][1005], n, m;
int check[1005][1005] = {0};
int dfs(int i, int j, int ans) {
  if (check[i][j]) {
    return 0;
  }
  check[i][j] = 1;
  int k = 0;
  if (!a[i][j] && i > 0 && !a[i - 1][j + 2]) {
    a[i][j] = 1;
    k += 1 + dfs(i - 1, j, 0);
  }
  if (!a[i][j + 1] && j + 7 < m * 4 && !a[i][j + 7]) {
    a[i][j + 1] = 1;
    k += 1 + dfs(i, j + 4, 0);
  }
  if (!a[i][j + 3] && j >= 4 && !a[i][j - 3]) {
    a[i][j + 3] = 1;
    k += 1 + dfs(i, j - 4, 0);
  }
  if (!a[i][j + 2] && i < n - 1 && !a[i + 1][j]) {
    a[i][j + 2] = 1;
    k += 1 + dfs(i + 1, j, 0);
  }
  a[i][j] = a[i][j + 1] = a[i][j + 2] = a[i][j + 3] = 1;
  return k + ans;
}
int dfs(int i, int j) {
  if (check[i][j]) {
    return 0;
  }
  check[i][j] = 1;
  int k = 0;
  if (!a[i][j] && i > 0 && !a[i - 1][j + 2]) {
    a[i][j] = 1;
    k += 1 + dfs(i - 1, j, 0);
  }
  if (!a[i][j + 1] && j + 7 < m * 4 && !a[i][j + 7]) {
    a[i][j + 1] = 1;
    k += 1 + dfs(i, j + 4, 0);
  }
  if (!a[i][j + 3] && j - 3 > 0 && !a[i][j - 3]) {
    a[i][j + 3] = 1;
    k += 1 + dfs(i, j - 4, 0);
  }
  if (!a[i][j + 2] && i + 1 < n && !a[i + 1][j]) {
    a[i][j + 2] = 1;
    k += 1 + dfs(i + 1, j, 0);
  }
  a[i][j] = a[i][j + 1] = a[i][j + 2] = a[i][j + 3] = 1;
  return k + 1;
}
void solve() {
  scanf("%d %d", &n, &m);
  ;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      int k;
      string::iterator(k);
      int l = (j + 1) * 4 - 1;
      while (k > 1) {
        a[i][l] = k % 2;
        k /= 2;
        l--;
      }
      a[i][l] = k;
    }
  }
  vector<int> ans;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      int k = dfs(i, j * 4);
      if (k) {
        ans.push_back(k);
      }
    }
  }
  sort(ans.begin(), ans.end(), greater<int>());
  for (auto i : ans) {
    cout << i << " ";
  }
  cout << "\n";
}
int main() {
  int t = 1;
  while (t--) {
    solve();
  }
  return 0;
}
