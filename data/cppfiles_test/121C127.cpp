#include <bits/stdc++.h>
using ll = long long;
using namespace std;
using pii = pair<ll, ll>;
ll mod = 998244353;
int get_p2(int n) {
  int i = 0;
  while ((1 << i) <= n) i++;
  return i - 1;
}
int main() {
  ios_base::sync_with_stdio(0);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    string a, b;
    cin >> a >> b;
    int need0 = 0, need1 = 0, nneed0 = 0, nneed1 = 0;
    for (int i = 0; i < n; i++) {
      if (a[i] != b[i]) {
        if (a[i] == '0')
          need0++;
        else
          need1++;
      } else {
        if (a[i] == '0')
          nneed0++;
        else
          nneed1++;
      }
    }
    int ans = -1;
    if (nneed1 - nneed0 == 1) ans = nneed1 + nneed0;
    if (need0 == need1)
      ans = (ans < 0 ? need0 + need1 : min(ans, need0 + need1));
    cout << ans << '\n';
  }
  cout.flush();
}
