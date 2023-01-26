#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e6 + 7;
int T, n;
int bit[37], value[maxn];
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin >> T;
  while (T--) {
    cin >> n;
    memset(bit, 0, sizeof(bit));
    for (int i = 0; i < n; ++i) {
      cin >> value[i];
      int idx = 0, t = value[i];
      int val = 1;
      while (t >= val) {
        bit[idx] += (t & val ? 1 : 0);
        val <<= 1;
        idx++;
      }
    }
    for (int i = 1; i <= n; ++i) {
      bool flag = true;
      for (int j = 0; j < 30; ++j)
        if (bit[j] % i) {
          flag = false;
          break;
        }
      if (flag) cout << i << " ";
    }
    cout << "\n";
  }
  return 0;
}
