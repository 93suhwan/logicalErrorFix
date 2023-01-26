#include <bits/stdc++.h>
using namespace std;
long long int MOD = 998244353;
long long int mod = 1e9 + 7;
long long int inf = 2e18;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long int t;
  cin >> t;
  while (t--) {
    long long int n;
    cin >> n;
    string s;
    cin >> s;
    long long int l = -1, r = -1;
    for (long long int i = 0; i < n; i++) {
      long long int a = 0, b = 0;
      for (long long int j = i; j < n; j++) {
        if (s[j] == 'a')
          a++;
        else
          b++;
        if (a == b) {
          l = i + 1;
          r = j + 1;
          break;
        }
      }
      if (l != -1) break;
    }
    cout << l << ' ' << r << '\n';
  }
  cerr << "Time elapsed : " << 1.0 * clock() / CLOCKS_PER_SEC << " sec \n";
}
