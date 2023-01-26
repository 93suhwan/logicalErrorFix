#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    string a, b;
    cin >> a >> b;
    int ans = 0;
    for (int i = 0; i < n; i++) {
      if (b[i] != '1') {
        continue;
      }
      if (b[i] == '1' and a[i] == '0') {
        ans++;
        continue;
      }
      if (i - 1 >= 0 and a[i - 1] == '1') {
        ans++;
        a[i - 1] = '.';
        continue;
      }
      if (i + 1 < n and a[i + 1] == '1') {
        ans++;
        a[i + 1] = '.';
        continue;
      }
    }
    cout << ans << "\n";
  }
}
