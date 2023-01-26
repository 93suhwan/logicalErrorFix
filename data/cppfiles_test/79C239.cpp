#include <bits/stdc++.h>
using namespace std;
int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    char num[55];
    int k, cnt[11];
    memset(cnt, 0, sizeof(cnt));
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
      printf("2\n");
      if (cnt[5] && num[1] != '5')
        printf("%c5", num[1]);
      else if (cnt[2] && num[1] != '2')
        printf("%c2", num[1]);
      else if (cnt[7] && cnt[2]) {
        int cnt = 0;
        for (int i = 1; i <= k; i++) {
          if (num[i] == '7' || num[i] == '2') {
            printf("%c", num[i]);
            cnt++;
          }
          if (cnt == 2) break;
        }
      } else if (cnt[5] && cnt[7]) {
        int cnt = 0;
        for (int i = 1; i <= k; i++) {
          if (num[i] == '5' || num[i] == '7') {
            printf("%c", num[i]);
            cnt++;
          }
          if (cnt == 2) break;
        }
      }
      printf("\n");
    }
  }
  return 0;
}
