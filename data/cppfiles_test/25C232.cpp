#include <bits/stdc++.h>
using namespace std;
int n, T;
string check(string a, string b) {
  string tmp = "";
  for (int l = 0; l <= a.size() - 1; l++) {
    tmp = "";
    for (int END = l; END < a.size() && END - l + 1 <= b.size(); END++) {
      tmp = a.substr(l, END - l + 1);
      if (END < (b.size() - tmp.size())) continue;
      string zz = "";
      zz = a.substr(END - (b.size() - tmp.size()), (b.size() - tmp.size()));
      reverse(zz.begin(), zz.end());
      if (tmp + zz == b) return "YES\n";
    }
  }
  return "NO\n";
}
int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> T;
  while (T-- > 0) {
    string a, b;
    cin >> a;
    cin >> b;
    cout << check(a, b);
  }
}
