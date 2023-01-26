#include <bits/stdc++.h>
using namespace std;
inline int read() {
  char ch = getchar();
  int w = 1, c = 0;
  for (; !isdigit(ch); ch = getchar())
    if (ch == '-') w = -1;
  for (; isdigit(ch); ch = getchar()) c = (c << 1) + (c << 3) + (ch ^ 48);
  return w * c;
}
signed main() {
  int _ = read();
  while (_--) {
    int a = read();
    int b = a / 3, c = b, d = b;
    if (a % 3 == 1)
      c++;
    else if (a % 3 == 2)
      d++;
    cout << c << " " << d << endl;
  }
  return 0;
}
