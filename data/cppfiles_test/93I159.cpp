#include <bits/stdc++.h>
using namespace std;
const int N = 3e5 + 10;
int s[N];
int main() {
  int t;
  scanf("%d", &t);
  for (int i = 1; i < 300010; i++) {
    s[i] = s[i - 1] ^ i;
  }
  while (t--) {
    int a, b;
    scanf("%d%d", &a, &b);
    int ans = a;
    int flag = s[a - 1];
    if (flag == 0) {
      if (b != 0) {
        if (a == b) {
          ans += 2;
        } else {
          ans += 1;
        }
      }
    } else if (flag > b || flag < b) {
      ans++;
    }
    if (a == 1 && b == 1) {
      ans = 3;
    }
    cout << ans << "\n";
  }
}
