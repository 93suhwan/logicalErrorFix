#include <bits/stdc++.h>
using namespace std;
const int N = 200010;
int t, n, first, last;
char c;
int main() {
  cin >> t;
  while (t--) {
    first = 1;
    cin >> n;
    for (int i = 1; i <= n; i++) {
      cin >> c;
      if (first) {
        if (c == 'B') {
          first = 0;
          if (i % 2)
            for (int j = 1; j <= i; j++) putchar(j % 2 ? 'B' : 'R');
          else
            for (int j = 1; j <= i; j++) putchar(j % 2 ? 'R' : 'B');
          last = 0;
        }
        if (c == 'R') {
          first = 0;
          if (i % 2)
            for (int j = 1; j <= i; j++) putchar(j % 2 ? 'R' : 'B');
          else
            for (int j = 1; j <= i; j++) putchar(j % 2 ? 'B' : 'R');
          last = 1;
        }
      } else
        switch (c) {
          case 'B':
            putchar('B');
            last = 0;
            break;
          case 'R':
            putchar('R');
            last = 1;
            break;
          default:
            putchar(last ? 'B' : 'R');
            last = !last;
        }
    }
    if (first)
      for (int i = 1; i <= n; i++) putchar(i % 2 ? 'B' : 'R');
    cout << endl;
  }
  return 0;
}
