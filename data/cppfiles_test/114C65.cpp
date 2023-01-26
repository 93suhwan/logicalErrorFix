#include <bits/stdc++.h>
using namespace std;
int n;
vector<vector<int>> a;
int m;
vector<vector<int>> b;
int main() {
  scanf("%d", &n);
  a.resize(n);
  for (int i = 0; i < int(n); i++) {
    int c;
    scanf("%d", &c);
    a[i].resize(c);
    for (int j = 0; j < int(c); j++) scanf("%d", &a[i][j]);
  }
  scanf("%d", &m);
  b.resize(m);
  for (int i = 0; i < int(m); i++) {
    b[i].resize(n);
    for (int j = 0; j < int(n); j++) {
      scanf("%d", &b[i][j]);
      --b[i][j];
    }
  }
  sort(b.begin(), b.end());
  vector<int> ult(n);
  for (int i = 0; i < int(n); i++) ult[i] = int(a[i].size()) - 1;
  if (!binary_search(b.begin(), b.end(), ult)) {
    for (int i = 0; i < int(n); i++) printf("%d ", ult[i] + 1);
    puts("");
    return 0;
  }
  int mx = 0;
  vector<int> ans(n, -1);
  for (int i = 0; i < int(m); i++) {
    vector<int> tmp = b[i];
    int sum = 0;
    for (int j = 0; j < int(n); j++) sum += a[j][tmp[j]];
    for (int j = 0; j < int(n); j++)
      if (tmp[j] != 0) {
        --tmp[j];
        if (!binary_search(b.begin(), b.end(), tmp) &&
            sum - a[j][tmp[j] + 1] + a[j][tmp[j]] > mx) {
          mx = sum - a[j][tmp[j] + 1] + a[j][tmp[j]];
          ans = tmp;
        }
        ++tmp[j];
      }
  }
  for (int i = 0; i < int(n); i++) {
    printf("%d ", ans[i] + 1);
  }
  return 0;
}
