#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ;
  int t;
  cin >> t;
  while (t--) {
    string s;
    cin >> s;
    int c = 0, f1 = 0, f2 = 0;
    for (int i = 0; i < s.size() - 1; i++) {
      if (s[i] == '0' && s[i + 1] == '1') c++;
    }
    if (s[s.size() - 1] == '0') c++;
    if (c > 2)
      cout << 2 << '\n';
    else
      cout << c << '\n';
  }
}
