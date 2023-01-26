#include <bits/stdc++.h>
using namespace std;
int compute(int a) {
  if (a % 4 == 0) return a;
  if (a % 4 == 1) return 1;
  if (a % 4 == 2) return a + 1;
  return 0;
}
int main() {
  int tt;
  cin >> tt;
  while (tt--) {
    int a, b;
    cin >> a >> b;
    int ans = 0;
    ans += a;
    int p = compute(a - 1);
    if (p != b) {
      int r = p ^ b;
      if (r == a)
        ans += 2;
      else
        ans += 1;
    }
    cout << ans << "\n";
  }
  return 0;
}
