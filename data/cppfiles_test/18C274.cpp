#include <bits/stdc++.h>
using namespace std;
#pragma comment(linker, "/STACK:102400000,102400000")
long long mul(long long a, long long b) { return (a * b) % (1000000007); }
long long add(long long a, long long b) { return (a + b) % (1000000007); }
long long sub(long long a, long long b) {
  return ((a - b) % (1000000007) + (1000000007)) % (1000000007);
}
void upd(long long &a, long long b) {
  a = (a % (1000000007) + b % (1000000007)) % (1000000007);
}
inline int read() {
  int x = 0, f = 1;
  char ch = getchar();
  while (!isdigit(ch)) {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (isdigit(ch)) {
    x = x * 10 + ch - '0';
    ch = getchar();
  }
  return x * f;
}
long long a[(50010)];
long long b[(50010)];
int col[(50010)];
long long calc(int n) {
  long long ans = 0;
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= n; j++) {
      int x = a[i], y = b[i], xx = a[j], yy = b[j];
      bool b1 = x < xx && xx < y;
      bool b2 = x < yy && yy < y;
      ans += b2 ^ b1;
    }
  return ans;
}
int main() {
  int t = read();
  while (t--) {
    int n = read(), k = read();
    for (int i = 1; i <= k; i++) {
      a[i] = read(), b[i] = read();
      if (a[i] > b[i]) swap(a[i], b[i]);
    }
    long long ans = -1;
    for (int t = 1; t <= 2 * n; t++) {
      for (int i = 1; i <= 2 * n; i++) col[i] = 0;
      for (int i = 1; i <= k; i++) col[a[i]] = col[b[i]] = i;
      int l = 0;
      for (int i = t; i <= 2 * n; i++) {
        if (!col[i]) {
          ++l;
          if (l <= n - k)
            a[k + l] = i, col[i] = l;
          else {
            b[k + l - (n - k)] = i, col[i] = l;
          }
        }
      }
      for (int i = 1; i <= t - 1; i++) {
        if (!col[i]) {
          ++l;
          if (l <= n - k)
            a[k + l] = i, col[i] = l;
          else {
            b[k + l - (n - k)] = i, col[i] = l;
          }
        }
      }
      ans = max(ans, calc(n));
      ;
    }
    cout << ans / 2 << endl;
  }
  return 0;
}
