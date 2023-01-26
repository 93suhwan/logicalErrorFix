#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> a, b;
int main() {
  int n;
  scanf("%d", &n);
  a.resize(n);
  for (int i = 0; i < n; i++) {
    int x;
    scanf("%d", &x);
    a[i].resize(x);
    for (int j = 0; j < x; j++) {
      scanf("%d", &a[i][j]);
    }
  }
  int m;
  scanf("%d", &m);
  b.resize(m);
  for (int i = 0; i < m; i++) {
    b[i].resize(n);
    for (int j = 0; j < n; j++) {
      scanf("%d", &b[i][j]);
      b[i][j]--;
    }
  }
  vector<int> now(n);
  for (int i = 0; i < n; i++) {
    now[i] = (int)a[i].size() - 1;
  }
  sort(b.begin(), b.end());
  if (!binary_search(b.begin(), b.end(), now)) {
    for (int i = 0; i < n; i++) {
      printf("%d ", now[i] + 1);
    }
    return 0;
  }
  vector<int> ans(n, -1);
  int Max = 0;
  for (int i = 0; i < m; i++) {
    vector<int> temp = b[i];
    int sum = 0;
    for (int j = 0; j < n; j++) {
      sum += a[j][temp[j]];
    }
    for (int j = 0; j < n; j++) {
      if (temp[j] != 0) {
        temp[j]--;
        if (!binary_search(b.begin(), b.end(), temp) &&
            Max < sum - a[j][temp[j] + 1] + a[j][temp[j]]) {
          Max = sum - a[j][temp[j] + 1] + a[j][temp[j]];
          ans = temp;
        }
        temp[j]++;
      }
    }
  }
  for (int i = 0; i < n; i++) {
    printf("%d ", ans[i] + 1);
  }
  return 0;
}
