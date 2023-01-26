#include <bits/stdc++.h>
using namespace std;
const int N = 55;
char s[N];
bool check(int x) {
  if (x <= 3) return x > 1;
  if (x % 2 == 0 || x % 3 == 0) return 0;
  for (int i = 5; i <= sqrt(x); i += 6) {
    if (x % i == 0 || x % (i + 2) == 0) return 0;
  }
  return 1;
}
int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int n, flag = 0;
    scanf("%d", &n);
    scanf("%s", s + 1);
    for (int i = 1; s[i]; i++) {
      int p = s[i] - '0';
      if (!check(p)) {
        printf("%d\n%d\n", 1, p);
        flag = 1;
        break;
      }
    }
    if (flag) continue;
    for (int i = 1; s[i]; i++) {
      for (int j = i + 1; s[j]; j++) {
        int p = (s[i] - '0') * 10 + s[j] - '0';
        if (!check(p)) {
          printf("%d\n%d\n", 2, p);
          flag = 1;
          break;
        }
      }
      if (flag) break;
    }
  }
  return 0;
}
