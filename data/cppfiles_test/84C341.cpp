#include <bits/stdc++.h>
using ll = long long;
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t = 1;
  cin >> t;
  while (t--) {
    int n, s;
    cin >> n >> s;
    int ans = 0;
    if (n % 2) {
      int m = (n + 1) / 2;
      ans = s / m;
    } else {
      int m = n / 2 + 1;
      ans = s / m;
    }
    cout << ans << "\n";
  }
}
