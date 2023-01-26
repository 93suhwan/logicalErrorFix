#include <bits/stdc++.h>
using namespace std;
const long long mod = 1e9 + 7;
long long n, m, mi, ma;
void solve() {
  cin >> n;
  string s;
  cin >> s;
  ma = 0;
  long long k1 = 0, k2 = 0;
  char c = 'a';
  string s1;
  for (int i = n - 1; i >= 0; i--) {
    if (s[i] == '1' || s[i] == '4' || s[i] == '6' || s[i] == '8' ||
        s[i] == '9') {
      cout << 1 << "\n" << s[i] << "\n";
      return;
    }
    if ((s[i] == '2' || s[i] == '5') && (i != 0)) {
      ma = n - 2;
      c = s[i];
    }
    if ((s[i] == '2' || s[i] == '5') && k1) {
      if (s[i] == '2')
        s1 = "27";
      else
        s1 = "57";
      ma = n - 2;
    }
    if (s[i] == '7') k1++;
    if (s[i] == '3') k2++;
  }
  if (max(k1, k2) > 1) {
    cout << 2 << "\n";
    if (k1 > k2)
      cout << "77\n";
    else
      cout << "33\n";
    return;
  }
  cout << n - ma << "\n";
  if (ma == 0) {
    cout << s << "\n";
    return;
  }
  if (c != 'a') {
    cout << s[0] << c << "\n";
    return;
  }
  cout << s1 << "\n";
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t = 1;
  cin >> t;
  while (t--) solve();
  return 0;
}
