#include <bits/stdc++.h>
using namespace std;
void solve() {
  long long n, i, sum = 0, lenS;
  string s;
  cin >> s;
  lenS = s.length();
  for (i = 0; i < lenS; i++) {
    if (i == lenS - 1 && s[i] == '0') sum++;
    if (s[i] == s[i + 1])
      continue;
    else if (s[i] == '0' && s[i + 1] == '1')
      sum++;
    else
      sum += 0;
  }
  if (sum >= 2) {
    cout << 2 << endl;
    return;
  } else
    cout << sum << endl;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int TC;
  cin >> TC;
  while (TC--) solve();
}
