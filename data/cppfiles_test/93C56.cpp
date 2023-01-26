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
int main() {
  int T;
  cin >> T;
  while (T--) {
    int a, b;
    cin >> a >> b;
    int ans = a;
    int xorion = findXOR(a - 1);
    if (xorion == b)
      cout << ans << endl;
    else if ((xorion ^ b) == a) {
      cout << ans + 2 << endl;
    } else
      cout << ans + 1 << endl;
  }
}
