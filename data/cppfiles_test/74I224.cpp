#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
int read() {
  int s = 0, w = 1;
  char c = getchar();
  for (; !isdigit(c); c = getchar()) {
    if (c == '-') w = -1;
  }
  for (; isdigit(c); c = getchar()) {
    s = (s << 3) + (s << 1) + (c ^ 48);
  }
  return (w == 1 ? s : -s);
}
int main() {
  int t = read();
  while (t--) {
    int a = read(), b = read();
    if (a > b) swap(a, b);
    int n = a + b;
    if (n % 2 == 1) {
      int c = n / 2, d = n - c;
      if (c == a && d == b) {
        cout << "0";
        for (int i = 1; i <= n; i++) cout << " " << i;
        cout << endl;
      } else {
        int tt = c - a;
        cout << tt;
        for (int i = tt + 1; i <= n - tt; i++) cout << " " << i;
        cout << endl;
      }
    } else {
      if (a == n / 2) {
        cout << "0";
        for (int i = 2; i <= n; i += 2) cout << " " << i;
        cout << endl;
      } else {
        int c = n / 2;
        int d = c - a;
        cout << d;
        for (int i = d + 2; i <= n - d; i += 2) cout << " " << i;
        cout << endl;
      }
    }
  }
  return 0;
}
