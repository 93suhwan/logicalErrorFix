#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    string a, b;
    cin >> a >> b;
    int ans = 0;
    for (int i = 0; i < n; i++) {
      if (a[i] != b[i])
        ans += 2;
      else if (a[i] == '0' && a[i + 1] == '1' && a[i + 1] == b[i + 1])
        ans += 2, i++;
      else if (a[i] == '1' && a[i + 1] == '0' && a[i + 1] == b[i + 1])
        ans += 2, i++;
      else if (a[i] == '0')
        ans += 1;
    }
    cout << ans << "\n";
  }
  return 0;
}
