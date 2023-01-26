#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 9;
int n, m, f[N];
int h[N], kq;
string s, t;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int T;
  cin >> T;
  for (; T--;) {
    cin >> s;
    cin >> t;
    sort(s.begin(), s.end());
    if (t != "abc")
      cout << s << "\n";
    else {
      int a = 0, b = 0, c = 0;
      for (int i = 0; i < s.size(); i++) {
        if (s[i] == 'a') a++;
        if (s[i] == 'b') b++;
        if (s[i] == 'c') c++;
      }
      if (a && b && c) {
        for (int i = 0; i < a; i++) cout << "a";
        for (int i = 0; i < c; i++) cout << "c";
        for (int i = 0; i < b; i++) cout << "b";
        for (int i = 0; i < s.size(); i++)
          if (s[i] != 'a' && s[i] != 'b' && s[i] != 'c') cout << s[i];
        cout << "\n";
      } else {
        cout << s << "\n";
      }
    }
  }
  return 0;
}
