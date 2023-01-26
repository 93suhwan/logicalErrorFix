#include <bits/stdc++.h>
using namespace std;
const int maxn = 500005;
int read() {
  char ch = getchar();
  int x = 0, pd = 0;
  while (ch < '0' || ch > '9') pd |= ch == '-', ch = getchar();
  while ('0' <= ch && ch <= '9') x = x * 10 + (ch ^ 48), ch = getchar();
  return pd ? -x : x;
}
int n, a[maxn];
int main() {
  int T = read();
  while (T--) {
    n = read();
    int sum = 0;
    for (int i = 1; i <= n; i++) sum += a[i] = read();
    if (sum % n == 0)
      cout << 0 << endl;
    else
      cout << 1 << endl;
  }
  return 0;
}
