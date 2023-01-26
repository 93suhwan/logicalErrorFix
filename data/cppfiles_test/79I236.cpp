#include <bits/stdc++.h>
using namespace std;
int T, n;
char a[55];
int main() {
  cin >> T;
  while (T--) {
    int s[55];
    memset(s, 0, sizeof(s));
    cin >> n;
    scanf("%s", a + 1);
    bool f = 0;
    for (int i = 1; i <= n; i++) {
      int t = a[i] - '0';
      s[t]++;
      if (t != 2 && t != 3 && t != 5 && t != 7) {
        f = 1;
        puts("1");
        cout << t << "\n";
        break;
      }
    }
    if (f) continue;
    for (int i = 1; i <= n; i++) {
      int t = a[i] - '0';
      if ((t == 2 || t == 5) && i != 1) {
        f = 1;
        puts("2");
        cout << a[1] - '0' << t << "\n";
        break;
      }
    }
    if (f) continue;
    for (int i = 1; i <= n; i++) {
      int t = a[i] - '0';
      if (s[t] > 1) {
        f = 1;
        puts("2");
        cout << t << t << "\n";
        break;
      }
    }
    if (f) continue;
    memset(s, 0, sizeof(s));
    for (int i = 1; i <= n; i++) {
      int t = a[i] - '0';
      s[t]++;
      if (t == 7) {
        if (s[2]) {
          f = 1;
          puts("2");
          cout << "27"
               << "\n";
          break;
        }
      }
    }
    if (f) continue;
    cout << n << "\n";
    for (int i = 1; i <= n; i++) {
      cout << a[i] - '0';
    }
    cout << "\n";
  }
}
