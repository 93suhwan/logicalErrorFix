#include <bits/stdc++.h>
using namespace std;
long long mod = 1e9 + 7;
void solve();
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long t;
  cin >> t;
  while (t--) {
    solve();
    cout << "\n";
  }
}
void solve() {
  long long a, b, c, d;
  cin >> a >> b >> c >> d;
  long long ans1 = a * (long long)(pow(10, b) + 0.5);
  long long ans2 = c * (long long)(pow(10, d) + 0.5);
  if (ans1 > ans2) {
    cout << ">";
  } else if (ans1 < ans2) {
    cout << "<";
  } else {
    cout << "=";
  }
}
