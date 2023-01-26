#include <bits/stdc++.h>
using namespace std;
int n;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int TT;
  cin >> TT;
  for (int tt = 1; tt <= TT; tt++) {
    cin >> n;
    bool even = 1;
    vector<long long> ad, bd;
    while (n) {
      if (even) {
        ad.push_back(n % 10);
      } else {
        bd.push_back(n % 10);
      }
      n /= 10, even ^= 1;
    }
    int ten = 1, a = 0, b = 0;
    for (auto i : ad) a += ten * i, ten *= 10;
    ten = 1;
    for (auto i : bd) b += ten * i, ten *= 10;
    cout << (a + 1) * (b + 1) - 2 << "\n";
  }
  return 0;
}
