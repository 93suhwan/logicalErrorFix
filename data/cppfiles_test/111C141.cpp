#include <bits/stdc++.h>
using namespace std;
const int NMX = 432000, oo = 0x3C3C3C3C, Bs = 1000000007;
int q, n;
string s;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cin >> q;
  while (q--) {
    cin >> n;
    s = "";
    for (int i = 1; i <= 2 * n; i++) s += i <= n ? '(' : ')';
    for (int i = 1; i <= n; i++) {
      cout << s << '\n';
      s[n - 2 + i] = ')';
      s[n - 1 + i] = '(';
    }
  }
  return 0;
}
