#include <bits/stdc++.h>
using namespace std;
int n, T;
bool check(string a, string b) {
  int ib = 0;
  for (int i = 0; i <= a.size() - 1; i++) {
    ib = 0;
    int ia = i;
    if (a[ia] == b[ib]) {
      while (a[ia] == b[ib] && ia < a.size() && ib < b.size()) {
        ia++;
        ib++;
      }
      if (ib == b.size()) return true;
      for (int z = ia - 2; z >= 0; z--) {
        if (a[z] != b[ib])
          break;
        else
          ib++;
        if (ib == b.size()) return true;
      }
    }
  }
  return false;
}
int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> T;
  while (T-- > 0) {
    string s, tmp;
    cin >> s;
    cin >> tmp;
    if (check(s, tmp))
      cout << "YES\n";
    else
      cout << "NO\n";
  }
}
