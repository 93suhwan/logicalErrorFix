#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 5;
int T, k, cnt[10], la[10], a[5] = {1, 4, 6, 8, 9};
char s[55];
int main() {
  scanf("%d", &T);
  while (T--) {
    int f = 0;
    memset(cnt, 0, sizeof(cnt));
    memset(la, 0, sizeof(la));
    scanf("%d", &k);
    scanf("%s", s);
    for (int i = k - 1; i >= 0; --i) cnt[s[i] - '0']++, la[s[i] - '0'] = i;
    for (int i = 0; i < 5; ++i)
      if (cnt[a[i]]) {
        printf("1\n%d\n", a[i]);
        f = 1;
        break;
      }
    if (f) continue;
    if (f == 0 && cnt[2]) {
      for (int j = la[2] + 1; j < k; ++j) {
        if (s[j] == '2' || s[j] == '5' || s[j] == '7') {
          printf("2\n2%c\n", s[j]);
          f = 1;
          break;
        }
      }
    }
    if (f == 0 && cnt[3]) {
      for (int j = la[3] + 1; j < k; ++j) {
        if (s[j] == '2' || s[j] == '3' || s[j] == '5') {
          printf("2\n3%c\n", s[j]);
          f = 1;
          break;
        }
      }
    }
    if (f == 0 && cnt[5]) {
      for (int j = la[5] + 1; j < k; ++j) {
        if (s[j] == '2' || s[j] == '5' || s[j] == '7') {
          printf("2\n5%c\n", s[j]);
          f = 1;
          break;
        }
      }
    }
    if (f == 0 && cnt[7]) {
      for (int j = la[7] + 1; j < k; ++j) {
        if (s[j] == '2' || s[j] == '5' || s[j] == '7') {
          printf("2\n7%c\n", s[j]);
          f = 1;
          break;
        }
      }
    }
  }
  return 0;
}
