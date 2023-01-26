#include <bits/stdc++.h>
const int int_reme = 2147483647;
const int log21e9_reme = 30;
const int maxn = 2e5 + 10;
const long long mod = 1e9 + 7;
const int INF = 0x3f3f3f3f;
using namespace std;
char DATA[maxn], duizhao[maxn];
int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int n;
    scanf("%d", &n);
    DATA[0] = 2;
    getchar();
    for (int i = 1; i <= n; i++) {
      scanf("%c", &DATA[i]);
    }
    getchar();
    for (int i = 1; i <= n; i++) {
      scanf("%c", &duizhao[i]);
    }
    int ans = 0;
    for (int i = 1; i <= n; i++) {
      if (duizhao[i] == '1') {
        if (DATA[i] == '0')
          ans++;
        else {
          if (DATA[i - 1] == '1') {
            DATA[i - 1] = '2';
            ans++;
          } else if (DATA[i + 1] == '1') {
            DATA[i + 1] = '2';
            ans++;
          }
        }
      }
    }
    printf("%d\n", ans);
  }
  return 0;
}
