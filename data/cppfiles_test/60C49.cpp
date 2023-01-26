#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    int ans;
    for (int i = 0; i < n; ++i) {
      int c;
      cin >> c;
      if (i == 0)
        ans = c;
      else
        ans &= c;
    }
    cout << ans << '\n';
  }
}
