#include <bits/stdc++.h>
using namespace std;
using int64 = long long;
void DBG() { cerr << "]" << '\n'; }
template <class H, class... T>
void DBG(H h, T... t) {
  cerr << h;
  if (sizeof...(t)) cerr << ", ";
  DBG(t...);
}
int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    string s;
    cin >> s;
    int n = s.size();
    auto count = [&n](const string &s) {
      int d = 0;
      for (int i = 0; i < n - 1; i++) {
        if (s[i] == 'a' && s[i + 1] == 'b')
          d++;
        else if (s[i] == 'b' && s[i + 1] == 'a')
          d--;
      }
      return d;
    };
    while (1) {
      int d = count(s);
      if (count(s) == 0) break;
      int vv = abs(d);
      for (int i = 0; i < n - 1; i++) {
        char tmp = s[i];
        if (s[i] == 'a')
          s[i] = 'b';
        else
          s[i] = 'a';
        int vvv = abs(count(s));
        if (vvv < vv) {
          break;
        }
        s[i] = tmp;
      }
    }
    cout << s << "\n";
  }
  return 0;
}
