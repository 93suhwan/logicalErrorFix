#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
  int t, n, i;
  char c;
  string str;
  bool odd, even;
  cin >> t;
  while (t--) {
    cin >> n >> c >> str;
    str = ' ' + str;
    odd = even = true;
    for (i = 1; i <= n && (odd || even); i++) {
      if ((i & 1) && odd && str[i] != c) odd = false;
      if (!(i & 1) && even && str[i] != c) even = false;
    }
    if (!odd && !even)
      cout << 2 << endl << 2 << ' ' << n - 1 << endl;
    else if (!odd)
      cout << 1 << endl << 2 << endl;
    else if (!even)
      cout << 1 << endl << n - 1 << endl;
    else
      cout << 0 << endl;
  }
  return 0;
}
