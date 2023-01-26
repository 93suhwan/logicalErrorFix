#include <bits/stdc++.h>
using namespace std;
const int N = 2105;
const long long mod = 998244353;
int n, T, x[N];
void solve() {
  cin >> n;
  for (int i = 1; i <= n; i++) cin >> x[i];
  vector<int> ans;
  ans.clear();
  for (int i = 1; i <= n; i++) {
    if (x[i] % 2 != i % 2) {
      cout << "-1\n";
      return;
    }
  }
  cout << (n - 1) / 2 * 5 << "\n";
  for (int i = n; i >= 2; i -= 2) {
    int posx, posy;
    for (int j = 1; j <= n; j++) {
      if (x[j] == i) posx = j;
    }
    cout << posx << " ";
    reverse(x + 1, x + posx + 1);
    for (int j = 1; j <= n; j++)
      if (x[j] == i - 1) posy = j;
    cout << posy - 1 << " " << posy + 1 << " " << 3 << " " << i << " ";
    reverse(x + 1, x + posy);
    reverse(x + 1, x + posy + 2);
    reverse(x + 1, x + 4);
    reverse(x + 1, x + i + 1);
  }
  cout << "\n";
}
signed main() {
  cin >> T;
  while (T--) solve();
  return 0;
}
