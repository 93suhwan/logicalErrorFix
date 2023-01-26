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
    long long swaps = 0;
    for (long long i = 0; i < siz; i++) {
      if (a[i] != b[i]) {
        swaps++;
      }
    }
    long long z1 = 0, z2 = 0;
    for (long long i = 0; i < siz; i++) {
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
    }
    long long ans = 0;
    long long min1 = (swaps + 1) / 2 * 2;
    long long is11 = 0;
    for (long long i = 0; i < siz; i++) {
      if (a[i] == '1' and b[i] == '1') {
        is11 = 1;
      }
    }
    if (is11) {
      swaps = siz - swaps - 1;
    } else {
      swaps = siz - swaps + 1;
    }
    long long min2 = (swaps + 1) / 2 * 2;
    if (z2 != siz - z1 - 1) {
      min2 = inf;
    } else if (z1 != z2) {
      min1 = inf;
    }
    cout << min(min1, min2 + 1) << endl;
  }
}
