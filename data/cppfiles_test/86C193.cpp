#include <bits/stdc++.h>
using namespace std;
inline int read() {
  int x = 0, f = 1;
  char ch = getchar();
  while (!isdigit(ch)) {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (isdigit(ch)) {
    x = x * 10 + ch - 48;
    ch = getchar();
  }
  return x * f;
}
int t;
char r1[1000001];
char r2[1000001];
int typ[1000001];
int fg[1000001];
int main() {
  cin >> t;
  while (t--) {
    int n;
    n = read();
    cin >> r1 + 1;
    cin >> r2 + 1;
    for (int i = 0; i <= n + 6; i++) {
      fg[i] = 0;
      typ[i] = 0;
    }
    for (int i = 1; i <= n; i++) {
      if (r1[i] == '0' && r2[i] == '0') {
        typ[i] = 1;
      } else {
        if (r1[i] == '1' && r2[i] == '1') {
          typ[i] = 3;
        } else {
          typ[i] = 2;
        }
      }
    }
    int ans = 0;
    for (int i = 1; i <= n; i++) {
      if (typ[i] == 1) {
        if (typ[i - 1] == 3 && fg[i - 1] == 0) {
          ans += 2;
          fg[i - 1] = 1;
        } else {
          if (typ[i + 1] == 3 && fg[i + 1] == 0) {
            ans += 2;
            fg[i + 1] = 1;
          } else {
            ans++;
          }
        }
      } else {
        if (typ[i] == 2) {
          ans += 2;
        } else {
          ans += 0;
        }
      }
    }
    cout << ans << "\n";
  }
  return 0;
}
