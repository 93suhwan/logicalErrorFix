#include <bits/stdc++.h>
using namespace std;
void dg(long long x) {
  cout << " # "
       << " : " << (x) << '\n';
}
const double pi = acos(-1);
const long long mod = 1000000007;
int t, n;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ;
  cin >> t;
  while (t--) {
    string s;
    cin >> n >> s;
    bool b = 0;
    for (int i = 0; i < n - 1; ++i) {
      if (s[i] != s[i + 1]) {
        cout << i + 1 << ' ' << i + 2 << '\n';
        b = 1;
        break;
      }
    }
    if (!b) cout << -1 << ' ' << -1 << '\n';
  }
  return 0;
}
