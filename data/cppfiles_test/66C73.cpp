#include <bits/stdc++.h>
using namespace std;
int solve(int);
int main() {
  std::ios::sync_with_stdio(false);
  int t;
  cin >> t;
  while (t--) {
    int k;
    cin >> k;
    int ans = solve(k);
    cout << ans << endl;
  }
  return 0;
}
int solve(int k) {
  if (k == 1) return 1;
  int cnt = 1;
  int ele = 1;
  while (1) {
    ele++;
    if (ele % 3 != 0 && ele % 10 != 3) {
      cnt++;
      if (cnt == k) return ele;
    }
  }
}
