#include <bits/stdc++.h>
using namespace std;
inline void read(int &x) {
  x = 0;
  char c = getchar();
  for (; !isdigit(c); c = getchar())
    ;
  for (; isdigit(c); c = getchar()) x = x * 10 + (c ^ '0');
}
int T, n, m;
int main() {
  for (cin >> T; T--;) {
    read(n), read(m);
    for (int i = 1; i < m; ++i) {
      int x = pow(10, (int)log10(n - (m - i)));
      printf("%d ", x);
      n -= x;
    }
    printf("%d\n", n);
  }
  return 0;
}
