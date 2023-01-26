#include <bits/stdc++.h>
using namespace std;
int findXOR(int n) {
  int mod = n % 4;
  if (mod == 0)
    return n;
  else if (mod == 1)
    return 1;
  else if (mod == 2)
    return n + 1;
  else if (mod == 3)
    return 0;
}
int findXOR(int l, int r) { return (findXOR(l - 1) ^ findXOR(r)); }
int main() {
  int T;
  cin >> T;
  while (T--) {
    int a, b;
    cin >> a >> b;
    int ans = a;
    if (a >= b) {
      int xorion = findXOR(1, a - 1);
      if (xorion == b) {
        cout << ans << endl;
        continue;
      } else if (xorion == 0) {
        cout << ans + 2 << endl;
      } else {
        cout << ans + 1 << endl;
      }
    } else if (a != 1 || b != 1)
      cout << ans + 1 << endl;
    else
      cout << ans + 2 << endl;
  }
}
