#include <bits/stdc++.h>
using namespace std;
const int N = 100;
char s[N];
int num[N];
int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    long long ans = 0;
    scanf("%s", s + 1);
    int len = strlen(s + 1);
    for (int i = 1; i <= len; ++i) {
      num[i] = s[i] - '0';
    }
    if (len == 1) {
      printf("%d\n", num[1] - 1);
      continue;
    }
    if (len == 2) {
      printf("%d\n", (num[1] + 1) * num[2]);
      continue;
    }
    int c = len - 2;
    for (int i = 0; i < (1 << c); ++i) {
      long long nowans = 1;
      int cur = i << 2;
      for (int j = len; j >= 1; --j) {
        int f = (cur >> (len - j)) & 1, pre = j - 2;
        int now = num[j];
        if (pre > 0 && ((cur >> (len - pre)) & 1)) {
          now += 10;
        }
        now -= f;
        if (now < 0 || now > 18) {
          nowans = 0;
          break;
        }
        if (now >= 10) {
          nowans *= (now + 1) - 2 * (now - 9);
        } else {
          nowans *= (now + 1);
        }
      }
      ans += nowans;
    }
    printf("%lld\n", ans - 2);
  }
}
