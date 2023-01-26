#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
  int t, n, i;
  char c;
  string str;
  bool flag, se;
  cin >> t;
  while (t--) {
    cin >> n >> c >> str;
    if (str[n - 2] != c)
      se = true;
    else
      se = false;
    flag = false;
    for (i = 0; i < n && !flag; i++) {
      if (i != n - 2 && str[i] != c) flag = true;
    }
    if (flag && se)
      cout << 2 << endl << n - 1 << ' ' << n << endl;
    else if (flag)
      cout << 1 << endl << n - 1 << endl;
    else if (se)
      cout << 1 << endl << n << endl;
    else
      cout << 0 << endl;
  }
  return 0;
}
