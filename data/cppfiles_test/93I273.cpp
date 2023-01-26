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
    int flag = 0;
    for (int i = 31; i >= 0; i--) {
      if (a >> i & 1) {
        for (int j = 0; j <= i; j++) {
          flag += 1 << j;
        }
        break;
      }
    }
    if (flag < b) {
      ans++;
    }
    if (b == 0) {
      ans++;
    }
    if (a == 1 && b == 1) {
      ans = 3;
    }
    cout << ans << "\n";
  }
}
