#include <bits/stdc++.h>
using namespace std;
int main() {
  cin.tie(0);
  cin.sync_with_stdio(0);
  cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n, ans = 0;
    string a, b;
    cin >> n >> a >> b;
    for (int i = 0; i < n; i++)
      if (b[i] == '1') {
        if (a[i] == '0')
          ans++;
        else if (i > 0 && a[i - 1] == '1')
          ans++;
        else if (i < n - 1 && a[i + 1] == '1') {
          ans++;
          a[i + 1] = '0';
        }
      }
    cout << ans << "\n";
  }
  return 0;
}
