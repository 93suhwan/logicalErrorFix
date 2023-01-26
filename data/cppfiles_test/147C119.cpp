#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  long long int t;
  cin >> t;
  while (t-- > 0) {
    string s;
    cin >> s;
    int cn = 0;
    for (int i = 0; i < s.length(); i++) {
      if (s[i] == 'N') cn++;
      if (cn > 1) break;
    }
    if (cn == 1) {
      cout << "NO\n";
    } else {
      cout << "YES\n";
    }
  }
  return 0;
}
