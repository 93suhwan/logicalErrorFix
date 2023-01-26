#include <bits/stdc++.h>
using namespace std;
const long long ll_INF = 0x3f3f3f3f3f3f3f3f;
const int int_INF = 0x3f3f3f3f;
const int MX = 200010;
long long _r() {
  long long x = 0, f = 1;
  char c = getchar();
  while (c > '9' || c < '0') {
    if (c == '-') f = -1;
    c = getchar();
  }
  while (c >= '0' && c <= '9')
    x = (x << 3) + (x << 1) + (c ^ 48), c = getchar();
  return f == -1 ? -x : x;
}
int n, m, k;
int a, b, c;
void Init() { a = _r(), b = _r(), c = _r(), k = _r(); }
void solve() {
  int mx = (a - 1) + (b - 1) + (c - 1);
  if (k > mx) {
    printf("NO\n");
    return;
  }
  if (k == mx) {
    printf("YES\n");
    return;
  }
  if (b < c) ((b) ^= (c) ^= (b) ^= (c));
  if (a < b) ((a) ^= (b) ^= (a) ^= (b));
  if (b < c) ((b) ^= (c) ^= (b) ^= (c));
  int mn = 0, last = b + c;
  if (a - 1 > last) {
    mn = a - last - 1;
  }
  if (k >= mn && k <= mx) {
    printf("YES\n");
  } else {
    printf("NO\n");
  }
}
int main() {
  int t = _r();
  while (t--) {
    Init();
    solve();
  }
  return 0;
}
