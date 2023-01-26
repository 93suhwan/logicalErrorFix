#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5, M = 27, mod = 1e9 + 7, OO = 0x3f3f3f3f, sqr = 320;
const long long LOO = 0x3f3f3f3f3f3f3f3f;
const long double eps = 1e-8;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ;
  int t;
  cin >> t;
  while (t--) {
    string k, s;
    cin >> k >> s;
    int ans = 0;
    for (int i = 1; i < s.size(); i++)
      ans += abs(k[s[i] - 'a'] - k[s[i - 1] - 'a']);
    cout << ans << '\n';
  }
  return 0;
}
