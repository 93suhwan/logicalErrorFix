#include <bits/stdc++.h>
using namespace std;
const int limit = 1e3;
bool check[limit + 5][limit + 5] = {};
int n, m, cnt;
int a[limit + 5][limit + 5] = {};
void DFS(int i, int j) {
  if (check[i][j] || !i || !j || i > n || j > m) return;
  cnt++;
  check[i][j] = 1;
  if (a[i][j] % 2 == 0) {
    DFS(i, j - 1);
  }
  a[i][j] /= 2;
  if (a[i][j] % 2 == 0) {
    DFS(i + 1, j);
  }
  a[i][j] /= 2;
  if (a[i][j] % 2 == 0) {
    DFS(i, j + 1);
  }
  a[i][j] /= 2;
  if (a[i][j] % 2 == 0) {
    DFS(i - 1, j);
  }
}
vector<int> arr;
int main() {
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) cin >> a[i][j];
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      cnt = 0;
      DFS(i, j);
      if (cnt) arr.push_back(cnt);
    }
  }
  sort(arr.begin(), arr.end());
  for (int i = arr.size() - 1; i >= 0; i--) cout << arr[i] << ' ';
  return 0;
}
