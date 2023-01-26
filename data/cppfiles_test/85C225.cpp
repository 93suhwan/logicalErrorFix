#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
const ll MOD = 1e+9 + 7;
void MAIN() {
  string s;
  cin >> s;
  char last = s[0];
  int ans = 0;
  if (s[0] == '0') ans++;
  for (int i = 1; i < s.size(); i++) {
    if (s[i] == last)
      continue;
    else {
      last = s[i];
      if (s[i] == '0') ans++;
    }
  }
  cout << min(ans, 2) << '\n';
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  cout << fixed;
  cout << setprecision(10);
  int t;
  cin >> t;
  while (t--) MAIN();
}
