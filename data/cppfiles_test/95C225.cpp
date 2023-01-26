#include <bits/stdc++.h>
using namespace std;
char *p1, *p2, buf[100000];
int read() {
  int x;
  scanf("%d", &x);
  return x;
}
const int maxn = 105;
int a[20], b[20], ten[20];
int s, n, len;
int cal() {
  int ret = 0;
  for (int i = 0; i <= len - 1; i++) ret += a[i];
  return ret;
}
void pri() {
  int cur = 0;
  while (n != 1) {
    for (int i = cur; i <= len - 1; i++) {
      if (a[i]) {
        a[i]--;
        cout << ten[len - i - 1] << " ";
        break;
      }
      cur = i;
    }
    n--;
  }
  int ret = 0;
  for (int i = cur; i <= len - 1; i++) {
    ret += a[i] * ten[len - i - 1];
  }
  cout << ret << "\n";
}
void init() { len = 0; }
void solve() {
  init();
  s = read(), n = read();
  while (s) {
    a[len++] = s % 10;
    s /= 10;
  }
  reverse(a, a + len);
  while (cal() < n) {
    for (int i = len - 2; i >= 0; i--) {
      if (a[i]) {
        a[i]--;
        a[i + 1] += 10;
        break;
      }
    }
  }
  pri();
}
int main() {
  ten[0] = 1;
  for (int i = 1; i <= 9; i++) ten[i] = ten[i - 1] * 10;
  int _t = read();
  while (_t--) solve();
  return 0;
}
