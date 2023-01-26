#include <bits/stdc++.h>
using namespace std;
int n, m, k;
int mp[1005][1005];
int cur;
int ji[1005];
int s;
char c;
int qr() {
  s = 0;
  c = getchar();
  while (c < '0' || c > '9') {
    c = getchar();
  }
  while (c >= '0' && c <= '9') {
    s = s * 10 + c - '0';
    c = getchar();
  }
  return s;
}
int main() {
  n = qr();
  m = qr();
  k = qr();
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      mp[i][j] = qr();
    }
  }
  for (int i = 1; i <= m; i++) {
    for (int j = n; j >= 1; j--) {
      if (mp[j][i] == 2) {
        ji[i] = j;
      } else {
        break;
      }
    }
  }
  for (int i = 1; i <= k; i++) {
    cur = qr();
    for (int j = 1; j <= n; j++) {
      if (ji[cur] <= j) {
        break;
      }
      while (mp[j][cur] != 2) {
        if (mp[j][cur] == 1) {
          mp[j][cur] = 2;
          cur++;
        } else {
          mp[j][cur] = 2;
          cur--;
        }
      }
    }
    printf("%d ", cur);
    for (int j = ji[cur]; j >= 1; j--) {
      if (mp[j][cur] == 2) {
        ji[i] = j;
      } else {
        break;
      }
    }
  }
  return 0;
}
