#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t;
  cin >> t;
  for (int q = 0; q < t; ++q) {
    long long s, n, k;
    cin >> s >> n >> k;
    if (k == 1) {
      if (s >= n * 2) {
        cout << "NO" << endl;
      } else {
        cout << "YES" << endl;
      }
      continue;
    }
    if (s >= ((n + k - 2) / (k - 1) - 1) * k + n) {
      cout << "NO" << endl;
    } else {
      cout << "YES" << endl;
    }
  }
  return 0;
}
