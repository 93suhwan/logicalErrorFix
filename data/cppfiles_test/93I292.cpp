#include <bits/stdc++.h>
using namespace std;
using LL = long long;
int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int T;
  vector<int> f(3e5 + 5);
  f[0] = 0;
  for (int i = 1; i < 3e5 + 5; i++) f[i] = f[i - 1] ^ i;
  for (cin >> T; T; T--) {
    int a, b;
    cin >> a >> b;
    int ans = a;
    if (f[a - 1] == 0) {
      if (a == b)
        ans += 2;
      else
        ans++;
    } else {
      if (f[a - 1] == b)
        ans = ans;
      else if ((f[a - 1] ^ b) != a)
        ans++;
      else
        ans += 2;
    }
    cout << ans << '\n';
  }
  return 0;
}
