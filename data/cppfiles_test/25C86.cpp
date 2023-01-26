#include <bits/stdc++.h>
using namespace std;
int constexpr max_n = 1e5 + 10;
int main() {
  ios::sync_with_stdio(false), cin.tie(0);
  ;
  int t = 1;
  cin >> t;
  while (t--) {
    int o, tm;
    string s, s1, t;
    cin >> s >> s1;
    int n = s.size(), n1 = s1.size();
    bool h = false;
    for (int i = 0; i < n; i++) {
      for (int j = n - i - 1; j >= 0 && ((i + (j << 1) - n1 + 1) >= 0); j--) {
        t = "";
        o = 0;
        for (int k = i; k <= i + j; k++, o++) t += s[k];
        tm = n1 - (j + 1);
        for (int k = i + j - 1; tm >= 1; k--, o++, tm--) t += s[k];
        if (t == s1 && o == s1.size()) h = true;
      }
    }
    if (h)
      cout << "YES\n";
    else
      cout << "NO\n";
  }
}
