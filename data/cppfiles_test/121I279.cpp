#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    char temp;
    int e0 = 0, e1 = 0, o0 = 0, o1 = 0;
    scanf("%d\n", &n);
    vector<char> a(n + 1), b(n + 1);
    for (int i = 0; i < n; i++) scanf("%c", &a[i]);
    a[n] = '\0';
    scanf("%c", &temp);
    for (int i = 0; i < n; i++) scanf("%c", &b[i]);
    b[n] = '\0';
    scanf("%c", &temp);
    for (int i = 0; i < n; i++) {
      if (a[i] == b[i]) {
        if (a[i] == '1')
          e1++;
        else
          e0++;
      } else {
        if (a[i] == '1')
          o1++;
        else
          o0++;
      }
    }
    if (e0 + e1 == n) {
      printf("0\n");
      continue;
    }
    if ((e0 + e1) % 2 == 0 && (o0 + o1) % 2 == 1) {
      printf("-1\n");
      continue;
    }
    if ((e0 + e1) % 2 == 1 && (o0 + o1) % 2 == 0) {
      if (e0 - e1 <= 1 && e0 - e1 >= -1 && (e0 != 0 || e1 == 1) && e1 != 0) {
        if (o0 - o1 <= 1 && o0 - o1 >= -1 && (o0 != 0 || o1 == 1) && o1 != 0) {
          printf("%d\n", min(e0 + e1, o0 + o1));
          continue;
        } else {
          printf("%d\n", e0 + e1);
          continue;
        }
      } else if (o0 - o1 <= 1 && o0 - o1 >= -1 && (o0 != 0 || o1 == 1) &&
                 o1 != 0) {
        printf("%d\n", o0 + o1);
        continue;
      } else {
        printf("-1\n");
        continue;
      }
    } else if ((e0 + e1) % 2 == 1 && e0 - e1 <= 1 && e0 - e1 >= -1 &&
               (e0 != 0 || e1 == 1) && e1 != 0) {
      printf("%d\n", e0 + e1);
      continue;
    } else if ((o0 + o1) % 2 == 0 && o0 - o1 <= 1 && o0 - o1 >= -1 &&
               (o0 != 0 || o1 == 1) && o1 != 0) {
      printf("%d\n", o0 + o1);
      continue;
    } else {
      printf("-1\n");
      continue;
    }
  }
  return 0;
}
