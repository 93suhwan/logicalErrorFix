#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, ans;
    cin >> n;
    ans = floor((n + 1) / 10);
    cout << ans << "\n";
  }
  return 0;
}
