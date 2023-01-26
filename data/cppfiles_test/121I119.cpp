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
    long long z1 = 0, z2 = 0;
    for (long long i = 0; i < siz; i++) {
      if (a[i] == '0') {
        z1++;
      }
      if (b[i] == '0') {
        z2++;
      }
    }
    if (a == b) {
      cout << 0 << endl;
    } else if (z1 != z2 and z2 != z1 - 1 and z2 != siz - z1 - 1 or z1 == 0) {
      cout << -1 << endl;
    } else {
      long long bad = 0;
      long long good = 0;
      for (long long i = 0; i < siz; i++) {
        if (a[i] == b[i]) {
          good++;
        } else {
          bad++;
        }
      }
      cout << min(bad, good) << endl;
    }
  }
}
