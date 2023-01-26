#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e6 + 1000;
int read() {
  int x = 0;
  char c = getchar();
  while (c < '0' || c > '9') c = getchar();
  while (c >= '0' && c <= '9') x = x * 10 + c - '0', c = getchar();
  return x;
}
int a[maxn], b[maxn];
int q(int x, int y, int z) {
  int g;
  cout << "? " << x << " " << y << " " << z << endl;
  cout.flush();
  cin >> g;
  return g;
}
int ans[maxn];
int main() {
  int T;
  cin >> T;
  while (T--) {
    int n;
    bool bx = 0;
    cin >> n;
    int c0, c1, q0, q1;
    for (int i = 1; i <= n; i += 3) {
      a[i] = q(i, i + 1, i + 2);
      if (a[i] == 0)
        c0 = i;
      else
        c1 = i;
    }
    int b0 = q(c0, c0 + 1, c1);
    int b1 = q(c0, c0 + 1, c1 + 1);
    int b2 = q(c0, c0 + 1, c1 + 2);
    if (b0 + b1 + b2 == 0) {
      ans[c0] = 0;
      ans[c0 + 1] = 0;
      q0 = c0;
      if (q(c0, c1, c1 + 1)) {
        ans[c1] = 1;
        ans[c1 + 1] = 1;
        q1 = c1;
        ans[c1 + 2] = q(c1 + 2, q0, q1);
      } else if (q(c0, c1 + 2, c1 + 1)) {
        ans[c1 + 2] = 1;
        ans[c1 + 1] = 1;
        q1 = c1 + 1;
        ans[c1] = q(c1, q0, q1);
      } else if (q(c0, c1, c1 + 2)) {
        ans[c1] = 1;
        q1 = c1;
        ans[c1 + 2] = 1;
        ans[c1 + 1] = q(c1 + 1, q0, q1);
      }
      ans[c0 + 2] = q(c0 + 2, q0, q1);
    } else {
      if (b0) q1 = c1;
      if (b1) q1 = c1 + 1;
      if (b2) q1 = c1 + 2;
      q0 = c0 + 2;
      ans[c0 + 2] = 0;
      ans[c1] = b0;
      ans[c1 + 1] = b1;
      ans[c1 + 2] = b2;
      ans[c0] = q(c0, q0, q1);
      ans[c0 + 1] = q(c0 + 1, q0, q1);
    }
    for (int i = 1; i <= n; i += 3) {
      if (i == q0 || i == q1 || i + 1 == q0 || i + 1 == q1 || i + 2 == q0 ||
          i + 2 == q1)
        continue;
      int x;
      if (a[i] == 0) {
        x = q(i, i + 1, q1);
        if (x == 0) {
          ans[i] = 0;
          ans[i + 1] = 0;
          ans[i + 2] = q(i + 2, q0, q1);
        } else {
          ans[i] = q(i, q0, q1);
          ans[i + 1] = ans[i] ^ 1;
          ans[i + 2] = 0;
        }
      } else {
        x = q(i, i + 1, q0);
        if (x == 1) {
          ans[i] = 1;
          ans[i + 1] = 1;
          ans[i + 2] = q(i + 2, q0, q1);
        } else {
          ans[i] = q(i, q0, q1);
          ans[i + 1] = ans[i] ^ 1;
          ans[i + 2] = 1;
        }
      }
    }
    int Ans = 0;
    for (int i = 1; i <= n; i++) {
      Ans += 1 - ans[i];
    }
    cout << "! " << Ans << " ";
    for (int i = 1; i <= n; i++) {
      if (ans[i] == 0) cout << i << " ";
    }
    cout << endl;
    cout.flush();
  }
}
