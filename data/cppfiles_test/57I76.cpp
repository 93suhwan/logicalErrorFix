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
int t;
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
      if (x == k && a[x - 1] == k - 1)
        continue;
      else if (x == 1) {
        if (a[2] != k - 1) {
          flag = false;
          break;
        }
        reverse(a + 1, a + k + 1);
        ans[++tot] = k;
        cnt++;
      } else {
        if (a[x - 1] != k - 1) {
          flag = false;
          break;
        }
        reverse(a + 1, a + x + 1);
        reverse(a + 1, a + k + 1);
        ans[++tot] = x;
        ans[++tot] = k;
        cnt++;
      }
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
