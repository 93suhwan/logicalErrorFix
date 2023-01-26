#include <bits/stdc++.h>
using namespace std;
int main() {
  int T;
  cin >> T;
  while (T--) {
    int N, M;
    cin >> N >> M;
    M++;
    int sum = 0;
    while (1) {
      int period = 1;
      while (period <= N) period <<= 1;
      sum += M / period * period;
      M %= period;
      if (M <= N) break;
      int i = 31;
      while (i >= 0 && (N >> i) == (M >> i)) i--;
      M &= (1 << (i + 1)) - 1;
      N &= (1 << (i + 1)) - 1;
    }
    cout << sum << endl;
  }
  return 0;
}
