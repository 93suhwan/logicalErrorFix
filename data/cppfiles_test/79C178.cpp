#include <bits/stdc++.h>
using namespace std;
const int maxn = 55;
char s[maxn];
int main() {
  int t;
  cin >> t;
  bool flag = false;
  while (t--) {
    int n;
    scanf("%d", &n);
    flag = false;
    scanf("%s", s);
    for (int i = 0; i < n; i++) {
      if (s[i] == '1' || s[i] == '4' || s[i] == '6' || s[i] == '8' ||
          s[i] == '9') {
        printf("1\n%c\n", s[i]);
        flag = true;
        break;
      }
    }
    if (flag) continue;
    for (int j = 0; j <= 2; j++) {
      if (s[j] == '2') {
        for (int i = j + 1; i < n; i++) {
          if (s[i] == '2' || s[i] == '5' || s[i] == '7') {
            printf("2\n2%c\n", s[i]);
            flag = true;
            break;
          }
        }
      } else if (s[j] == '3') {
        for (int i = j + 1; i < n; i++) {
          if (s[i] == '2' || s[i] == '5' || s[i] == '3') {
            printf("2\n3%c\n", s[i]);
            flag = true;
            break;
          }
        }
      } else if (s[j] == '5') {
        for (int i = j + 1; i < n; i++) {
          if (s[i] == '2' || s[i] == '5' || s[i] == '7') {
            printf("2\n5%c\n", s[i]);
            flag = true;
            break;
          }
        }
      } else if (s[j] == '7') {
        for (int i = j + 1; i < n; i++) {
          if (s[i] == '2' || s[i] == '5' || s[i] == '7') {
            printf("2\n7%c\n", s[i]);
            flag = true;
            break;
          }
        }
      }
      if (flag) break;
    }
  }
}
