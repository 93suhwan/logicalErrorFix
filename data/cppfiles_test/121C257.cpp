#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1e9 + 7;
const long long inf = 4e18;
string alpha = "abcdefghijklmnopqrstuvwxyz";
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  long long size;
  cin >> size;
  while (size--) {
    long long siz;
    cin >> siz;
    string a, b;
    cin >> a >> b;
    long long is11 = 0, z1 = 0, z2 = 0, swaps = 0;
    for (long long i = 0; i < siz; i++) {
      if (a[i] != b[i]) {
        swaps++;
      }
      if (a[i] == '1' and b[i] == '1') {
        is11 = 1;
      }
      if (a[i] == '0') {
        z1++;
      }
      if (b[i] == '0') {
        z2++;
      }
    }
    if (z1 != z2 and z2 != siz - z1 - 1) {
      cout << -1 << endl;
      continue;
    } else if (z2 == z1 and siz - z1 - 1 == z2) {
      cout << min((swaps + 1) / 2 * 2,
                  ((is11 ? siz - swaps - 1 : siz - swaps + 1) + 1) / 2 * 2 + 1)
           << endl;
    } else if (z2 == z1) {
      cout << (swaps + 1) / 2 * 2 << endl;
    } else {
      if (is11) {
        swaps = siz - swaps - 1;
      } else {
        swaps = siz - swaps + 1;
      }
      cout << (swaps + 1) / 2 * 2 + 1 << endl;
    }
  }
}
