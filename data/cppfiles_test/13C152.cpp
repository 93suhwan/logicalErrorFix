#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int contB = 0, cont = 0;
    string s;
    cin >> s;
    for (int i = 0; i < s.size(); ++i) {
      if (s[i] == 'B')
        contB++;
      else
        cont++;
    }
    if (cont == contB)
      cout << "YES"
           << "\n";
    else
      cout << "NO"
           << "\n";
  }
  return 0;
}
