#include <bits/stdc++.h>
using namespace std;
template <class T>
void read(T &x) {
  x = 0;
  int f = 0;
  char ch = getchar();
  while (ch < '0' || ch > '9') {
    f |= (ch == '-');
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') {
    x = (x << 1) + (x << 3) + (ch ^ 48);
    ch = getchar();
  }
  x = f ? -x : x;
  return;
}
int T, n;
void work() {
  read(n);
  for (int i = 1; i <= n; i++) cout << i + 2 << ' ';
  cout << endl;
}
int main() {
  read(T);
  for (int t = 1; t <= T; t++) {
    work();
  }
  return 0;
}
