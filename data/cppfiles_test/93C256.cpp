#include <bits/stdc++.h>
using namespace std;
int t, a, b, sum[300001];
int main() {
  for (int i = 1; i <= 300000; i++) sum[i] = sum[i - 1] ^ i;
  cin >> t;
  while (t--) {
    cin >> a >> b;
    int x = sum[a - 1];
    if (x == b) {
      cout << a << "\n";
    } else if ((x ^ b) != a) {
      cout << a + 1 << "\n";
    } else {
      cout << a + 2 << "\n";
    }
  }
}
