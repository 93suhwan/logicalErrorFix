#include <bits/stdc++.h>
using namespace std;
int **M, n, m, **visited;
int area(int i, int j) {
  if (visited[i][j]) return 0;
  visited[i][j] = 1;
  int x = 0;
  if (!(M[i][j] & 1) && j > 0) {
    x += area(i, j - 1);
  }
  if (!((M[i][j] >> 1) & 1) && i < n - 1) {
    x += area(i + 1, j);
  }
  if (!((M[i][j] >> 2) & 1) && j < m - 1) {
    x += area(i, j + 1);
  }
  if (!((M[i][j] >> 3) & 1) && i > 0) {
    x += area(i - 1, j);
  }
  return x + 1;
}
int main() {
  int t, k, i;
  cin >> n >> m;
  M = new int *[n];
  visited = new int *[n];
  for (int i = 0; i < n; i++) M[i] = new int[m], visited[i] = new int[m];
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++) {
      visited[i][j] = 0;
      cin >> M[i][j];
    }
  multiset<int> ans;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (!visited[i][j]) {
        ans.insert(area(i, j));
      }
    }
  }
  for (auto elem = ans.rbegin(); elem != ans.rend(); elem++)
    cout << *elem << " ";
}
