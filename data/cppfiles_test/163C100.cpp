#include <bits/stdc++.h>
using namespace std;
static const int Mod = 1000000007;
int N, M, Rb, Cb, Rd, Cd, T, P;
long long GCDext(long long a, long long b, long long &x, long long &y) {
  if (b == 0) {
    x = 1;
    y = 0;
    return a;
  } else {
    long long p = a / b;
    long long b2 = a % b;
    long long a2 = b;
    long long d = GCDext(a2, b2, x, y);
    long long x2 = x;
    x = y;
    y = x2 - p * x;
    return d;
  }
}
long long invert(long long v, long long p) {
  long long x, y;
  GCDext(v, p, x, y);
  while (x < 0) x += p;
  return x;
}
bool used[410000];
int main() {
  cin >> T;
  while (T--) {
    cin >> N >> M >> Rb >> Cb >> Rd >> Cd >> P;
    int len = 4 * (N - 1) * (M - 1);
    int r = Rb, c = Cb;
    int dr = 1, dc = 1;
    for (int i = 0; i < len; i++) {
      used[i] = false;
      if (r == Rd || c == Cd) used[i] = true;
      if (r == N && dr == 1) dr = -1;
      if (r == 1 && dr == -1) dr = 1;
      if (c == M && dc == 1) dc = -1;
      if (c == 1 && dc == -1) dc = 1;
      r += dr;
      c += dc;
    }
    long long Un = 0, Ud = 1;
    long long Vn = 1, Vd = 1;
    for (int i = len - 1; i >= 0; i--) {
      if (used[i]) {
        Un = (100 - P) * ((Ud + Un) % Mod) % Mod;
        Ud = 100 * Ud % Mod;
        Vn = (100 - P) * Vn % Mod;
        Vd = 100 * Vd % Mod;
      } else {
        Un = (Un + Ud) % Mod;
      }
    }
    Vn = (Vd - Vn + Mod) % Mod;
    long long An = Un * Vd % Mod;
    long long Ad = Ud * Vn % Mod;
    cout << (An * invert(Ad, Mod) % Mod) << "\n";
  }
  return 0;
}
