#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    string initial, target;
    cin >> initial;
    cin >> target;
    int change[2] = {0, 0};
    int noChange[2] = {0, 0};
    for (int i = 0; i < n; i++) {
      if (initial[i] == target[i])
        noChange[initial[i] - '0']++;
      else
        change[initial[i] - '0']++;
    }
    int ans = 1000000;
    bool possible = false;
    if (noChange[1] - noChange[0] == 1) {
      possible = true;
      ans = min(ans, noChange[0] + noChange[1]);
    }
    if (change[0] == change[1]) {
      possible = true;
      ans = min(ans, change[0] + change[1]);
    }
    if (possible)
      cout << ans << '\n';
    else
      cout << "-1\n";
  }
  return 0;
}
