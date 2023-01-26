#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    int ans = 0;
    for (int i = 1; i <= n; i++) {
      char a;
      cin >> a;
      ans += a - '0' + (i != n and a != '0');
    }
    cout << ans << "\n";
  }
  return 0;
}
