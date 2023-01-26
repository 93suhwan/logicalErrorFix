#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  vector<long long> xorValue(3e5 + 1);
  xorValue[0] = 0;
  for (int i = 1; i <= 3e5; i++) {
    xorValue[i] ^= i;
  }
  int t;
  cin >> t;
  while (t--) {
    long long a, b;
    cin >> a >> b;
    long long cur = a;
    if (xorValue[a - 1] != b) {
      if ((b ^ xorValue[a - 1]) != a) {
        cur++;
      } else {
        cur += 2;
      }
    }
    cout << cur << '\n';
  }
  return 0;
}
