#include <bits/stdc++.h>
using namespace std;
void solve() {
  long long int t = 1;
  cin >> t;
  while (t--) {
    long long int n, i;
    cin >> n;
    string s, s1;
    s.push_back('x');
    cin >> s1;
    s += s1;
    long long int flg = 0;
    for (i = 1; i < n + 1; i++) {
      if (s[i] == '0') {
        if (i <= n / 2) {
          cout << i << " " << n << " " << i + 1 << " " << n << "\n";
        } else {
          cout << 1 << " " << i << " " << 1 << " " << i - 1 << "\n";
        }
        flg = 1;
        break;
      }
    }
    if (flg == 0) {
      cout << 1 << " " << n - 1 << " " << 2 << " " << n << "\n";
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
