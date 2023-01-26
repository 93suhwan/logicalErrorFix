#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  int n, m;
  int i, j;
  int ans;
  vector<int> v1, v2;
  scanf("%d", &t);
  int flag = 0;
  while (t--) {
    v1.clear();
    v2.clear();
    flag = 0;
    scanf("%d%d", &n, &m);
    if (n == 0) {
      ans = m + 1;
      printf("%d\n", ans);
      continue;
    }
    if (n > m) {
      ans = 0;
      printf("%d\n", ans);
      continue;
    }
    int tmp = n;
    while (tmp > 0) {
      v1.push_back(tmp & 1);
      tmp = tmp >> 1;
    }
    tmp = m;
    while (tmp > 0) {
      v2.push_back(tmp & 1);
      tmp = tmp >> 1;
    }
    for (i = v1.size() - 1; i >= 0; i--) {
      if (v1[i] == v2[i]) continue;
      if (v1[i] > v2[i]) {
        flag = 1;
        break;
      }
    }
    int l;
    tmp = m + 1;
    j = 0;
    while (tmp > 0 && (tmp & 1) == 0) {
      tmp = tmp >> 1;
      j++;
    }
    ans = n ^ (m + 1);
    l = i + 1;
    ans = ans >> l;
    ans = ans << l;
    ans = ans >> j;
    ans = ans << j;
    printf("%d\n", ans);
  }
  return 0;
}
