#include <bits/stdc++.h>
using namespace std;
int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    char num[55];
    int k, cnt[11];
    scanf("%d", &k);
    scanf("%s", num + 1);
    int ans = 0, len;
    for (int i = 1; i <= k; i++) {
      if (num[i] == '1' || num[i] == '4' || num[i] == '6' || num[i] == '8' ||
          num[i] == '9') {
        len = 1, ans = num[i] - '0';
        break;
      }
      cnt[num[i] - '0']++;
    }
    if (ans) {
      printf("%d\n%d\n", len, ans);
      continue;
    }
    for (int i = 1; i <= 9; i++) {
      if (cnt[i] >= 2) {
        len = 2, ans = i * 10 + i;
        break;
      }
    }
    if (ans) {
      printf("%d\n%d\n", len, ans);
      continue;
    } else {
      if (cnt[5]) {
        for (int i = 1; i <= k; i++) {
          if (num[i] != '5') {
            printf("2\n%c5", num[i]);
            break;
          }
        }
      } else if (cnt[2]) {
        for (int i = 1; i <= k; i++) {
          if (num[i] != '2') {
            printf("2\n%c2", num[i]);
            break;
          }
        }
      } else {
        int cnt = 0;
        for (int i = 1; i <= k; i++) {
          if (num[i] == '7' || num[i] == '3') {
            printf("%c", num[i]);
            cnt++;
          }
          if (cnt == 2) break;
        }
      }
    }
  }
  return 0;
}
