#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 5;
const double eps = 1e-8;
const int maxp = 1010;
char s1[N], s2[N];
int vis[N];
int vis2[N];
signed main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
      vis[i] = 0;
      vis2[i] = 0;
    }
    scanf("%s%s", s1 + 1, s2 + 1);
    int sum = 0;
    for (int i = 1; i <= n; i++) {
      if (s1[i] == '1') {
        if (!vis[i]) {
          if (i >= 2 && s2[i - 1] == '1' && !vis2[i - 1]) {
            vis2[i - 1] = 1;
            vis[i] = 1;
            sum++;
          }
        }
        if (!vis[i]) {
          if (i + 1 <= n && s2[i + 1] == '1' && !vis2[i + 1]) {
            vis2[i + 1] = 1;
            vis[i] = 1;
            sum++;
          }
        }
      } else {
        if (!vis[i]) {
          if (!vis2[i] && s2[i] == '1') {
            vis2[i] = 1;
            vis[i] = 1;
            sum++;
          }
        }
      }
    }
    printf("%d\n", sum);
  }
}
