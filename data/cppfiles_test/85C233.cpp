#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    string s;
    cin >> s;
    int n = s.size();
    int count = 0;
    char curr = 2;
    for (int i = 0; i < n; i++) {
      if (curr != '0' and s[i] == '0') count++;
      curr = s[i];
    }
    if (count > 1)
      cout << 2 << '\n';
    else if (count == 1)
      cout << 1 << '\n';
    else if (count == 0)
      cout << 0 << '\n';
  }
}
