#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target( \
    "sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
using namespace std;
const long long N = 3005;
const long long M = 70;
const long long SZ = 450;
const long long mod = 1e9 + 7;
const long long inf = 0x3f3f3f3f3f3f3f3f;
long long read() {
  long long x = 0, f = 1;
  char ch = getchar();
  while (ch > '9' || ch < '0') {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') {
    x = x * 10 + ch - '0';
    ch = getchar();
  }
  return x * f;
}
void write(long long x) {
  if (x < 0) {
    putchar('-');
    x = -x;
  }
  if (x >= 10) write(x / 10);
  putchar(x % 10 + '0');
}
long long ksm(long long x, long long y = mod - 2, long long z = mod) {
  long long ret = 1;
  while (y) {
    if (y & 1) ret = (ret * x) % z;
    x = (x * x) % z;
    y >>= 1;
  }
  return ret;
}
long long n, A, B, x, y;
string a, b;
bool flag = 0;
void DOIT() {
  n = read();
  A = read();
  B = read();
  A++;
  B++;
  cin >> a >> b;
  flag = 0;
  if (A > B) {
    if (a == "left")
      A--;
    else
      A++;
    if (A == 0) A = 2;
    if (A == n + 1) A = n - 1;
    swap(A, B);
    swap(a, b);
  }
  if (A == 1 && B == 1) {
    cout << n - 1 << "\n";
    return;
  }
  if (A == 1 && B == 2) {
    cout << 0 << "\n";
    return;
  }
  if (A < B) {
    if (a == "right" && b == "left") {
      flag = (B - A + 1) % 2;
      x = (A + B + 1) / 2 - 1;
      y = n - x - 1;
    }
    if (a == "left" && b == "left") {
      B -= A - 1;
      A = 1;
      if (A == 1 && B == 1) {
        cout << n - 1 << "\n";
        return;
      }
      if (A == 1 && B == 2) {
        cout << 0 << "\n";
        return;
      }
      flag = (B - A + 1) % 2;
      x = (A + B + 1) / 2 - 1;
      y = n - x - 1;
    }
    if (a == "right" && b == "right") {
      A += n - B;
      B = n;
      if (A == n) {
        cout << 0 << "\n";
        return;
      }
      if (A == n - 1) {
        cout << n - 1 << "\n";
        return;
      }
      flag = (B - A + 1) % 2;
      x = (A + B + 1) / 2 - 1;
      y = n - x - 1;
    }
    if (a == "left" && b == "right") {
      long long t = max(A - 1, n - B);
      A -= t;
      if (A < 1) A = 2 - A;
      B += t;
      if (B > n) B = 2 * n - B;
      flag = (B - A + 1) % 2;
      x = (A + B + 1) / 2 - 1;
      y = n - x - 1;
    }
  } else if (A == B) {
    x = A - 1;
    if (a == "left" && b == "right") {
      flag = 0;
    }
    if (a == "left" && b == "left") {
      cout << n - 1 << "\n";
      return;
    }
    if (a == "right" && b == "right") {
      cout << 0 << "\n";
      return;
    }
    if (a == "right" && b == "left") {
      flag = 1;
    }
  }
  if (x <= y + flag)
    cout << 0 << "\n";
  else
    cout << n - 1 << "\n";
}
signed main() {
  long long JYZ;
  JYZ = read();
  while (JYZ--) DOIT();
}
