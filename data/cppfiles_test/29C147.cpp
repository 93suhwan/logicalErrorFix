#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int t;
  cin >> t;
  while (t-- > 0) {
    long long x = 0ll, y = 0ll;
    int n;
    cin >> n;
    std::vector<int> v(n + 1);
    ;
    for (int i = 1; i <= n; i++) cin >> v[i];
    ;
    for (int i = 1; i <= n; i++) {
      if (v[i] == 0)
        y++;
      else if (v[i] == 1)
        x++;
    }
    long long ans = x * pow(2, y);
    cout << ans << "\n";
  }
}
