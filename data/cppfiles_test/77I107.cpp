#include <bits/stdc++.h>
using namespace std;
const int N = 1010;
int sum;
int a[N][N];
bool res[N][N];
int ssum[N];
bool cmp(int a, int b) { return a > b; }
void dfs(int i, int j) {
  sum++;
  res[i][j] = 1;
  if (!res[i - 1][j] && (8 & a[i][j])) dfs(i - 1, j);
  if (!res[i][j + 1] && (4 & a[i][j])) dfs(i, j + 1);
  if (!res[i + 1][j] && (2 & a[i][j])) dfs(i + 1, j);
  if (!res[i][j - 1] && (1 & a[i][j])) dfs(i, j - 1);
}
int main() {
  int n, m;
  int k = 0;
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> a[i][j];
      a[i][j] ^= 15;
    }
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (res[i][j] == 0) {
        sum = 0;
        dfs(i, j);
        ssum[k++] = sum;
      }
    }
  }
  sort(ssum, ssum + k, cmp);
  for (int i = 0; i <= k - 1; i++) {
    cout << ssum[i] << " ";
  }
  cout << endl;
  return 0;
}
