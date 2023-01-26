#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    long long n;
    cin >> n;
    long long coin2 = n / 3;
    long long coin1 = coin2;
    if (coin2 % 3 == 0) {
      coin1 = coin1 + 1;
    } else if (coin2 == coin1 && (coin2 + 2 * coin1 == n)) {
      coin2 = coin1;
    } else {
      coin2 = coin1 + 1;
    }
    cout << coin1 << " " << coin2 << endl;
  }
  return 0;
}
