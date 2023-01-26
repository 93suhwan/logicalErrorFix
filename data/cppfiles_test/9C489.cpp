#include <bits/stdc++.h>
using namespace std;
bool cmp(int a, int b) { return a > b ? 1 : 0; }
int main() {
  int t, n;
  scanf("%d", &t);
  char str[51];
  while (t--) {
    scanf("%s", str);
    int a[26] = {0};
    for (int i = 0; str[i] != '\0'; i++) {
      a[str[i] - 'a']++;
    }
    sort(a, a + 26, cmp);
    int temp = 0;
    for (int i = 0; i < 26; i++) {
      if (a[i] != 0) {
        temp++;
      } else {
        break;
      }
    }
    if (temp > 1 || (temp == 1 && a[0] > 1)) {
      int ans = 0;
      for (int i = 0; i < temp; i++) {
        if (a[i] > 1) {
          ans++;
        } else {
          ans += (temp - i) / 2;
          break;
        }
      }
      printf("%d\n", ans);
    } else {
      printf("0\n");
    }
  }
  return 0;
}
