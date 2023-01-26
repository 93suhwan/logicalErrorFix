#include <bits/stdc++.h>
using namespace std;
const int N = 105;
int n, m, k;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int _;
  cin >> _;
  while (_--) {
    cin >> n >> m >> k;
    m >>= 1;
    if (n * m < k) {
      cout << "NO\n";
      continue;
    }
    if (n & 1) {
      --n;
      k -= m;
    }
    if (k < 0 || k & 1) {
      cout << "NO\n";
      continue;
    }
    cout << "YES\n";
  }
  return 0;
}
