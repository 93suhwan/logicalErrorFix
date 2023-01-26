#include <bits/stdc++.h>
using namespace std;
template <typename T>
void chkMax(T &x, T y) {
  if (x < y) x = y;
}
template <typename T>
void chkMin(T &x, T y) {
  if (x > y) x = y;
}
template <typename T>
void inline read(T &x) {
  int f = 1;
  x = 0;
  char s = getchar();
  while (s < '0' || s > '9') {
    if (s == '-') f = -1;
    s = getchar();
  }
  while (s >= '0' && s <= '9') {
    x = (x << 1) + (x << 3) + (s ^ 48);
    s = getchar();
  }
  x *= f;
}
const int N = 3e5 + 10;
int n;
char c, s[N];
int main() {
  int T;
  cin >> T;
  while (T--) {
    cin >> n >> c;
    scanf("%s", s + 1);
    int cnt = 0, pos;
    for (int i = 1; i <= n; i++) {
      if (s[i] != c) cnt++, pos = i;
    }
    if (!cnt)
      puts("0");
    else if (cnt == 1) {
      puts("1");
      if (pos != n)
        printf("%d\n", n);
      else
        printf("%d\n", pos + 1);
    } else {
      puts("2");
      printf("%d %d\n", n, n - 1);
    }
  }
  return 0;
}
