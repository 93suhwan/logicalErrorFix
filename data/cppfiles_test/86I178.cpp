#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 9;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t, n;
  cin >> t;
  while (t--) {
    int ans = 0;
    string a, b;
    vector<char> zero, one;
    cin >> n >> a >> b;
    for (int i = 0; i < n; i++) {
      if (a[i] != b[i]) {
        ans += 2;
        if (!zero.empty()) zero.clear();
        if (!one.empty()) one.clear();
      } else if (a[i] == b[i] && a[i] == '1') {
        if (i != 0 && a[i - 1] == b[i - 1] && a[i - 1] == '0' &&
            !zero.empty()) {
          ans += 2;
          zero.pop_back();
        } else
          one.push_back('1');
      } else if (a[i] == b[i] && a[i] == '0') {
        if (i != 0 && a[i - 1] == b[i - 1] && a[i - 1] == '1' && !one.empty()) {
          ans += 2;
          one.pop_back();
        } else
          zero.push_back('0');
      }
    }
    ans += zero.size();
    cout << ans << '\n';
  }
  return 0;
}
