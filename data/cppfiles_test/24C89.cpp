#include <bits/stdc++.h>
using namespace std;
int calc(int n) {
  int res = 0;
  while (n > 0) {
    res += n % 10;
    n /= 10;
  }
  return res;
}
int32_t main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    cout << (n + 1) / 10 << "\n";
  }
  return 0;
}
