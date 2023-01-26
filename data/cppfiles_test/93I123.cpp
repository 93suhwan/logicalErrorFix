#include <bits/stdc++.h>
using namespace std;
int computeXOR(int n) {
  if (n % 4 == 0) return n;
  if (n % 4 == 1) return 1;
  if (n % 4 == 2) return n + 1;
  return 0;
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    int a, b;
    cin >> a >> b;
    int ans = a;
    int x = computeXOR(a - 1);
    if (b == x)
      cout << ans << endl;
    else if (a == b)
      cout << ans + 2 << endl;
    else
      cout << ans + 1 << endl;
  }
}
