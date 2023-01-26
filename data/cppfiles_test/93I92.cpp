#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:102400000,102400000")
using namespace std;
int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int a, b;
    scanf("%d%d", &a, &b);
    int ans = 0;
    ans += a;
    int flag1 = 0;
    int flag = 0;
    int c = a - 1;
    for (int i = 31; i >= 0; i--) {
      if (c >> i & 1) {
        for (int j = 0; j <= i; j++) {
          flag += 1 << j;
        }
        break;
      }
    }
    if (a >= 2) {
      int c2 = a - 2;
      for (int i = 31; i >= 0; i--) {
        if (c2 >> i & 1) {
          for (int j = 0; j <= i; j++) {
            flag1 += 1 << j;
          }
          break;
        }
      }
    }
    if (flag < b) {
      ans++;
    } else if (b == 0 && flag1 != c) {
      ans++;
    } else if (c != flag1 && flag > b) {
      ans++;
    }
    if (a == 1 && b == 1) {
      ans = 3;
    }
    cout << ans << "\n";
  }
}
