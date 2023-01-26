#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target( \
    "sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
using namespace std;
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
long long n, A, B, x, y;
long long ans;
string a, b;
bool flag = 0;
void DOIT() {
  n = read();
  A = read();
  B = read();
  A++;
  B++;
  x = 0;
  y = 0;
  cin >> a >> b;
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
    if (1)
      cout << n - 1 << "\n";
    else
      cout << 0 << "\n";
    return;
  }
  if (A == 1 && B == 2) {
    if (0)
      cout << n - 1 << "\n";
    else
      cout << 0 << "\n";
    return;
  }
  if (A == n) {
    if (0)
      cout << n - 1 << "\n";
    else
      cout << 0 << "\n";
    return;
  }
  if (A == n - 1) {
    if (0)
      cout << n - 1 << "\n";
    else
      cout << 0 << "\n";
    return;
  }
  if (A < B) {
    if (a == "right" && b == "left") {
      if ((A + B + 1) % 2)
        cout << n - 1 << "\n";
      else
        cout << 0 << "\n";
      return;
    }
    if (a == "left" && b == "left") {
      B -= A - 1;
      A = 1;
      if (A == 1 && B == 1) {
        if (1)
          cout << n - 1 << "\n";
        else
          cout << 0 << "\n";
        return;
      }
      if (A == 1 && B == 2) {
        if (0)
          cout << n - 1 << "\n";
        else
          cout << 0 << "\n";
        return;
      }
      {
        if ((A + B + 1) % 2)
          cout << n - 1 << "\n";
        else
          cout << 0 << "\n";
        return;
      }
    }
    if (a == "right" && b == "right") {
      A += n - B;
      B = n;
      if (A == n) {
        if (0)
          cout << n - 1 << "\n";
        else
          cout << 0 << "\n";
        return;
      }
      if (A == n - 1) {
        if (0)
          cout << n - 1 << "\n";
        else
          cout << 0 << "\n";
        return;
      }
      {
        if ((A + B + 1) % 2)
          cout << n - 1 << "\n";
        else
          cout << 0 << "\n";
        return;
      }
    }
    if (a == "left" && b == "right") {
      long long t = max(A - 1, n - B);
      A -= t;
      if (A < 1) A = 2 - A;
      B += t;
      if (B > n) B = 2 * n - B;
      if (A == 1 && B == 1) {
        if (1)
          cout << n - 1 << "\n";
        else
          cout << 0 << "\n";
        return;
      }
      if (A == 1 && B == 2) {
        if (0)
          cout << n - 1 << "\n";
        else
          cout << 0 << "\n";
        return;
      }
      if (B == n && A == n) {
        if (0)
          cout << n - 1 << "\n";
        else
          cout << 0 << "\n";
        return;
      }
      if (B == n && A == n - 1) {
        if (1)
          cout << n - 1 << "\n";
        else
          cout << 0 << "\n";
        return;
      }
      {
        if ((A + B + 1) % 2)
          cout << n - 1 << "\n";
        else
          cout << 0 << "\n";
        return;
      }
    }
  } else if (A == B) {
    x = A - 1;
    y = n - x - 1;
    if (a == "left" && b == "right") {
      if (0)
        cout << n - 1 << "\n";
      else
        cout << 0 << "\n";
      return;
    }
    if (a == "left" && b == "left") {
      if (1)
        cout << n - 1 << "\n";
      else
        cout << 0 << "\n";
      return;
    }
    if (a == "right" && b == "right") {
      if (0)
        cout << n - 1 << "\n";
      else
        cout << 0 << "\n";
      return;
    }
    if (a == "right" && b == "left") {
      if (1)
        cout << n - 1 << "\n";
      else
        cout << 0 << "\n";
      return;
    }
  }
}
signed main() {
  long long JYZ;
  JYZ = read();
  while (JYZ--) DOIT();
}
