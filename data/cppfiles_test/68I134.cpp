#include <bits/stdc++.h>
using namespace std;
int find(long long x) {
  for (int i = 1;; i++) {
    if (i * i < x && (i + 1) * (i + 1) >= x) {
      return i;
    }
  }
}
void solve() {
  long long x;
  cin >> x;
  int q = find(x);
  x = x - q * q;
  if (x <= q + 1)
    printf("%d %d\n", x, q + 1);
  else {
    x = x - q - 1;
    printf("%d %d\n", q + 1, q + 1 - x);
  }
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
