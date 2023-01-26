#include <bits/stdc++.h>
using namespace std;
template <class T>
bool chkmax(T& a, const T& b) {
  return a < b ? a = b, 1 : 0;
}
int read() {
  int num = 0, f = 1;
  char ch = getchar();
  while (ch < '0' || ch > '9') {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') {
    num *= 10;
    num += ch - '0';
    ch = getchar();
  }
  return num * f;
}
long long read1() {
  long long num = 0, f = 1;
  char ch = getchar();
  while (ch < '0' || ch > '9') {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') {
    num *= 10;
    num += ch - '0';
    ch = getchar();
  }
  return num * f;
}
int idx(char x) { return x - 'a'; }
int a[1000010];
int ans[4000010];
long long n, m;
int t, tt;
int main() {
  t = read();
  while (t--) {
    n = read();
    for (int i = 1; i <= n; i++) {
      a[i] = read();
    }
    int tot = 0;
    bool flag = true;
    int cnt = 0;
    for (int k = n; k > 1; k -= 2) {
      int x = 1;
      while (a[x] != k) x++;
      int y = 1;
      while (a[y] != k - 1) y++;
      if ((y & 1) || (x % 2 == 0)) {
        flag = false;
        break;
      }
      reverse(a + 1, a + x + 1);
      ans[++tot] = x;
      if (y < x) {
        tt = x;
        x = tt + 1 - x;
        y = tt + 1 - y;
      }
      reverse(a + 1, a + y);
      ans[++tot] = y - 1;
      reverse(a + 1, a + y + 2);
      ans[++tot] = y + 1;
      reverse(a + 1, a + 4);
      ans[++tot] = 3;
      reverse(a + 1, a + k + 1);
      ans[++tot] = k;
    }
    if (a[1] != 1 || flag == false)
      cout << -1 << endl;
    else {
      cout << tot << endl;
      for (int i = 1; i <= tot; i++) cout << ans[i] << ' ';
      if (tot || cnt) cout << endl;
    }
  }
  return 0;
}
