#include <bits/stdc++.h>
using namespace std;
void JIZZ(string output = "") {
  cout << output;
  exit(0);
}
const long double PI = 3.14159265358979323846264338327950288;
const long double eps = 1e-10;
const long long mod = 1e9 + 7;
void solve() {
  string s, t;
  cin >> s >> t;
  for (int st = 0; st < (int)s.size(); ++st) {
    string cur;
    for (int ri = st; ri < (int)s.size(); ++ri) {
      cur += s[ri];
      if (cur == t) {
        cout << "YES" << endl;
        return;
      }
      string cc = cur;
      for (int i = ri - 1; i >= 0 && cur.size() < t.size(); --i) {
        cc += s[i];
        if (cc.size() == t.size()) {
          if (cc == t) {
            cout << "YES" << endl;
            return;
          }
          break;
        }
      }
    }
  }
  cout << "NO" << '\n';
}
int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
}
