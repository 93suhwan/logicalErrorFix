#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    long long n;
    cin >> n;
    long long coin2 = n / 3;
    long long coin1 = n - 2 * coin2;
    if (abs(coin1 - coin2) > 1) {
      int x = abs(coin1 - coin2);
      coin1 -= x;
      coin2 += x / 2;
    }
    cout << coin1 << " " << coin2 << endl;
  }
  return 0;
}
