#include <bits/stdc++.h>
using namespace std;
void solve() {
  long long int t = 1;
  cin >> t;
  while (t--) {
    long long int n, i;
    cin >> n;
    string s;
    cin >> s;
    long long int cnt0 = 0;
    for (i = 0; i < n; i++) {
      if (s[i] == '0') {
        cnt0++;
      }
    }
    if (cnt0 >= 1) {
      long long int idx = 0;
      for (i = 0; i < n; i++) {
        if (s[i] == '0') {
          idx = i;
          break;
        }
      }
      if (idx <= n / 2) {
        cout << idx + 1 << " " << n << " " << idx + 2 << " " << n << "\n";
      } else {
        cout << 1 << " " << idx + 1 << " " << 1 << " " << idx << "\n";
      }
    } else {
      cout << 1 << " " << 2 * (n / 2) + 1 << " " << 1 << " " << n / 2 + 1
           << "\n";
    }
  }
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  solve();
  cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs"
       << "\n";
  return 0;
}
