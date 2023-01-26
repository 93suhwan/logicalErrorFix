#include <bits/stdc++.h>
using namespace std;
int main() {
  int t, n, a[100002], b, c, s, tmp;
  cin >> t;
  while (t--) {
    cin >> n;
    b = 0;
    s = 0;
    for (int i = 0; i < n; ++i) {
      cin >> tmp;
      a[i] = tmp % 2;
      b += a[i];
    }
    c = n - b;
    if (abs(b - c) >= 2)
      s = -1;
    else {
      if (b > c) {
        int flag = 0;
        for (int i = 0; i < n; i++) {
          if (a[i] == 1) {
            s += abs(i - flag);
            flag += 2;
          }
        }
      } else if (b < c) {
        int flag = 1;
        for (int i = 0; i < n; i++) {
          if (a[i] == 1) {
            s += abs(i - flag);
            flag += 2;
          }
        }
      } else if (b == c) {
        int flag = 1, s1 = 0, s2 = 0;
        for (int i = 0; i < n; i++) {
          if (a[i] == 1) {
            s1 += abs(i - flag);
            flag += 2;
          }
        }
        flag = 0;
        for (int i = 0; i < n; i++) {
          if (a[i] == 1) {
            s2 += abs(i - flag);
            flag += 2;
          }
        }
        s = min(s1, s2);
      }
    }
    cout << s << endl;
  }
  return 0;
}
